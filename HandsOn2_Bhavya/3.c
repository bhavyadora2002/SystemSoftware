/*
============================================================================
Name : 3.c
Author : Dora Bhavya Rishitha
Description :3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 14th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>

int main(int argc,char * argv[]){
    struct rlimit rlim;
    struct rlimit rlimold;
    if(argc != 3){
    fprintf(stderr,"Incorrect number of arguments");
    exit(0);
    }
    rlim.rlim_cur = atoi(argv[1]);
    rlim.rlim_max = atoi(argv[2]);
    if(getrlimit(0,&rlimold) == -1){
        perror("ERROR:");
    }
    else{
        printf("Soft Limit is(Current) is %ld",rlimold.rlim_cur);
        printf("\nHard Limit is(Max) is %ld",rlimold.rlim_max);
    }
    if(setrlimit(0,&rlim) == -1)
        perror("ERRRO:");
    else{
        if(getrlimit(0,&rlimold) == -1)
        perror("ERROR:");
        else{
        printf("\nSoft Limit is(Current) is %ld",rlimold.rlim_cur);
        printf("\nHard Limit is(Max) is %ld",rlimold.rlim_max);
        }
    }
    return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out 0 1
Soft Limit is(Current) is -1
Hard Limit is(Max) is -1
Soft Limit is(Current) is 0
Hard Limit is(Max) is 1
============================================================================
*/