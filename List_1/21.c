/*
============================================================================
Name : 21.c
Author : Dora Bhavya Rishitha
Description :21. Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	int t = fork();
	if(t == -1)
	{
		printf("Cannot create child process\n");
	}else if(t>0){
		printf("In PARENT Process\n");
		printf("Parent Process ID:%d\n",getppid());
		printf("Child Process ID:%d\n",t);
	}else{
		printf("In CHILD Process\n");
		printf("Parent Process ID:%d\n",getppid());
		printf("Child Process ID:%d\n",getpid());
	}
	return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
In PARENT Process
Parent Process ID:51009
Child Process ID:51494
In CHILD Process
Parent Process ID:1955
Child Process ID:51494
============================================================================
*/

