/*
============================================================================
Name : 13b.c
Author : Dora Bhavya Rishitha
Description :13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    if(kill(getpid(),SIGSTOP) == 0){
        printf("\nKilled");
    }else{
        perror("Cannot send SIGSTOP");
    }
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 13b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out

[1]+  Stopped                 ./a.out
============================================================================
*/