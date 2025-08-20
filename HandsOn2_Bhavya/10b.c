/*
============================================================================
Name : 10b.c
Author : Dora Bhavya Rishitha
Description :10. Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
    printf("Received signal is %d\n",sig);
    exit(0);
}
int main(){
    struct sigaction s;
    s.sa_handler = handler;
    s.sa_flags = 0;
    if(sigaction(SIGINT,&s,NULL) == -1){
        perror("Error assigning signal handler");
    }else{
        while(1);
    }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 10b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
^CReceived signal is 2
============================================================================
*/