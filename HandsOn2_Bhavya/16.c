/*
============================================================================
Name : 16.c
Author : Dora Bhavya Rishitha
Description :16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 14th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int p1[2];//parent to child
    int p2[2];//child to parent
    int a;
    if(pipe(p1) == -1){
        perror("Error creating pipe");  
        exit(0);
    }
    if(pipe(p2) == -1){
        perror("Error creating pipe");  
        exit(0);
    }
   
    int f = fork();
    if(f == -1){
        perror("Error creating child");
        exit(0);
    }
    else if(f != 0){
        close(p1[0]);
        close(p2[1]);
        printf("\nEnter a:");
        scanf("%d",&a);
        if(write(p1[1],&a,sizeof(int)) == -1){
            perror("Error Writing");
            exit(0);
        }
        printf("Value of a written in parent process is %d\n",a);
        if(read(p2[0],&a,sizeof(int)) == -1){
            perror("Error Writing");
            exit(0);
        }
        printf("Value of a read in parent process is %d\n",a);
        close(p2[0]);
        close(p1[1]);
    }else{
        sleep(1);
        close(p2[0]);
        close(p1[1]);
        if(read(p1[0],&a,sizeof(int)) == -1){
            perror("Error Writing");
            exit(0);
        }
        printf("Value of a read in child process is %d\n",a);
        printf("\nEnter b:");
        scanf("%d",&a);
        if(write(p2[1],&a,sizeof(int)) == -1){
            perror("Error Writing");
            exit(0);
        }   
        printf("Value of a written in child process is %d\n",a);
        
        close(p1[0]);
        close(p2[1]);
    }
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 16.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Enter a:4
Value of a written in parent process is 4
Value of a read in child process is 4

Enter b:6
Value of a written in child process is 6
Value of a read in parent process is 6
============================================================================
*/