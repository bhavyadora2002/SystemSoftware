/*
============================================================================
Name : 5.c
Author : Hymavathi Jayaramappa
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory..
Date: 12th sept, 2024.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
void main()
{
    long val;
    // _SC_ARG_MAX -  Maximum length of the arguments to the exec family of functions.
    val=sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions -%ld\n", val);

    // _SC_CHILD_MAX -  Maximum number of simultaneous process per user id.
    val = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous process per user id -%ld\n", val);

    // _SC_CLK_TCK -  Number of clock ticks (jiffy) per second.
    val = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second -%ld\n", val);

    // _SC_OPEN_MAX -  Maximum number of open files
    val = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files -%ld\n", val);

    // _SC_PAGESIZE -  Size of a page
    val = sysconf(_SC_PAGESIZE);
    printf("Size of a page -%ld bytes\n", val);

    // _SC_PHYS_PAGES -  Total number of pages in the physical memory
    val = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory -%ld\n", val);

    // _SC_AVPHYS_PAGES -  Number of  currently available pages in the physical memory.
    val = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of  currently available pages in the physical memory -%ld\n", val);
}


/*
============================================================================
OUTPUT :
@hyma-Latitude-7390:~/Handson2$ cc 5.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Maximum length of the arguments to the exec family of functions -2097152
Maximum number of simultaneous process per user id -30892
Number of clock ticks (jiffy) per second -100
Maximum number of open files -1024
Size of a page -4096 bytes
Total number of pages in the physical memory -1998102
Number of  currently available pages in the physical memory -236707


*/