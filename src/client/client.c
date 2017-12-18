#include "client.h"

int clientStart(char * clientStr) {
    // Structure to connect to the server
    struct sockaddr_in server;
    int server_fd = 0, valread;
    char *hello = "Hello from clientOn!";
    char buf[MAX_SIZE_BUF] = {0};

    printf("CREATING CLIENT SOCKET...\n");

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)), 0) {
        printf("\tsocket creation failed!!!");
        exit(EXIT_FAILURE);
    }
    printf("\tDONE!!!\n");

    printf("DEFINING CLIENT SOCKET FAMILY, ADDRESS & PORT...\n");
    // assigning types of the socket created using 'struct sockaddr_in'
    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, SERVER_ADDRESS, &server.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    printf("CLIENT CONNECTING ON PORT 8080 TO COMMUNICATE WITH SERVER...\n");
    if(connect(server_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    // Send hello message to the sever
    send(server_fd, clientStr, str_length(clientStr), 0);

    //printf("HELLO MESSAGE SENT!!!");

    valread = (int) recv(server_fd, buf, MAX_SIZE_BUF, 0);

    printf("message from server: %s\n", buf);

/*
 *  while(1) {
 *  memset(buffer, 0, sizeof(buffer));
 *  memset(cchat, 0, sizeof(cchat));
 *  printf("CLIENT : ");
 *  fgets (cchat, sizeof(cchat), stdin);
 *  send(sock , cchat , strlen(cchat) , 0 );
 *  valread = read( sock , buffer, 1024);
 *  printf("%s\n",buffer );
 *  cchat[strlen(cchat)] = '\0';
 *  if(strncmp(cchat, bye, strlen(bye))==0)
 *      break;
 *
 *
 *  }
 * */
}

size_t str_length(const char* buf) {
    size_t i;
    for (i = 0; buf[i] != '\0'; ++i);
    return i;
}

