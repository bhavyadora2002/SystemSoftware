/*
============================================================================
Name : 18.c
Author : Dora Bhavya Rishitha
Description :18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pipe1[2];
    int pipe2[2];
    int a;
    int b; 
    if(pipe(pipe1) == -1){
        perror("Error creating pipe");  
        exit(0);
    }
    if(pipe(pipe2) == -1){
        perror("Error creating pipe");  
        exit(0);
    }
    int f1 = fork();
    if(f1 == -1){
        perror("Error creating child");
        exit(0);
    }
    else if(f1 != 0){
        int f2 = fork();
        if(f2 == 0){
            close(1); //closing stdout
            close(pipe2[0]);
            close(pipe2[1]);
            close(pipe1[0]); //child1 doesn't read
            dup2(pipe1[1],1); //reassign stdout to write end of pipe1
            close(pipe1[1]);
            execlp("ls", "ls", "-l", (char *)NULL);
        }
        else{
            close(0);
            close(1);
            close(pipe1[1]);
            close(pipe2[0]);
            dup2(pipe1[0],0);
            dup2(pipe2[1],1);
            close(pipe1[0]);
            close(pipe2[1]);
            execlp("grep", "grep", "^d", (char *)NULL);
        }
    }
    else{
            close(0); //closing stdout
            close(pipe1[0]);
            close(pipe1[1]);
            close(pipe2[1]); //parent doesn't read
            dup2(pipe2[0],0); //reassign stdout to w
            close(pipe2[0]);
            execlp("wc", "wc", (char *)NULL);
    }
    return 0;    
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 18.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
      0       0       0
==========================================
*/