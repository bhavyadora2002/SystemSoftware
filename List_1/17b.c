/*
============================================================================
Name : 17b.c
Author : Dora Bhavya Rishitha
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
	struct{
		int ticketno;
	}data;
	struct flock lock;
	int fd = open("TicketList",O_RDWR);
	read(fd,&data,sizeof(data));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical section\n");
	printf("Ticket number is %d\n",data.ticketno);
	data.ticketno++;
	lseek(fd,0L,SEEK_SET);
	write(fd,&data,sizeof(data));
	printf("Press enter to unlock\n");
	getchar();
	lock.l_type = F_UNLCK;
	printf("Unlocked\n");
	fcntl(fd,F_SETLK,&lock);
	printf("Finish");
}
/*
============================================================================
OUTPUT:
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 17b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before entering critical section
Inside critical section
Ticket number is 1
Press enter to unlock

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before entering critical section

============================================================================
AFTER PRESSING ENTER
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before entering critical section
Inside critical section
Ticket number is 1
Press enter to unlock

Unlocked
Finish

TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before entering critical section
Inside critical section
Ticket number is 2
Press enter to unlock
============================================================================
*/
