
/*
============================================================================
Name : 34server.c
Author : Dora Bhavya Rishitha
Description :34. Write a program to create a concurrent server.
b. use pthread_create
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* handler(void * arg)
 { 
    char buf[20];    
    int conid = *((int*)arg);
    if(read(conid,buf,sizeof(buf)) == -1)
    {
        perror("Unable to read");
        exit(0);
    }

    printf("Message from Client : %s\n",buf);
    if(write(conid,"Server Message\n",14) == -1){
        perror("Unable to write");
         exit(0);
    }
    write(conid,"Server Message\n",14);
    exit(0);
}
void main()
{
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Socket creation error");
    }
   
    char buf[14];
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5055);

    if(bind(sd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Unable to bind");
        exit(0);
    }

    if (listen(sd, 1) == -1)
    {
        perror("Unable to listen");
        exit(0);
    }

    while (1)
    {
        int cz = (int)sizeof(client);
        int conid = accept(sd, (struct sockaddr *)&client, &cz);
        if (conid == -1)
        {
            perror("Unable to connect");
            exit(0);
        }
        pthread_t id;
        pthread_create(&id,NULL,handler,&conid);   
    }
    close(sd);
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 34bserver.c -o 34bserver.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./34bserver.out
Message from Client : Client Message
*/