/*
============================================================================
Name : 20a.c
Author : Dora Bhavya Rishitha
Description :20. Write two programs so that both can communicate by FIFO -Use one way communication.
a. program to read
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buf[100];
    int fd = open("fifo20",O_RDONLY);
    if(fd == -1){
        perror("cannot open fifo file");
        exit(0);
    }
    read(fd,buf,sizeof(buf));
    printf("The text from FIFO is: %s\n",buf);
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 20a.c -o 20a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./20a.out
The text from FIFO is: testFile
=============================================================================
*/