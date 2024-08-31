/*
============================================================================
Name : 16b.c
Author : Dora Bhavya Rishitha
Description : 16. Write a program to perform mandatory locking.
                b. Implement read lock
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
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
        printf("Before Locking with read lock\n");
        fcntl(fd,F_SETLKW,&lock);
        printf("Entered critical section\n");
        printf("Press enter to unlock:");
        getchar();
        lock.l_type = F_UNLCK;
        fcntl(fd,F_SETLK,&lock);
        printf("Unlocked");
}
/*
============================================================================
OUTPUT:
Terminal 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 16b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with read lock
Entered critical section
Press enter to unlock:

Terminal 2:Trying to enter reader process to critical section
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with read lock
Entered critical section
Press enter to unlock:

Terminal 3:Trying to enter writer process to critical section
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock

============================================================================
AFTER PRESSING ENTER KEY IN BOTH TERMINAL 1 AND TERMINAL 2
Terminal 3:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Before Locking with write lock
Entered critical section
Press enter to unlock:


============================================================================
*/


