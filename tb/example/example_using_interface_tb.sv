module example_using_interface_tb #(
    parameter DATA_WIDTH    = 32
) (
    input wire                      clk,
    input wire                      res_n,

    input wire [DATA_WIDTH-1:0]     m2s_request,
    input wire                      m2s_request_valid,

    output logic [DATA_WIDTH-1:0]   s2m_response,
    output logic                    s2m_response_valid
);

    example_if #(
        .DATA_WIDTH     (DATA_WIDTH)
    ) example_i();

    always_comb
    begin
        s2m_response        = example_i.response;
        s2m_response_valid  = example_i.response_valid;
    end

    always_ff @(posedge clk)
    begin
        if (!res_n)
        begin
            example_i.request          <= '0;
            example_i.request_valid    <= '0;
        end
        else
        begin
            example_i.request          <= m2s_request;
            example_i.request_valid    <= m2s_request_valid;
        end
    end

    example_using_interface #(
        .DATA_WIDTH     (DATA_WIDTH)
    ) dut_I (
        .clk            (clk),
        .res_n          (res_n),

        .example_i      (example_i)
    );

endmodule
