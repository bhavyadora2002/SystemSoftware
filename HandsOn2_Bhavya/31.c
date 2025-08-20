/*
============================================================================
Name : 31.c
Author : Dora Bhavya Rishitha
Description :31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
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
    printf("Binary semaphore creation done\n");
    semctl(semid, 0, SETVAL, sem); 
    
    semun sem1;
    key = ftok(".",'s');
    semid = semget(key, 1, IPC_CREAT | 0744);
    sem1.val = 2; 
    printf("counting semaphore created with size %d \n", sem1.val);
    semctl(semid, 0, SETVAL, sem1); 
    return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 31.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Binary semaphore creation done
counting semaphore created with size 2
============================================================================
 */
