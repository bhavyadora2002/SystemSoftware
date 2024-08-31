/*
============================================================================
Name : 24.c
Author : Dora Bhavya Rishitha
Description :Write a program to create an orphan process.
Date :29th August,2024
===========================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
        int t = fork();
        if(t == -1)
        {
                printf("Cannot create child process\n");
        }else if(t==0){
                printf("In CHILD Process\n");
		printf("Before becoming orphan\n");
                printf("Parent Process ID:%d\n",getppid());
                printf("Child Process ID:%d\n",getpid());
		sleep(5);
		printf("In CHILD Process\n");
		printf("After becoming orphan\n");
                printf("Parent Process ID:%d\n",getppid());
                printf("Child Process ID:%d\n",getpid());

        }else{
		sleep(1);
                printf("In PARENT Process\n");
                printf("Parent Process ID:%d\n",getpid());
                printf("Child Process ID:%d\n",t);
	}
}
/*
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 24.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
In CHILD Process
Before becoming orphan
Parent Process ID:9419
Child Process ID:9420
In PARENT Process
Parent Process ID:9419
Child Process ID:9420
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ In CHILD Process
After becoming orphan
Parent Process ID:2019
Child Process ID:9420
============================================================================
*/
