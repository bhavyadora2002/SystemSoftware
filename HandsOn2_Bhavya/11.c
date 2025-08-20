/*
============================================================================
Name : 11.c
Author : Dora Bhavya Rishitha
Description :11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(){
    struct sigaction s;
    s.sa_handler = SIG_IGN;
    s.sa_flags = 0;
    if(sigaction(SIGINT,&s,NULL) == -1){
        perror("Error assigning signal handler");
    }else{
        sleep(5);
    }
    s.sa_handler = SIG_DFL;
    if(sigaction(SIGINT,&s,NULL) == -1){
        perror("Error assigning signal handler");
    }else{
        while(1);
    }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 11.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
^C^C^C^C^C^C^C^C^C^C^C^C^C^C^C
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ 
============================================================================
*/