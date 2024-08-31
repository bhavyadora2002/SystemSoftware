/*
============================================================================
Name : 26a.c
Author : Dora Bhavya Rishitha
Description :Write a program to execute an executable program.
a. use some executable program
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    const char *cmd = "~/Desktop/List_1/test26.out";
    t = system(cmd);
    return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc test26.c -o test26.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 26a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Hello..This is test file for 26a
============================================================================
*/

