#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int sock;
void handler(int arg) {
    sock = arg;
}

void login(char *type){

    char username[20], password[20], server_reply[200];


    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if(send(sock,type,sizeof(type),0) == -1){
        perror("Failed to send type of user");
        exit(1);
    }


    if (send(sock, username, sizeof(username), 0) == -1) {
        perror("Failed to send username");
        exit(1);
    }
    if (send(sock, password, sizeof(password), 0) == -1) {
        perror("Failed to send password");
        exit(1);
    }
    int recv_len = recv(sock, server_reply, sizeof(server_reply), 0);
    if (recv_len > 0) {
        server_reply[recv_len] = '\0'; 
        printf("Server reply: %s\n", server_reply);
    } else {
        printf("Failed to receive server reply.\n");
    }
}