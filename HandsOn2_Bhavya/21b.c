/*
============================================================================
Name : 21b.c
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
    int fd = open("fifo21a",O_WRONLY);
    int fd1 = open("fifo21b",O_RDONLY);

    printf("Enter text to fifo21a file\n");
    scanf(" %[^\n]",buf);
    write(fd,buf,sizeof(buf));

    read(fd1,buf1,sizeof(buf1));
    printf("Text from fifo21b file is %s\n",buf1);
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