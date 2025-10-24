module example_using_interface #(
    parameter DATA_WIDTH    = 32
) (
    input wire          clk,
    input wire          res_n,

    example_if.slave    example_i
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
        data_b                      = data_r;
        counter_b                   = counter_r;
        counter_active_b            = counter_active_r;

        example_i.response          = '0;
        example_i.response_valid    = '0;

        if (example_i.request_valid)
        begin
            data_b              = example_i.request;
            counter_b           = '0;
            counter_active_b    = '1;
        end

        if (counter_active_b)
        begin
            counter_b   = counter_r + 1'b1;
        end

        if (counter_r == 'd4)
        begin
            counter_active_b            = '0;
            example_i.response          = data_r;
            example_i.response_valid    = '1;
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

