

/*
============================================================================
Name :34bClient.c
Author : Hymavathi Jayaramappa
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date:20 sept 2024
===========================================================
*/


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Erroe when creating socket");
        _exit(0);
    }
    printf("Socket createdSuccessfully\n");

    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);


    int connectionS = connect(sd, (struct sockaddr *)&address, sizeof(address));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server established\n");

    char buf[100];
    
    read(sd, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write massage for server: \n");
    scanf("%[^\n]", buf);

    write(sd, buf, sizeof(buf));
    printf("Data sent to server\n");

    
    close(sd);
}

/*output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 34bClient.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Socket createdSuccessfully
Connection with server established
Data from server: Hello from server

Write massage for server: 
hello server i am writing from client
Data sent to server

*/