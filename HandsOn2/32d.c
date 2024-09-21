/*
============================================================================
Name : 32d.c
Author : Dora Bhavya Rishitha
Description :d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
typedef union semun
{
    int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
    struct semid_ds *buf;      // Data structure describing a set of semaphores.
    unsigned short int *array; // array for GETALL, SETALL
} semun;

int main()
{

    semun sem;
    key_t key = ftok(".", 4);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    sem.val = 1;
    if(semid == -1){
        perror("Error creating semaphore");
    }
    else{
    semctl(semid, 0, SETVAL, sem); 
    printf("Deleting semaphore");
    semctl(semid, 0, IPC_RMID, sem); 
    }
}

/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x06050e3a 1          bhavya     744        1         
0x73050e3a 2          bhavya     744        1         
0x04050e3a 3          bhavya     744        1         

bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 32d.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Deleting semaphorebhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x06050e3a 1          bhavya     744        1         
0x73050e3a 2          bhavya     744        1
*/