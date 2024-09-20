/*
============================================================================
Name : 30a.c
Author : Dora Bhavya Rishitha
Description :30. Write a program to create a shared memory.
a. write some data to the shared memory
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

struct msgbuf {
    long mtype;
	char mtext [1];
}; 
int main(){
    int k = ftok(".",1);
    if(k==-1){
        perror("Error getting key for IPC");
        exit(0);
    }
    printf("Key generated is %d\n",k);
    int id = shmget(k,1024,0666|IPC_CREAT);
    if(id == -1){
        perror("Error creating shared memory");
        exit(0);
    }
    char* str = (char*)shmat(id,(void*)0,0);
    printf("Enter data to shared memory\n");
    scanf("%s",str);
    printf("Data entered is %s",str);
    shmdt(str);
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 30a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Key generated is 17108538
Enter data to shared memory
SharedMemory
Data entered is SharedMemory
============================================================================
*/