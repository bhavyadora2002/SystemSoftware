/*
============================================================================
Name : 32c.c
Author : Dora Bhavya Rishitha
Description :c. protect multiple pseudo resources ( may be two) using counting semaphore
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
    semun sem;
    key_t key = ftok(".", 's');
    int semid = semget(key, 1, 0);
    if(semid == -1)
        perror("Error creating semaphore");
    else{
        struct sembuf sem_op = {0,-1,0};

        printf("Before Critical section\n");
        semop(semid,&sem_op,1);
        printf("Inside critical section\n");
        printf("Enter to exit\n");
        getchar();
        sem_op.sem_op = 1;
        semop(semid, &sem_op, 1);
        printf("Out of critical section\n");
    }
    return 0;
}
/*
OUTPUT:My semaphore value is 2 
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 32c.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Before Critical section
Inside critical section
Enter to exit

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Before Critical section
Inside critical section
Enter to exit

TERMINAL 3:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Before Critical section


*/