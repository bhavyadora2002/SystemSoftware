
/*
============================================================================
Name : 13b.c
Author : Hymavathi Jayaramappa
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 13th sept, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
void main()
{
    pid_t pid;
    printf("Enter process id\n");
    scanf("%d",&pid);
    int status = kill(pid, SIGSTOP);
    if (status == -1)
    {
        perror("Error while sending kill signal!");
    }
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 13b.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Enter process id
 75095

*/