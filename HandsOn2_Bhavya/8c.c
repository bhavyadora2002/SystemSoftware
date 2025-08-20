/*
============================================================================
Name : 8c.c
Author : Dora Bhavya Rishitha
Description :8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
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
    int j;
    signal(SIGFPE,handler);
    j = 5/0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 8c.c
8c.c: In function ‘main’:
8c.c:21:10: warning: division by zero [-Wdiv-by-zero]
   21 |     j = 5/0;
      |          ^
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Received signal is 8
============================================================================
*/