/*
============================================================================
Name : 14.c
Author : Dora Bhavya Rishitha
Description :Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc,char *argv[]){
	struct stat sb;
	if(argc!=2) {
               fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

	if(lstat(argv[1],&sb)== -1){
		perror("ERROR:");
		return 0;
	}
         switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
	}
}
/*
 ============================================================================
 * OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 14.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out symlink.txt 
symlink
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out fifo
fifofile.txt   fifomknod.txt  
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out fifofile.txt 
FIFO/pipe
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out link.txt
regular file
============================================================================
*/


