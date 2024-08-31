/*
============================================================================
Name : 1a.c
Author : Dora Bhavya Rishitha
Description :Create the following types of a files using (i) shell command (ii) system call
a.soft link (symlink system call)
Date: 29th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int errno;
	errno = symlink(path1,"SymLink");
	perror("symlink");
	printf("%d\n",errno);
	if(errno == 0)
		printf("Success");
	else
		printf("Failure");
}

/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 1a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
symlink: Success
0
Success
*/



