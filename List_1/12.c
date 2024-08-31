/*
============================================================================
Name : 12.c
Author : Dora Bhavya Rishitha
Description :12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 29th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd = open("inputFile12.txt",O_WRONLY|O_CREAT,0777);
	write(fd,"Input file for program 12",25);
	if(fd == -1){
		perror("ERROR:");
		return 0;
	}
	int flag = fcntl(fd,F_GETFL);
	int access_mode = flag & O_ACCMODE;
	if(access_mode == O_RDONLY)
		printf("File is opened in read only mode\n");
	else if(access_mode == O_WRONLY)
		printf("File is opened in write only mode\n");
	else if(access_mode == O_RDWR)
		printf("File is opened in read write mode\n");
	else
		printf("File is opened in unknown mode\n");
	return 0;
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 12.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
File is opened in write only mode
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat inputFile12.txt
Input file for program 12
============================================================================
*/
