/*
============================================================================
Name : 1b.c
Author : Dora Bhavya Rishitha
Description :Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
void main(){
	const char *path1 = "link.txt";
	const char *path2 = "hrdlinkSC.txt";
	int errno = link(path1,path2);
	if(errno == 0){
	printf("SUCCESS");
	}else{
	perror("");
	printf("FAILURE");
	}
}
/*
========================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
SUCCESS
========================================================================
*/
