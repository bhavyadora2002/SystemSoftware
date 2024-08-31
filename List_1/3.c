/*
============================================================================
Name : 3.c
Author : Dora Bhavya Rishitha
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 29th Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
int main(){
	int fd;
	const char *path = "creatFile_3.txt";
	mode_t mode = 0666;
	fd = creat(path,mode);
	printf("File Descriptor number of created file is %d",fd);
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 3.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
File Descriptor number of created file is 3
============================================================================
*/
