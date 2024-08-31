/*
============================================================================
Name : 18.c
Author : Dora Bhavya Rishitha
Description :18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
struct{
	int trainNumber;
	int ticketCount;
}data;
int main(){
	int tno;
	int fd = open("ticketBooking.txt",O_RDWR);
	printf("Select train number between 1 and 3:\n");
	scanf("%d",&tno);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (tno-1)*sizeof(data);
	lock.l_len = sizeof(data);
	lock.l_pid = getpid();

	printf("Before entering critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	lseek(fd,(tno-1)*sizeof(data),SEEK_SET);
	read(fd,&data,sizeof(data));
	printf("Ticket Number is %d\n",data.ticketCount);
	data.ticketCount++;
	lseek(fd,-1*sizeof(data),SEEK_CUR);
	write(fd,&data,sizeof(data));
	printf("To confirm,Press Enter\n");
	getchar();
	getchar();
	lseek(fd,-1*sizeof(data),SEEK_CUR);
	read(fd,&data,sizeof(data));
	printf("Ticket Number is %d\n",data.ticketCount);
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Booked");
}
	
/*
===============================================================================
OUTPUT:
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 18b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Select train number between 1 and 3:
1
Before entering critical section
Ticket Number is 0
To confirm,Press Enter


TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 18b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Select train number between 1 and 3:
1
Before entering critical section

TERMINAL 3:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 18b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Select train number between 1 and 3:
2
Before entering critical section
Ticket Number is 0
To confirm,Press Enter

Ticket Number is 1
Booked
================================================================================
AFTER PRESSING ENTER IN TERMINAL 1
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Select train number between 1 and 3:
1
Before entering critical section
Ticket Number is 0
To confirm,Press Enter

Ticket Number is 1
Booked

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Select train number between 1 and 3:
1
Before entering critical section
Ticket Number is 1
To confirm,Press Enter

================================================================================
*/
