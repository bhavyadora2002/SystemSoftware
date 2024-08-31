/*
============================================================================
Name : 18.c
Author : Dora Bhavya Rishitha
Description :18. Write a program to perform Record locking.
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th Aug, 2024.
============================================================================
*/
#include <sys/file.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int fd;
    struct ticketData{
        int trainNum;
        int ticketCount;
    }td;
    fd = open("ticketBooking.txt",O_RDWR);

    int train_num;
    printf("Enter train number you want to check : ");
    scanf("%d",&train_num);

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = sizeof(td)*(train_num-1);
    lock.l_len = sizeof(td);
    lock.l_pid = getpid();
    printf("Before locking file in READ lock...\n");
    fcntl(fd, F_SETLKW, &lock);   
    
    getchar();
    lseek(fd, sizeof(td)*(train_num-1), SEEK_SET);
    read(fd, &td, sizeof(td));
    printf("Train Number is : %d\n",td.trainNum);
    printf("Ticket Count is : %d\n",td.ticketCount);
    printf("Press Enter to unlock.");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd); 

    return 0;
}