/*
============================================================================
Name : 5.c
Author : Dora Bhavya Rishitha
Description :5.Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
void main(){
	int count = 1;
	char temp[20];
	mode_t mode = 0666;
	while(1){
	if(count <=5){
	char s[20] = "file";
	sprintf(temp, "%d", count);
	strcat(s,temp);
	strcat(s,".txt"); 
	int fd = open(s,O_CREAT,mode);
	if(fd == -1){
	perror("ERROR:");
	}else{
	printf("File %s created with file descriptor number is %d\n",s,fd);
	}
	count++;
	}
	}

}
	

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out &
[5] 15405
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ File file1.txt created with file descriptor number is 3
File file2.txt created with file descriptor number is 4
File file3.txt created with file descriptor number is 5
File file4.txt created with file descriptor number is 6
File file5.txt created with file descriptor number is 7
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~$ cd /proc/15405/fd/
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:/proc/15405/fd$ ls -l
total 0
lrwx------ 1 bhavya bhavya 64 Aug 28 21:33 0 -> /dev/pts/0
lrwx------ 1 bhavya bhavya 64 Aug 28 21:33 1 -> /dev/pts/0
lrwx------ 1 bhavya bhavya 64 Aug 28 21:33 2 -> /dev/pts/0
lr-x------ 1 bhavya bhavya 64 Aug 28 21:33 3 -> /home/bhavya/Desktop/List_1/file1.txt
lr-x------ 1 bhavya bhavya 64 Aug 28 21:33 4 -> /home/bhavya/Desktop/List_1/file2.txt
lr-x------ 1 bhavya bhavya 64 Aug 28 21:33 5 -> /home/bhavya/Desktop/List_1/file3.txt
lr-x------ 1 bhavya bhavya 64 Aug 28 21:33 6 -> /home/bhavya/Desktop/List_1/file4.txt
lr-x------ 1 bhavya bhavya 64 Aug 28 21:33 7 -> /home/bhavya/Desktop/List_1/file5.txt
============================================================================
*/
