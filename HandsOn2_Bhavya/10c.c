/*
============================================================================
Name : 10c.c
Author : Dora Bhavya Rishitha
Description :10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
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
    if(sigaction(SIGFPE,&s,NULL) == -1){
        perror("Error assigning signal handler");
    }else{
        int i,j;
        i = 5;
        j = 5/0;
    }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 10c.c
10c.c: In function ‘main’:
10c.c:28:14: warning: division by zero [-Wdiv-by-zero]
   28 |         j = 5/0;
      |              ^
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Received signal is 8
============================================================================
*/