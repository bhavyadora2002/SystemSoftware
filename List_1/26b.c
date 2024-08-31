/*
============================================================================
Name : 26b.c
Author : Dora Bhavya Rishitha
Description :Write a program to execute an executable program.
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    const char *cmd = "~/Desktop/List_1/test26b.out Hello";
    t = system(cmd);
    return 0;
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc test26b.c -o test26b.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 26b.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
This is test file for 26b
Argument passed is Hello
============================================================================
*/

