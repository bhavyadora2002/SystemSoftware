/*
============================================================================
Name : 8c.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using signal system call to catch the following signals.
    c. SIGFPE
Date: 12th sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("SIGFPE caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGFPE, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGFPE); 
        /* SIGFPE may occur due to 
            1.division by zero
            2.modulo operation by zero
            3.integer overflow(when the value you are trying to store exceeds the range) trying using a bigger data type like long.
        */
    }
}

/* output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 8c.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
SIGFPE caught

*/