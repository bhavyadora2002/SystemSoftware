/*
============================================================================
Name : 8b.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using signal system call to catch the following signals.
    b. SIGINT
Date: 12th sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("SIGINT caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGINT, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT); // SIGINT signal is sent to a process by its controlling terminal when a user wishes to interrupt the process
    }
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 8b.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
SIGINT caught

*/