typedef struct {
    logic [31:0]    request;
    logic           request_valid;
} m2s_t;

typedef struct {
    logic [31:0]    response;
    logic           response_valid;
} s2m_t;
