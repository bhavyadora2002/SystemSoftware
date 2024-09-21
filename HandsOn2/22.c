/*
============================================================================
Name : 22.c
Author : Dora Bhavya Rishitha
Description :22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/select.h>

int main()
{
  
  char data[30];
  fd_set rdfd;
  struct timeval tv;
  int fd= open("fifo23",O_RDONLY);
  if(fd == -1){
    printf("Cannot open file\n");
  }
  FD_ZERO(&rdfd);
  FD_SET(fd,&rdfd);
  tv.tv_sec=10;
  tv.tv_usec=0;
  
  printf("Waiting for 10 seconds\n");
   int retval = select(fd+1,&rdfd,NULL,NULL,&tv);
  if(retval==-1)
    perror("error");
  else if (retval)
  {
    printf("Data received\n");
    read(fd,data,sizeof(data));
    printf("Data: %s \n",data);
    
  }
   else
    printf("No data received in 10 seconds\n");
    
}
/*
OUTPUT:
============================================================================
FIRST TIME

TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 22.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Waiting for 10 seconds
Data received
Data: testFile 
TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 20b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Enter text for fifo file:
testFile

SECOND TIME

TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 22.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Waiting for 10 seconds
No data received in 10 seconds

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 20b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Enter text for fifo file:


=============================================================================
*/