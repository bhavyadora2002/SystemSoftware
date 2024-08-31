/*
============================================================================
Name : 11a.c
Author : Dora Bhavya Rishitha
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
Date: 29th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd = open("dupliateFile11.txt",O_CREAT|O_RDWR,0644);
	if(fd == -1)
		perror("ERROR:");
	int fd1 = dup(fd);
	write(fd,"Writing using first file descriptor\n",37);
	write(fd1,"Writing using second file descriptor",37);
	close(fd);
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 11a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat dupliateFile11.txt
Writing using first file descriptor
Writing using second file descriptor
============================================================================
*/
