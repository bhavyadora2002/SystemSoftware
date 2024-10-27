/*
============================================================================
Name : 9.c
Author : Hymavathi Jayaramappa
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 12th sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    __sighandler_t status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    status=signal(SIGINT, SIG_IGN);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); // SIGINT will be ingnored for 5 seconds
    }

    printf("reseting the default action of the SIGINT signal\n");
    status = signal(SIGINT, SIG_DFL);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 9.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal

*/