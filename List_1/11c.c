/*
============================================================================
Name : 11c.c
Author : Dora Bhavya Rishitha
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
c. use fcntl
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
        char buffer[100];
        int fd = open("dupliateFile11.txt",O_CREAT|O_RDWR,0644);
        if(fd == -1)
                perror("ERROR:");
        int fd1 = fcntl(fd,F_DUPFD);
        snprintf(buffer, sizeof(buffer), "Writing using first file descriptor %d\n", fd);
        write(fd,buffer,strlen(buffer));
        snprintf(buffer,sizeof(buffer), "Writing using second file descriptor %d\n", fd1);
        write(fd1,buffer,strlen(buffer));
        close(fd);
        close(fd1);
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 11c.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat dupliateFile11.txt
Writing using first file descriptor 3
Writing using second file descriptor 4
============================================================================
*/
