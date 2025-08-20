/*
============================================================================
Name : 8b.c
Author : Dora Bhavya Rishitha
Description :8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
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

    signal(SIGINT,handler);
    while(1);
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 8b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
^CReceived signal is 2
============================================================================
*/