/*
============================================================================
Name : 15.c
Author : Dora Bhavya Rishitha
Description :15. Write a simple program to send some data from parent to the child process.
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
    printf("\nEnter a number:");
    scanf("%d",&a);
    int f = fork();
    if(f == -1){
        perror("Error creating child");
        exit(0);
    }
    else if(f != 0){
        close(fd[0]);
        if(write(fd[1],&a,sizeof(int)) == -1){
            perror("Error Writing");
            exit(0);
        }
        printf("\nData wrote in parent process is %d",a);
        close(fd[1]);
    }else{
        close(fd[1]);
        if(read(fd[0],&b,sizeof(int)) == -1){
            perror("Error Reading");
            exit(0);
        }
        printf("\nData read in child process is %d",b);
        
        close(fd[0]);
    }
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 15.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out

Enter a number:46

Data wrote in parent process is 46
Data read in child process is 46
============================================================================
*/