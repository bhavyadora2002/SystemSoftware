/*
============================================================================
Name : 2.c
Author : Hymavathi Jayaramappa
Description :Write a separate program (for each time domain) to set a interval tmr in 10sec and
10micro second
a. Itimer_REAL
b. Itimer_VIRTUAL
c. Itimer_PROF
Date: 12th sept, 2024.
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
outptut:
hyma@hyma-Latitude-7390:~/Handson2$ cc 2.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Soft Limit is(Current) is -1
Hard Limit is(Max) is -1
*/