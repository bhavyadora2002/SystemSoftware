/*
============================================================================
Name : 26a.c
Author : Dora Bhavya Rishitha
Description :9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/sysmacros.h>

int main(int argc, char *argv[]){
	struct stat sb;
	if(argc!=2){
		fprintf(stderr,"Invalid number of arguments");
		return 0;
	}
	const char *file = argv[1];
	if(stat(file,&sb) == -1){
		perror("Unable to retrieve info");
		return 0;
	}
	printf("File name is %s\n",file);
	printf("inode number is %ld\n", (long) sb.st_ino);
	printf("Hard Link count is %ld\n", (long) sb.st_nlink);
	printf("UID is %d\n",  sb.st_uid);
	printf("GID is %d\n",  sb.st_gid);
	printf("File Size is %ld bytes\n",(long) sb.st_size);
	printf("Block size is %ld bytes\n",(long) sb.st_blksize);
	printf("Blocks allocated are %ld\n",(long) sb.st_blocks);
	printf("Last status change is %s", ctime(&sb.st_ctime));
        printf("Last file modification is %s", ctime(&sb.st_mtime));
	return 0;
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 9.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out readFile6.txt 
File name is readFile6.txt
inode number is 2373676
Hard Link count is 1
UID is 1000
GID is 1000
File Size is 86 bytes
Block size is 4096 bytes
Blocks allocated are 8
Last status change is Wed Aug 28 22:56:15 2024
Last file access is Wed Aug 28 22:56:21 2024
Last file modification is Wed Aug 28 22:56:15 2024
============================================================================
*/

