/*
============================================================================
Name : 4.c
Author : Dora Bhavya Rishitha
Description :4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc(){
        unsigned long long dst;
        __asm__ __volatile__("rdtsc":"=A"(dst));
}
int main(){
        unsigned long long int start,end;
        start = rdtsc();
        for(int i = 0;i<100;i++){
        int pid = getppid();
        }   
        end = rdtsc();
        int nano = (end-start)/2.09;
        printf("Time taken to execute 100 getppid system calls is %d nano seconds\n",nano);
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 4.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Time taken to execute 100 getppid system calls is 31148 nano seconds
============================================================================
*/