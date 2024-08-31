/*
============================================================================
Name : 23.c
Author : Dora Bhavya Rishitha
Description :23. Write a program to create a Zombie state of the running program.
Date :29th August,2024
===========================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
        int t = fork();
        if(t == -1)
        {
                printf("Cannot create child process\n");
        }else if(t==0){
                printf("In CHILD Process\n");
                printf("Parent Process ID:%d\n",getppid());
                printf("Child Process ID:%d\n",getpid());
        }else{
		getchar();
                printf("In CHILD Process\n");
                printf("Parent Process ID:%d\n",getppid());
                printf("Child Process ID:%d\n",getpid());
        }
        return 0;
}
/*
OUTPUT:
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 23.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
In CHILD Process
Parent Process ID:52440
Child Process ID:52441

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ more /proc/52441/status
Name:	a.out
State:	Z (zombie)
Tgid:	52441
Ngid:	0
Pid:	52441
PPid:	52440
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	0
Groups:	4 24 27 30 46 100 114 1000
NStgid:	52441
NSpid:	52441
NSpgid:	52440
NSsid:	51009
Kthread:	0
Threads:	1
SigQ:	2/62167
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	3fff
--More--
*/

