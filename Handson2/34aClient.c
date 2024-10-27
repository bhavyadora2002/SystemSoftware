
/*
============================================================================
Name :34a.c
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
    int bs = socket(AF_INET, SOCK_STREAM, 0);
    if (bs == -1)
    {
        perror("Error while creating socket");
        _exit(0);
    }
    printf("Socket created  Successfully\n");

    // assigning server info
    struct sockaddr_in add;
    add.sin_addr.s_addr = htonl(INADDR_ANY); 
    add.sin_family = AF_INET;
    add.sin_port = htons(8080);

    // make connection to the server
    int connectionS = connect(bs, (struct sockaddr *)&add, sizeof(add));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server Established Successfully\n");

    char buf[100];
    // read fron server
    read(bs, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write massage for server: \n");
    scanf("%[^\n]", buf);

    write(bs, buf, sizeof(buf));
    printf("Data sent to server\n");

    // closing socket
    close(bs);
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 34aClient.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Socket created  Successfully
Connection with server Established Successfully
hello i am writing from client concurrentlyData from server: hello i am writing from server to client
Write massage for server: 
hello from server
Data sent to server

*/