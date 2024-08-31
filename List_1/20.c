
/*
============================================================================
Name : 20.c
Author : Dora Bhavya Rishitha
Description :20. Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	while(1){
	}
	return 0;
}
/*
=============running the process by assigning 10 as nice value================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ nice -n 10 ./a.out &
[1] 23560

================checking nice value of running process=========================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ top -p 23560
top - 15:38:41 up  5:52,  1 user,  load average: 2.42, 2.49, 2.64
Tasks:   1 total,   1 running,   0 sleeping,   0 stopped,   0 zombie
%Cpu(s): 10.2 us,  1.4 sy,  7.2 ni, 81.0 id,  0.0 wa,  0.0 hi,  0.1 si,  0.0 st 
MiB Mem :  15611.4 total,   5150.2 free,   6623.9 used,   5814.4 buff/cache     
MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.   8987.5 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                                          
  23560 bhavya    30  10    2548   1024   1024 R  99.7   0.0   0:36.43 a.out     

==================modifying nice value of running process========================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ sudo renice -n 5 -p 23560
[sudo] password for bhavya: 
23560 (process ID) old priority 10, new priority 5

===================checking the modified nice value ot process====================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ top -p 23560
top - 15:38:41 up  5:52,  1 user,  load average: 2.42, 2.49, 2.64
Tasks:   1 total,   1 running,   0 sleeping,   0 stopped,   0 zombie
%Cpu(s): 10.2 us,  1.4 sy,  7.2 ni, 81.0 id,  0.0 wa,  0.0 hi,  0.1 si,  0.0 st 
MiB Mem :  15611.4 total,   5150.2 free,   6623.9 used,   5814.4 buff/cache     
MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.   8987.5 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                                          
  23560 bhavya    30  10    2548   1024   1024 R  99.7   0.0   0:36.43 a.out                                                            

*/
