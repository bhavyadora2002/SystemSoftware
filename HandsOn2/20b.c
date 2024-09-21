/*
============================================================================
Name : 20b.c
Author : Dora Bhavya Rishitha
Description :20. Write two programs so that both can communicate by FIFO -Use one way communication.
a. program to write
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buf[100];
    int fd = open("fifo23",O_WRONLY);
    if(fd == -1){
        perror("cannot open fifo file");
        exit(0);
    }
    printf("Enter text for fifo file:\n");
    scanf("%s",buf);
    write(fd,buf,sizeof(buf));
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 20b.c -o 20b.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./20b.out
Enter text for fifo file:
testFile
=============================================================================
*/