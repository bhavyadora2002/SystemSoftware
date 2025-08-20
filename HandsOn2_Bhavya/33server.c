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
  struct sockaddr_in server, client;
  int sd, sz, nsd;
  char buf[14];
  sd = socket(AF_UNIX,SOCK_STREAM,0);
  if(sd == -1){
    perror("socket creation error");
    exit(0);
  }
  server.sin_family = AF_UNIX;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(5056);
  
  if(bind(sd,(void*)(&server),sizeof(server))==-1){
    perror("unable to bind");
    exit(0);
  }
  
  if(listen(sd,1) == -1){
    perror("Unable to listen");
    exit(0);
  }
  sz = sizeof(client);
  
  nsd = accept(sd,(void*)(&client),&sz);
  printf("Connection established\n");
  if(read(nsd,buf,sizeof(buf)) == -1)
  {
    perror("Unable to read");
    exit(0);
  }

  printf("Message from Client : %s\n",buf);
  if(write(nsd,"Server Message\n",14) == -1){
    perror("Unable to write");
    exit(0);
  }
  
  close(sd);
  close(nsd);
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 33server.c -o 33server.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./33server.out
Connection established
Message from Client : Client Message
*/