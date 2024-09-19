/*
============================================================================
Name : 9.c
Author : Dora Bhavya Rishitha
Description :9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
    printf("Received signal is %d\n",sig);
    exit(0);
}
int main(){

    if(signal(SIGINT,SIG_IGN) ==  SIG_ERR){
        perror("Error while assigning signal handler");
    }else{
        sleep(5);
    }
    if(signal(SIGINT,SIG_DFL) ==  SIG_ERR){
        perror("Error while assigning signal handler");
    }else{
        while(1);
    }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 8b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
^CReceived signal is 2
============================================================================
*/