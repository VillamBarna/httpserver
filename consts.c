const char* request_methods[] = { "GET", "HEAD", "POST", "PUT", "DELET", "CONNECT", "OPTIONS", "TRACE", "PATCH" };
const int request_methods_size = 9;
const char* line200 = "HTTP/1.1 200 OK\r\n";
const char* line404 = "HTTP/1.1 404 Not found\r\n";
const char* content_text = "Content-Type: text/html\r\n";
const char* header_break = "\r\n";
