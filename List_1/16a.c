/*
============================================================================
Name : 16a.c
Author : Dora Bhavya Rishitha
Description : 16. Write a program to perform mandatory locking.
		a. Implement write lock
Date: 28th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	struct flock lock;
	int fd;
	fd = open("inputFile16.txt",O_RDWR|O_CREAT,0644);
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before Locking with write lock\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Entered critical section\n");
	printf("Press enter to unlock:\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Unlocked");
}
/*
============================================================================
OUTPUT:
Terminal 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock
Entered critical section
Press enter to unlock:

Teminal 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 16a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock
============================================================================
AFTER PRESSING ENTER
Terminal 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock
Entered critical section
Press enter to unlock:

Unlocked

Terminal 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock
Entered critical section
Press enter to unlock:


============================================================================
*/
