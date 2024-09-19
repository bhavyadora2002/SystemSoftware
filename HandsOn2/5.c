/*
============================================================================
Name : 5.c
Author : Dora Bhavya Rishitha
Description :5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
void main(){
    int val;
    val = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions is %d\n",val);
    val = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID is %d\n",val);
    val = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second is %d\n",val);
    val = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files is %d\n",val);
    val = sysconf(_SC_PAGE_SIZE);
    printf("Size of a page in bytes is %d\n",val);
    val = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory is %d\n",val);
    val = sysconf(_SC_AVPHYS_PAGES);
    printf("The number of currently available pages of physical memory is %d\n",val);
    }
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 5.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Maximum length of the arguments to the exec family of functions is 2097152
Maximum number of simultaneous processes per user ID is 62167
Number of clock ticks (jiffy) per second is 100
Maximum number of open files is 1024
Size of a page in bytes is 4096
Total number of pages in the physical memory is 3996518
The number of currently available pages of physical memory is 1961482
============================================================================
*/