/*
============================================================================
Name : 6.c
Author : Dora Bhavya Rishitha
Description :6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

void main(){
	char buf[20];
	int r = read(0,buf,20);
	if(r == -1)
	perror("ERROR");
	else{
	printf("Number of bytes of data read is %d\n",r);
	fflush(stdout);
	int w = write(1,buf,r);
	if(w == -1)
	perror("ERROR");
	}
}
	
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 6.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Hello World
Number of bytes of data read is 12
Hello World
============================================================================
*/
