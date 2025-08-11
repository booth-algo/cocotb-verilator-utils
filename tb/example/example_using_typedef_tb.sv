module example_using_typedef_tb #(
    parameter DATA_WIDTH    = 32
) (
    input wire                  clk,
    input wire                  res_n,

    input wire                  m2s_request,
    input wire                  m2s_request_valid,

    output logic                m2s_response,
    output logic                m2s_response_valid
);



    example_using_typedef #(
        .DATA_WIDTH     (DATA_WIDTH)
    ) dut_I (
        .clk            (clk),
        .res_n          (res_n),

        .m2s            (),
        .s2m            ()
    );


endmodule
