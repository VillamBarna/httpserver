#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "consts.h"

void get_request(char target[], char* response) {
    FILE* html_file;
    char* file_name = (char*)malloc(32*sizeof(char));
    long length;
    char* buffer;

    printf("target: %s\n", target);
    if (strcmp(target, "/") == 0) {
        strcpy(file_name, "index.html");
    }
    else {
        target++;
        strcpy(file_name, target);
    }
    printf("filename: %s\n", file_name);
    html_file = fopen(file_name, "r");
    if (html_file == NULL) {
        printf("couldn't load file %s\n", file_name);
        strcpy(response, line404);
        strcat(response, header_break);
        strcat(response, "File not found!\n");
        return;
    }

    strcpy(response, line200);
    strcat(response, content_text);
    strcat(response, header_break);
    fseek(html_file, 0, SEEK_END);
    length = ftell(html_file);
    rewind(html_file);
    buffer = (char*)malloc(length + 1);

    fread(buffer, 1, length, html_file);
    buffer[length] = '\0';
    strcat(response, buffer);
    fclose(html_file);
    free(buffer);
    free(file_name);
}