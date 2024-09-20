/*
============================================================================
Name : 21a.c
Author : Dora Bhavya Rishitha
Description :21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buf[100],buf1[100];
    int fd = open("fifo21a",O_RDONLY);
    int fd1 = open("fifo21b",O_WRONLY);

    printf("Enter text to fifo21b file\n");
    scanf(" %[^\n]",buf);

    write(fd1,buf,sizeof(buf));
    read(fd,buf1,sizeof(buf1));
    printf("Text from fifo21a file is %s\n",buf1);
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 21a.c -o 21a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./21a.out
Enter text to fifo21b file
fifo21b_input
Text from fifo21a file is fifo21a_input
=============================================================================
*/