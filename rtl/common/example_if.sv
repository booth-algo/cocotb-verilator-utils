interface example_if #(
    parameter DATA_WIDTH    = 32
  );

  logic [DATA_WIDTH-1:0]    request;
  logic [DATA_WIDTH-1:0]    response;
  logic                     request_valid;
  logic                     response_valid;

  modport master (
    output  request,
    output  request_valid,
    input   response,
    input   response_valid
  );

  modport slave (
    input   request,
    input   request_valid,
    output  response,
    output  response_valid
  );

endinterface
