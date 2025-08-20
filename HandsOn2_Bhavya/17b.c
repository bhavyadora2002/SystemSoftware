/*
============================================================================
Name : 17b.c
Author : Dora Bhavya Rishitha
Description :17. Write a program to execute ls -l | wc.
b. use dup2
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    int fd[2];
    int a;
    int b; 
    if(pipe(fd) == -1){
        perror("Error creating pipe");  
        exit(0);
    }
  
    int f = fork();
    if(f == -1){
        perror("Error creating child");
        exit(0);
    }
    else if(f != 0){
        close(1); //closing stdout
        close(fd[0]); //parent doesn't read..So closing read end
        dup2(fd[1],1);// reassign stdout to write end of pipe
        close(fd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
    }else{
        close(0);// closing stdinput
        close(fd[1]);//child doesn't write..So closing write end
        dup2(fd[0],0);// reassign stdin to read end of file
        close(fd[0]);
        execlp("wc", "wc", (char *)NULL);
    }
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 17b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
     28     245    1388
==========================================
*/