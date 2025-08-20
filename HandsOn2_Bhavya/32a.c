
/*
============================================================================
Name : 32a.c
Author : Dora Bhavya Rishitha
Description :32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef union semun
{
    int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
    struct semid_ds *buf;      // Data structure describing a set of semaphores.
    unsigned short int *array; // array for GETALL, SETALL
    struct seminfo *__buf;     // Buffer for IPC_INFO
} semun;
int main(int argc, char *argv[])
{
    struct{
      int ticketno;
    }data;
    data.ticketno= 1;

    semun sem;
    key_t key = ftok(".", 4);
    int semid = semget(key, 1, 0); // if semaphore already exists
    if(semid == -1){
        int semid = semget(key, 1, IPC_CREAT | 0744);
        sem.val = 1;
        printf("Binary semaphore creation done\n");
        semctl(semid, 0, SETVAL, sem); 
    }

    struct sembuf sem_op; 
    sem_op.sem_flg = 0;
    printf("Entering critical zone\n");

    sem_op.sem_op = -1;
    semop(semid, &sem_op, 1);

    int fd = open("./ticketnum.txt", O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file!");
        return 0;
    }
    write(fd,&data,sizeof(data));
    printf("Inside Critical section\n");
    printf("Enter to proceed\n");
    getchar();

    fd = open("./ticketnum.txt", O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file!");
        return 0;
    }
    read(fd,&data, sizeof(data));
    data.ticketno++;
    lseek(fd, 0, SEEK_SET); 
    write(fd, &data, sizeof(data));
    printf("Ticket number is : %d\t \n", data.ticketno);

    printf("Out of critical section\n");
    sem_op.sem_op = 1;
    semop(semid, &sem_op, 1);
    return 0;
}
/*
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 32a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Entering critical zone
Inside Critical section
Enter to proceed

Ticket number is : 2	 
Out of critical section

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 32a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Entering critical zone
Inside Critical section
Enter to proceed

Ticket number is : 3	 
Out of critical section
*/