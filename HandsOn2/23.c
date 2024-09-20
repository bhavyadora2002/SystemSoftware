/*
============================================================================
Name : 23.c
Author : Dora Bhavya Rishitha
Description :23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/select.h>

int main(){
    int fd,retval;
    char buf[80];
    fd_set rfds;
    struct timeval tv;
    fd = open("fifo23",O_RDONLY);
    if(fd == -1){
        perror("Error opening file");
        exit(0);
    }
    FD_ZERO(&rfds);
    FD_SET(fd,&rfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    retval = select(fd+1,&rfds,NULL,NULL,&tv);
    printf("%d",retval);
    if(retval== -1){
        perror("ERROR");
        exit(0);
    }
    else if(retval){
        printf("Data is available\n");
    }else{
        printf("No data is available within 10 seconds\n");
        exit(0);
    }
    read(fd,buf,sizeof(buf));
    printf("Text from fifo file is %s\n",buf);
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 21b.c -o 21b.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./21b.out
Enter text to fifo21a file
fifo21a_input
Text from fifo21b file is fifo21b_input
=============================================================================
*/