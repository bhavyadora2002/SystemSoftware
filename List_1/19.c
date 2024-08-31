/*
============================================================================
Name : 19.c
Author : Dora Bhavya Rishitha
Description :19.Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2024.
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
	int pid = getpid();
	end = rdtsc();
	int nano = (end-start)/2.09;
	printf("Time taken to execute getpid system call is %d nano seconds",nano);
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 19.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Time taken to execute getpid system call is 5671 nano seconds
============================================================================
*/
