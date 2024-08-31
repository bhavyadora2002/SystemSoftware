/*
============================================================================
Name : 29.c
Author : Dora Bhavya Rishitha
Description :29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>
int main(){
	struct sched_param s;
    	s.sched_priority = 20;
    	int pid = getpid();
    	int sched_policy = sched_getscheduler(pid);
	if(sched_policy == SCHED_FIFO)
		printf("Scheduling process is FIFO\n");
	else if(sched_policy == SCHED_RR)
		printf("Scheduling process is Round Robin\n");
	else if(sched_policy == SCHED_OTHER)
		printf("Scheduling process is Regular\n");
	else
		printf("Unknown\n");

	s.sched_priority = 20;
    	int t = sched_setscheduler(pid, SCHED_FIFO, &s);
    	sched_policy = sched_getscheduler(pid);
    	if(sched_policy==SCHED_FIFO)
		printf("Successfully set scheduling process to FIFO\n");
	else
		perror("ERROR:");

	s.sched_priority = 20;
	t = sched_setscheduler(pid, SCHED_RR, &s);
    	sched_policy = sched_getscheduler(pid);
    	if(sched_policy == SCHED_RR)
        	printf("Successfully set scheduling process to Round Robin\n");
    	else
		perror("ERROR:");
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 29.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ sudo ./a.out
Scheduling process is Regular
Successfully set scheduling process to FIFO
Successfully set scheduling process to Round Robin
============================================================================
*/

