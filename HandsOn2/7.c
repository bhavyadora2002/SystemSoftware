/*
============================================================================
Name : 7.c
Author : Dora Bhavya Rishitha
Description :7. Write a simple program to print the created thread ids.
Date: 14th Sep, 2024.
============================================================================
*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void* subroutine(){
    printf("Thread id of current thread is %lu\n",pthread_self());
    pthread_exit(NULL);

}
void main(){
    pthread_t p1,p2,p3;
    if(pthread_create(&p1,NULL,&subroutine,NULL)){
        perror("ERROR:");
        exit(0);
    }
    if(pthread_create(&p2,NULL,&subroutine,NULL)){
        perror("ERROR:");
        exit(0);
    }
    if(pthread_create(&p3,NULL,&subroutine,NULL)){
        perror("ERROR:");
        exit(0);
    }
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ gcc 7.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/HandsOn2$ ./a.out
Thread id of current thread is 134401868433088
Thread id of current thread is 134401847461568
Thread id of current thread is 134401857947328
============================================================================
*/