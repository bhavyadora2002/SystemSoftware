
/*
============================================================================
Name : 32b.c
Author : Dora Bhavya Rishitha
Description :b. protect shared memory from concurrent write access
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

typedef union semun
{
    int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
    struct semid_ds *buf;      // Data structure describing a set of semaphores.
    unsigned short int *array; // array for GETALL, SETALL
    struct seminfo *__buf;     // Buffer for IPC_INFO
} semun;

int main()
{
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
  
    semun sem;
    key_t key = ftok(".", 4);
    int semid = semget(key, 1, 0);
    if(semid == -1)
        perror("Error creating semaphore");
    else{
        struct sembuf sem_op = {0,-1,0};

        printf("Before Critical section\n");
        semop(semid,&sem_op,1);
        printf("Inside critical section\n");
        printf("Enter the data: \n");
        scanf(" %[^\n]",str);
        printf("Data in shared memory :%s\n",str);
        printf("Enter to exit\n");
        getchar();
        sem_op.sem_op = 1;
        semop(semid, &sem_op, 1);
        printf("Out of critical section\n");
    }
    return 0;
}
/*
OUTPUT:
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./32.out
Key generated is 17108538
Before Critical section
Inside critical section
Enter the data: 
testData
Data in shared memory :testData
Enter to exit
Out of critical section

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 32b.c 
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Key generated is 17108538
Before Critical section
Inside critical section
Enter the data: 

*/