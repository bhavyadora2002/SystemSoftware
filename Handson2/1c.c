/*
============================================================================
Name : 1c.c
Author : Hymavathi Jayaramappa
Description :Write a separate program (for each time domain) to set a interval tmr in 10sec and
10micro second
a. Itimer_REAL
b. Itimer_VIRTUAL
c. Itimer_PROF
Date: 12th sept, 2024.
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

/* output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 1c.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Received signal is 27

*/