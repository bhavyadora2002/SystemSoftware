/*
============================================================================
Name : 25.c
Author : Dora Bhavya Rishitha
Description :25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int t1 = fork();
	if(t1==0){
		printf("This is child 1 and its parent id is %d\n",getppid());
		sleep(10);
		printf("Child 1 completed it's sleeping time\n");
	}else{
		int t2 = fork();
		if(t2==0){
			printf("This is child 2 and its parent id is %d\n",getppid());
			sleep(5);
			printf("Child 2 completed it's sleeping time\n");
		}else{
			int t3 = fork();
			if(t3==0){
				printf("This is child 3 and its parent id is %d\n",getppid());
				sleep(5);
				printf("Child 3 completed it's sleeping time\n");
			}else{
				printf("This is parent process and it's id is %d\n",getpid());
				printf("Parent process waiting for child process to teminate\n");
				waitpid(t1,NULL,0);
				waitpid(t2,NULL,0);
				waitpid(t3,NULL,0);
				printf("All child process are completed\n");
				printf("Parent process terminated\n");
			}
		}
	}
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 25.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
This is child 1 and its parent id is 32274
This is parent process and it's id is 32274
Parent process waiting for child process to teminate
This is child 2 and its parent id is 32274
This is child 3 and its parent id is 32274
Child 2 completed it's sleeping time
Child 3 completed it's sleeping time
Child 1 completed it's sleeping time
All child process are completed
Parent process terminated
============================================================================
*/
