/*
============================================================================
Name : 8e.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using signal system call to catch the following signals.
    e. SIGALRM (use setitimer system call)
Date: 12th sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void print()
{
    printf("SIGALRM caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2; // Set an alarm for 2 second
    timer.it_value.tv_usec = 0;
    int timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");
    status = signal(SIGALRM, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        while (1)
            ; // waiting for alarm
    }
}

/*
output: hyma@hyma-Latitude-7390:~/Handson2$ cc 8e.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
SIGALRM caught

*/