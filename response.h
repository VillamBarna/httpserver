char* generate_response(char request[]);
struct Line {
    char method[1024];
    char target[1024];
    char version[1024];
};
struct Headers {
    char request[1024];
    char general[1024];
    char representation[1024];
};
struct Request {
    struct Line line;
    struct Headers headers;
};