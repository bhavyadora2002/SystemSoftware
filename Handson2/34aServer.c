
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
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Error when creating socket");
    }
    printf("server Socket created\n");

    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY); 
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    int bindS = bind(sd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to server socket was successful!\n");

    
    int listenS = listen(sd, 3);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        _exit(0);
    }
    printf("Listning from Connection \n");

    while (1)
    {
        int client_size = (int)sizeof(client);
        int connectionfd = accept(sd, (struct sockaddr *)&client, &client_size);
        if (connectionfd == -1)
        {
            perror("Error while accepting Connection\n");
            _exit(0);
        }
        else
        {
            if (fork() == 0)
            {
              
                char buf[100];
                printf("Write massage form server to client: \n");
                scanf("%[^\n]", buf);
                
                write(connectionfd, buf, sizeof(buf));

                read(connectionfd, buf, 100);
                printf("Data from client : %s\n",buf);
            }
            else
            {
                
                close(connectionfd);
            }
        }
    }

    
    close(sd);
}

/*output:
Data sent to serverhyma@hyma-Latitude-7390:~/Handson2$ cc 34aServer.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
server Socket created
Binding to server socket was successful!
Listning from Connection 
Write massage form server to client: 
hello i am writing from server to client
Data from client : hello i am writing from client concurrentlyhello from server



*/