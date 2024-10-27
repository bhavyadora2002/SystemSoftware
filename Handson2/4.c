/*
============================================================================
Name : 4.c
Author : Hymavathi Jayaramappa
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 12th sept, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// using time stamp counter we can find 
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;

    start = rdtsc();
    int it = 1;
    //for 100
    while (it <= 100)
    {
        getppid();
        it += 1;
    }

    end = rdtsc();

    printf("time required : %llu\n", end - start);
}




/*
============================================================================
OUTPUT :
hyma@hyma-Latitude-7390:~/Handson2$ cc 4.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
time required : 635728

*/