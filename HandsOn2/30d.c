/*
============================================================================
Name : 30b.c
Author : Dora Bhavya Rishitha
Description :30. Write a program to create a shared memory.
d. remove the shared memory
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
    char* str = (char*)shmat(id,(void*)0,SHM_RDONLY);
    if(str == (char *)-1){
        perror("Shared Memory not created");
        exit(0);
    }
    printf("Enter to delete shared Memory\n");
    getchar();
    shmctl(id,IPC_RMID,NULL);   
    printf("Trying to access shared memory after deleting\n");
    printf("%s",str);
    return 0;
}
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 30d.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Key generated is 17108538
Enter to delete shared Memory

Trying to access shared memory after detaching
SharedMemory
============================================================================
*/