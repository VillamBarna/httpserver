#include "response.h"
#include <stdlib.h>
#include "consts.h"
#include <stdbool.h>
#include <string.h>

char* generate_response(char request_text[]) {
    char* response = (char*)malloc(1024*sizeof(char));
    if (response == NULL) {
        return NULL;
    }
    struct Request request;

    int j = 0;
    while (request_text[j] != ' ') {
        request.line.method[j] = request_text[j];
        j++;
    }
    bool in_list = false;
    for (int i=0; i < request_methods_size; i++) {
        if (strcmp(request_methods[i], request.line.method)) {
            in_list = true;
            break;
        }
    }
    if (in_list) {
        strcpy(response, "HTTP/1.1 200 OK\n\nValid request");
    }
    else {
        strcpy(response, "HTTP/1.1 200 OK\n\nInvalid request");
    }


    return response;
}
