module example_using_typedef_tb #(
    parameter DATA_WIDTH    = 32
) (
    input wire                      clk,
    input wire                      res_n,

    input wire [DATA_WIDTH-1:0]     m2s_request,
    input wire                      m2s_request_valid,

    output logic [DATA_WIDTH-1:0]   s2m_response,
    output logic                    s2m_response_valid
);

    m2s_t m2s_struct;
    s2m_t s2m_struct;

    always_comb
    begin
        s2m_response        = s2m_struct.response;
        s2m_response_valid  = s2m_struct.response_valid;
    end

    always_ff @(posedge clk)
    begin
        if (!res_n)
        begin
            m2s_struct.request          <= '0;
            m2s_struct.request_valid    <= '0;
        end
        else
        begin
            m2s_struct.request          <= m2s_request;
            m2s_struct.request_valid    <= m2s_request_valid;
        end
    end

    example_using_typedef #(
        .DATA_WIDTH     (DATA_WIDTH)
    ) dut_I (
        .clk            (clk),
        .res_n          (res_n),

        .m2s            (m2s_struct),
        .s2m            (s2m_struct)
    );

endmodule
