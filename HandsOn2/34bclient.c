/*
============================================================================
Name : 34client.c
Author : Dora Bhavya Rishitha
Description :34. Write a program to create a concurrent server.
b. use pthread_create
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>


int main()
{
  struct sockaddr_in server;
  int sd;
  char buf[14];
  sd = socket(AF_INET,SOCK_STREAM,0);
  if(sd == -1){
    perror("Socket creation error");
    exit(0);
  }
  
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(5055);
  
  if(connect(sd,(void*)(&server),sizeof(server)) == -1){
    perror("Unable to connect");
    exit(0);
  }

  printf("Connection established from client\n");
  if(write(sd,"Client Message\n",14) == -1){
    perror("Unable to write");
    exit(0);
  }
  
  if(read(sd,buf,sizeof(buf)) == -1){
    perror("Unable to read");
    exit(0);
  }

  printf("Message from server : %s\n",buf);
  close(sd);
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 34aclient.c -o 34aclient.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./34aclient.out
Connection established from client
Message from server : Server Message
*/

