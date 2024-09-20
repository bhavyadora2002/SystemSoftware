/*
============================================================================
Name : 29.c
Author : Dora Bhavya Rishitha
Description :29. Write a program to remove the message queue.
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
    if(msgctl(id, IPC_RMID, NULL) == -1){
        perror("Error Removinf Queue");
        exit(0);
    }
    return 0;
}
    
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01050e3a 0          bhavya     776        0            0           
0x02050e3a 1          bhavya     666        0            0           

bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 29.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x02050e3a 1          bhavya     666        0            0  
============================================================================
*/