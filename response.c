#include "response.h"
#include <stdlib.h>
#include "consts.h"
#include <stdbool.h>
#include <string.h>
#include "requests.h"
#include <stdio.h>

char* generate_response(char request_text[]) {
    char* response = (char*)malloc(1024*sizeof(char));
    int j = 0;
    int k = 0;
    if (response == NULL) {
        return NULL;
    }
    char method[20] = {0};
    char target[20] = {0};
    char version[20] = {0};

    k = 0;
    while (request_text[j] != ' ' && request_text[j] != '\0' && request_text[j] != '\n') {
        method[k] = request_text[j];
        j++;
        k++;
    }
    j++;
    bool in_list = false;
    for (int i=0; i < request_methods_size; i++) {
        if (strcmp(request_methods[i], method)) {
            in_list = true;
            break;
        }
    }
    if (!in_list) {
        strcpy(response, "HTTP/1.1 200 OK\n\nInvalid request");
        return response;
    }

    k = 0;
    while (request_text[j] != ' ' && request_text[j] != '\0' && request_text[j] != '\n') {
        target[k] = request_text[j];
        printf("%c\n", request_text[j]);
        j++;
        k++;
    }
    j++;
    k = 0;
    while (request_text[j] != ' ' && request_text[j] != '\0' && request_text[j] != '\n') {
        version[k] = request_text[j];
        j++;
        k++;
    }
    j++;
    if (strcmp(method, "GET") == 0) {
        get_request(target, response);
    }

    return response;
}


