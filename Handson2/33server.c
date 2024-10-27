

/*
============================================================================
Name :33server.c
Author : Hymavathi Jayaramappa
Description : Write a program to communicate between two machines using socket
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
    int SocketID = socket(AF_INET, SOCK_STREAM, 0);
    if (SocketID == -1)
    {
        perror("Error occured while  creating socket");
    }
    printf("server Socket created\n");

    // server info
    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY); // host to network long
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    int bs = bind(SocketID, (struct sockaddr *)&server, sizeof(server));
    if (bs == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to server socket was successful!\n");

    // listen for connection
    int listenS = listen(SocketID, 2);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        _exit(0);
    }
    printf("Listning from Connection ");

    int client_size = (int)sizeof(client);
    int connectionfd = accept(SocketID, (struct sockaddr *)&client, &client_size);
    if (connectionfd == -1)
    {
        perror("Error while accepting Connection");
        _exit(0);
    }
    else
    {
        char buf[100];
        printf("Write massage from server to client: ");
        scanf("%[^\n]", buf);
        // write fron server to connection fd
        write(connectionfd, buf, sizeof(buf));

        read(connectionfd, buf, 100);
        printf("Data from client: %s\n", buf);
    }

    // closing socket
    close(SocketID);
}

/*
Output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 33server.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
server Socket created
Binding to server socket was successful!
hello
i am writing from server
Listning from Connection Write massage form server to client: Data from client: hello i am writing from client

*/