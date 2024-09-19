/*
============================================================================
Name : 2.c
Author : Dora Bhavya Rishitha
Description :2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 14th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

int main(){
    struct rlimit rlim;
    if(getrlimit(0,&rlim) == -1)
        perror("ERRRO:");
    else{
        printf("Soft Limit is(Current) is %ld",rlim.rlim_cur);
        printf("\nHard Limit is(Max) is %ld",rlim.rlim_max);

    }
    return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 2.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Soft Limit is(Current) is -1
Hard Limit is(Max) is -1
============================================================================
*/