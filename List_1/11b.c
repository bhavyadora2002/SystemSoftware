/*
============================================================================
Name : 11b.c
Author : Dora Bhavya Rishitha
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
	char buffer[100];
        int fd = open("dupliateFile11.txt",O_CREAT|O_RDWR,0644);
        if(fd == -1)
                perror("ERROR:");
	int fd1;
       	printf("Enter number that you want to assign to new file descriptor");
	scanf("%d",&fd1);
        int fd2 = dup2(fd,fd1);
	snprintf(buffer, sizeof(buffer), "Writing using first file descriptor %d\n", fd);
        write(fd,buffer,strlen(buffer));
	snprintf(buffer,sizeof(buffer), "Writing using secoond file descriptor %d\n", fd2);
        write(fd2,buffer,strlen(buffer));
        close(fd);
	close(fd2);
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 11b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Enter number that you want to assign to new file descriptor9
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat dupliateFile11.txt
Writing using first file descriptor 3
Writing using secoond file descriptor 9
============================================================================
*/


