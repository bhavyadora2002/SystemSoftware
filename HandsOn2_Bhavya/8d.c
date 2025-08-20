/*
============================================================================
Name : 8d.c
Author : Dora Bhavya Rishitha
Description :8. Write a separate program using signal system call to catch the following signals.
d. SIGALRM
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void handler(int sig){
    printf("Received signal is %d\n",sig);
    exit(0);
}
int main(){
    
    signal(SIGALRM,handler);
    alarm(5);
    while(1);
    
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 8d.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Received signal is 14
============================================================================
*/