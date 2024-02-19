#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <asm-generic/socket.h>

int main(int argc, char* argv[]) {
    int sockfd;
    int new_socket;
    int opt = 1;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    ssize_t valread;
    char buffer[1024] = { 0 };
    char* response = "HTTP/1.1 200 ok\nContent-Type: text/html\nContent-Length: 7\n\nWorks!\n";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socete failed");
        exit(EXIT_FAILURE);
    }


    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setcoskpot");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);
    
    if ((bind(sockfd, (struct sockaddr*)&address, sizeof(address))) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if ((listen(sockfd, 3)) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(sockfd, (struct sockaddr*)&address, &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        valread = read(new_socket, buffer, 1024 - 1); 
        printf("%s", buffer);
        send(new_socket, response, strlen(response), 0); 
        printf("response sent:\n %s", response);
        close(new_socket);
    }
    close(sockfd);
    return 0;
}
