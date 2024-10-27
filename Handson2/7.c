/*
============================================================================
Name : 7.c
Author : Hymavathi Jayaramappa
Description : WWrite a simple program to print the created thread ids.
Date: 12th sept, 2024.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("I have created succesfully and Printing from thread :%lu\n", pthread_self());
}

void main()
{
    pthread_t Td1, Td2, Td3;
    int pstatus;
    pstatus = pthread_create(&Td1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&Td2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&Td2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 7.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
I have created succesfully and Printing from thread :139838172952256
I have created succesfully and Printing from thread :139838164559552
I have created succesfully and Printing from thread :139838156166848

*/