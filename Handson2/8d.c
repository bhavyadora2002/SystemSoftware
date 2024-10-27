/*
============================================================================
Name : 8d.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using signal system call to catch the following signals.
    d. SIGALRM (use alarm system call)
Date: 12th sept, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("SIGALRM caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;
    alarm(2); // Set an alarm for 2 second
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
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 8d.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
SIGALRM caught

*/