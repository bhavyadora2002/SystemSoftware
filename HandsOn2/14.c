/*
============================================================================
Name : 14.c
Author : Dora Bhavya Rishitha
Description :14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    int fd[2];
    int a;
    int b; 
    if(pipe(fd) == -1)
    perror("Error creating pipe");  
    printf("\nEnter a number:");
    scanf("%d",&a);
    if(write(fd[1],&a,sizeof(int)) == -1)
    perror("Error Writing");
    close(fd[1]);
    if(read(fd[0],&b,sizeof(int)) == -1)
    perror("Error Reading");
    close(fd[0]);
    printf("\nDisplaying on monitor");
    printf("\nThe value read is %d",b);
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 14.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out

Enter a number:46

Displaying on monitor
The value read is 46
============================================================================
*/