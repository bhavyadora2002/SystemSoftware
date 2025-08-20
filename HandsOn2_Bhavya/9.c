/*
============================================================================
Name : 9.c
Author : Dora Bhavya Rishitha
Description :9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
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

    if(signal(SIGINT,SIG_IGN) ==  SIG_ERR){
        perror("Error while assigning signal handler");
    }else{
        sleep(5);
    }
    if(signal(SIGINT,SIG_DFL) ==  SIG_ERR){
        perror("Error while assigning signal handler");
    }else{
        while(1);
    }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 9.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
^C^C^C^C^C^C^C^C^C^C^C^C^C
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ^C
Here ^C didn't work for some time as I ignored SIGINT then when I set it to default,it is terminated
============================================================================
*/