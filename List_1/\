/*
============================================================================
Name : 4b.c
Author : Dora Bhavya Rishitha
Description :4. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 29th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
int main(){
        const char *existingfile = "creatFile_3.txt";
        const char *newfile = "creatFile_4.txt";
        int fd1 = open(existingfile,O_CREAT|O_EXCL);
        if(fd1 == -1){
        perror("Error:");
        }else{
        printf("File descriptor number of created file is %d",fd1);
        }
        mode_t mode = 0666;
        int fd2 =  open(newfile,O_CREAT|O_EXCL,mode);
        if(fd2 == -1){
        perror("Error:");
        }else{
        printf("FIle descriptor number  of created file is %d",fd2);
        }
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 4b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Error:: File exists
FIle descriptor number  of created file is 3
============================================================================
*/
