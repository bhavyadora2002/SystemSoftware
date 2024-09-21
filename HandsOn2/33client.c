/*
============================================================================
Name : 33client.c
Author : Dora Bhavya Rishitha
Description :33. Write a program to communicate between two machines using socket.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
  struct sockaddr_in server;
  int sd;
  char buf[14];
  sd = socket(AF_UNIX,SOCK_STREAM,0);
  if(sd == -1){
    perror("Socket creation error");
    exit(0);
  }
  
  server.sin_family = AF_UNIX;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(5056);
  
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
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 33client.c  -o 33client.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./33client.out 
Connection established from client
Message from server : Server Message
*/