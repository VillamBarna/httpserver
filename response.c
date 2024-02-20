#include "response.h"
#include <stdlib.h>

char* generate_response(char request[]) {
    char* method = (char*)malloc(1024*sizeof(char));
    int i = 0;
    while (request[i] != ' ') {
        method[i] = request[i];
        i++;
    }

    return method;
}