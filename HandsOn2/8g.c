/*
============================================================================
Name : 8e.c
Author : Dora Bhavya Rishitha
Description :8. Write a separate program using signal system call to catch the following signals.
g. SIGPROF(using setitimer system call)
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include <sys/time.h>


void handler(int sig){
    printf("Received signal is %d\n",sig);
    exit(0);
}
int main(){
    struct itimerval t;
    t.it_interval.tv_sec = 0;
    t.it_value.tv_usec = 0;
    t.it_value.tv_sec = 2;
    t.it_value.tv_usec = 0;
    if(setitimer(ITIMER_PROF,&t,0) == -1)
    perror("Error while setting timer");
    __sighandler_t err = signal(SIGPROF,handler);
    if(err == SIG_ERR){
        printf("Error while assigning signal handler\n");
    }else{
    while(1);
    }   
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 8g.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Received signal is 27
============================================================================
*/