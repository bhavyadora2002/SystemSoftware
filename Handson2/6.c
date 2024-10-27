/*
============================================================================
Name : 6.c
Author : Hymavathi Jayaramappa
Description : Write a simple program to create three threads.

Date: 12th sept, 2024.
============================================================================
*/


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread\n");
}

void main()
{
    pthread_t threadId1, threadId2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadId1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadId2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadId2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}


/*
output:

hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Printing from thread
Printing from thread
Printing from thread

*/