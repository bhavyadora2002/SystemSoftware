/*
============================================================================
Name : 28.c
Author : Dora Bhavya Rishitha
Description :28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <time.h>

int main(){
    int k = ftok(".",1);
    if(k==-1){
        perror("Error getting key for IPC");
        exit(0);
    }
    int id = msgget(k,0666|IPC_CREAT);
    if(id == -1){
        perror("Error creating Message Queue");
        exit(0);
    }
    struct msqid_ds buf;
    msgctl(id, IPC_STAT, &buf);
    
    struct ipc_perm msg_perm = buf.msg_perm;  
    printf("current access permission is %d\n", msg_perm.mode);
    buf.msg_perm.mode = 0776;

    msgctl(id,IPC_SET,&buf);
    
    struct msqid_ds cbuf;
    msgctl(id,IPC_STAT,&cbuf);
    struct ipc_perm cmsg_perm = cbuf.msg_perm;
    printf("changed access permission is %d\n",cmsg_perm.mode);
    return 0;
}
    
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 28.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
current access permission is 438
changed access permission is 510
============================================================================
*/