/*
============================================================================
Name : 8a.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using signal system call to catch the following signals.
    a.SIGSEGV
Date: 12th sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("SIGSEGV caught Successfully\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGSEGV, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV); //// Send segmentation fault signal
    }
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 8a.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
SIGSEGV caught Successfully

*/