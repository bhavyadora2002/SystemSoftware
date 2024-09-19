/*
============================================================================
Name : 12.c
Author : Dora Bhavya Rishitha
Description :12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    if(!fork()){
        int st = kill(getppid(),SIGKILL);
        if(st == -1){
            perror("Error creating orphan process");
        }else{
            printf("\nParent is killed and child is now orphan\n");
        }
    }else{
        while(1);
    }
    return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 12.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out

Parent is killed and child is now orphan
Killed 
============================================================================
*/