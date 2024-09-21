/*
============================================================================
Name : 23.c
Author : Dora Bhavya Rishitha
Description :23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <string.h>

int main()
{
  int fd[2];
  pipe(fd);
  long open=sysconf(_SC_OPEN_MAX);
  printf("Maximum number of open files: %lu \n",open);
  
  long size = pathconf(".",_PC_PIPE_BUF);
  printf("Maximum size of pipe buffer: %lu\n",size);
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 23.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Maximum number of open files: 1024 
Maximum size of pipe buffer: 4096
*/