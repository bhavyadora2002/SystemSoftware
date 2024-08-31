/*
============================================================================
Name : 28.c
Author : Dora Bhavya Rishitha
Description : 28. Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sched.h>
int main(){
	printf("Minimum real time priority for Round Robin is %d\n",sched_get_priority_min(SCHED_RR));
	printf("Maximum real time priority for Round Robin is %d\n",sched_get_priority_max(SCHED_RR));
	printf("Minimum real time priority for FIFO is %d\n",sched_get_priority_min(SCHED_FIFO));
        printf("Maximum real time priority for FIFO is %d\n",sched_get_priority_max(SCHED_FIFO));
        printf("Minimum real time priority for others is %d\n",sched_get_priority_min(SCHED_OTHER));
        printf("Maximum real time priority for others is %d\n",sched_get_priority_max(SCHED_OTHER));
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 28.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Minimum real time priority for Round Robin is 1
Maximum real time priority for Round Robin is 99
Minimum real time priority for FIFO is 1
Maximum real time priority for FIFO is 99
Minimum real time priority for others is 0
Maximum real time priority for others is 0
============================================================================
*/
	
