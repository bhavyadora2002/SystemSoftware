/*
============================================================================
Name : 10.c
Author : Dora Bhavya Rishitha
Description :10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFF_SIZE 1024
int main(){
        int fd = open("inputFile10.txt",O_RDWR);
	int fd1 = open("outputfile10.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd == -1 || fd1 == -1)
		perror("ERROR");
        char buffer[BUFF_SIZE];
        read(fd,buffer,10);
        write(fd1,buffer,10);
        int l = lseek(fd1,10,SEEK_CUR);
        printf("Return value of lseek is %d\n",l);
        read(fd,buffer,10);
        write(fd1,buffer,10);
        close(fd);
	close(fd1);
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 10.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Return value of lseek is 20
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat inputFile10.txt
abcd efgh ijkl mnop qrst uvwx yz 1234 5678 910 ABCD EFGH IJKL MNOP QRST UVWX YZ
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat outputfile10.txt
abcd efgh ijkl mnop bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ od -c outputfile10.txt
0000000   a   b   c   d       e   f   g   h      \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   i   j   k   l       m   n   o   p
0000036
============================================================================
*/
