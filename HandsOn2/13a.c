/*
============================================================================
Name : 13a.c
Author : Dora Bhavya Rishitha
Description :13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void handler(int sig){
    printf("Received signal is %d\n",sig);
    exit(0);
}
int main(){
    if(signal(SIGSTOP,handler)==SIG_ERR){
        perror("Error sending signal");
    }else{
        sleep(5);
    }
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 13a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Error sending signal: Invalid argument

Cannot catch the signal.We cannot catch SIGKILL and SIGSTOP using signal system call
============================================================================
*/