#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char response[1024];


void add_employee(int sd){
    char unamenew[1024];
    char passnew[1024];
    char idnew[1024];
    int fd_e = open("employee.txt",O_RDWR|O_CREAT,0744);

    char msg[] = "Enter Username: ";
    write(sd, msg, sizeof(msg));
    read(sd, unamenew, sizeof(unamenew));
    printf("Username Received is %s\n",unamenew);

    char pass_msg[] = "Enter Password: ";
    write(sd, pass_msg, sizeof(pass_msg));
    read(sd, passnew, sizeof(passnew));
    printf("Password Received is %s\n",passnew);

    char id_msg[] = "Enter ID: ";
    write(sd, id_msg, sizeof(id_msg));
    read(sd, idnew, sizeof(idnew));
    printf("ID Received is %s\n",idnew);
    int id = atoi(idnew);
    e.id =id;
    strcpy(e.username,unamenew);
    strcpy(e.password,passnew);
    e.flag = 0;
    lseek(fd_e,0,SEEK_END);
    int i = write(fd_e,&e,sizeof(e));
	close(fd_e);
    if(i>0)
    strcpy(response,"Added Employee\n");
    else
    strcpy(response,"Unable to add employee");
}

void modify_customer(int sd){
    char unamenew[1024];
    char unamenew1[1024];
    char msg[] = "Enter Current Username of Customer: ";
    write(sd, msg, sizeof(msg));
    read(sd, unamenew, sizeof(unamenew));
    printf("Username Received is %s\n",unamenew);  

    char new_msg[] = "Enter New Username of Customer: ";
    write(sd, new_msg, sizeof(new_msg));
    read(sd, unamenew1, sizeof(unamenew1));
    printf("New Username Received is %s\n",unamenew1);

    int fd_c = open("customer.txt", O_RDWR, 0744);
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        if (strcmp(c.username, unamenew) == 0) {
                    strcpy(c.username,unamenew1);
                    lseek(fd_c, -sizeof(c), SEEK_CUR);
                    int by = write(fd_c,&c,sizeof(c));
                    if(by>0){
                    close(fd_c);
                    strcpy(response,"Modified Customer Details\n");
                    return;  
                    }
                }   
            i = read(fd_c, &c, sizeof(c));  
    }      
        strcpy(response,"Error modifying details\n");
        close(fd_c);
}

void modify_employee(int sd){
    char unamenew[1024];
    char unamenew1[1024];
    char msg[] = "Enter Current Username of Employee: ";
    write(sd, msg, sizeof(msg));
    read(sd, unamenew, sizeof(unamenew));
    printf("Username Received is %s\n",unamenew);  

    char new_msg[] = "Enter New Username of Employee: ";
    write(sd, new_msg, sizeof(new_msg));
    read(sd, unamenew1, sizeof(unamenew1));
    printf("New Username Received is %s\n",unamenew1);

    int fd_e = open("employee.txt", O_RDWR, 0744);
    int i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", e.id, e.username, e.password, e.flag);
        if (strcmp(e.username, unamenew) == 0) {
                    strcpy(e.username,unamenew1);
                    lseek(fd_e, -sizeof(e), SEEK_CUR);
                    int by = write(fd_e,&e,sizeof(e));
                    if(by>0){
                    close(fd_e);
                    strcpy(response,"Modified Employee Details\n");
                    return;  
                    }
                } 
            i = read(fd_e, &e, sizeof(e));   
        }
        strcpy(response,"Error modifying details\n");
        close(fd_e);
}

int change_password_ad(int sd,char *uname){
    char new_pass[1024];
    int fd_c = open("admin.txt", O_RDWR, 0744);
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        if (strcmp(c.username, uname) == 0) {
                if (c.flag == 1) {
                    char msg[] = "Enter New Password: ";
                    write(sd, msg, sizeof(msg));
                    read(sd, new_pass, sizeof(new_pass));
                    printf("New Password is %s\n",new_pass);
                    strcpy(c.password,new_pass);
                    lseek(fd_c, -sizeof(c), SEEK_CUR);  
                    write(fd_c, &c, sizeof(c)); 
                    close(fd_c);
                    strcpy(response, "Password Changed\n");
                    return 1; 
                } 
            }   
            i = read(fd_c, &c, sizeof(c));        
        }
        strcpy(response, "Password not changed\n");
        close(fd_c);
}