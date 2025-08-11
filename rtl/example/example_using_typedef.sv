`include "common/example_typedef.sv"

module example_using_typedef #(
    parameter DATA_WIDTH    = 32
) (
    input wire                      clk,
    input wire                      res_n,

    input m2s_t                     m2s,
    output s2m_t                    s2m
);

    // Slave module that responds with same data 4 cycles later

    logic [DATA_WIDTH-1:0]  data_b;
    logic [DATA_WIDTH-1:0]  data_r;

    logic [2:0]             counter_b;
    logic [2:0]             counter_r;
    logic                   counter_active_b;
    logic                   counter_active_r;

    always_comb
    begin
        data_b              = data_r;
        counter_b           = counter_r;
        counter_active_b    = counter_active_r;

        if (m2s.request_valid)
        begin
            data_b              = m2s.request;
            counter_b           = '0;
            counter_active_b    = '1;
        end

        if (counter_active_b)
        begin
            counter_b   = counter_r + 1'b1;
        end

        if (counter_active_r == 'h4)
        begin
            counter_active_b    = '0;
            s2m.response        = data_r;
            s2m.response_valid  = '1;
        end
    end

    always_ff @(posedge clk)
    begin
        if (!res_n)
        begin
            data_r              <= '0;
            counter_r           <= '0;
            counter_active_r    <= '0;
        end
        else
        begin
            data_r              <= data_b;
            counter_r           <= counter_b;
            counter_active_r    <= counter_active_b;
        end
    end

endmodule
