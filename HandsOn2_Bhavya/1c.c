
/*
============================================================================
Name : 1c.c
Author : Dora Bhavya Rishitha
Description :1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
Date: 20th Sep, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


void handler(int sig)
{
  printf("Received signal is %d\n",sig);
  exit(0);
}

int main()
{
  struct itimerval t;
    t.it_value.tv_sec = 2;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 5;
    t.it_interval.tv_usec = 0;
  signal(SIGPROF, handler);
  if(setitimer(ITIMER_PROF,&t,0) == -1)
  perror("Error while setting timer");
  while(1);
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 1c.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Received signal is 27
============================================================================
*/
