#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char response[1024];


void add_customer(int sd){
    char unamenew[1024];
    char passnew[1024];
    char idnew[1024];
    int fd_c = open("customer.txt",O_RDWR|O_CREAT,0744);

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
    c.id =id;
    strcpy(c.username,unamenew);
    strcpy(c.password,passnew);
    c.flag = 0;
    c.active = 1;
    lseek(fd_c,0,SEEK_END);
    int i = write(fd_c,&c,sizeof(c));
	close(fd_c);
    if(i>0)
    strcpy(response,"Added Customer\n");
    else
    strcpy(response,"Unable to add customer");
}



int change_password_emp(int sd,char *uname){
    char new_pass[1024];
    int fd_c = open("employee.txt", O_RDWR, 0744);
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
void view_loans(int sd, char *uname) {
    char response[4096];  
    char temp[512];  
    int fd_ac = open("account.txt", O_RDONLY, 0744);

    if (fd_ac == -1) {
        strcpy(response, "Error opening account file\n");
        send(sd, response, strlen(response) + 1, 0);
        return;
    }

    response[0] = '\0';  
    int found_any = 0;

    while (read(fd_ac, &ac, sizeof(ac)) > 0) {
        if (strcmp(ac.eusername, uname) == 0) {  
            snprintf(temp, sizeof(temp), "Customer ID: %d, Username: %s, Loan: %d, Status: %s\n",
                     ac.id, ac.username, ac.loan, ac.status);
            strncat(response, temp, sizeof(response) - strlen(response) - 1);  
            found_any = 1;
        }
    }

    if (!found_any) {
        strcpy(response, "No customers found for this employee.\n");
    }

    send(sd, response, strlen(response) + 1, 0);  
    close(fd_ac);
}

void aporrej_loan(int sd,char *uname){
    char c_id[1024];
    char stat[1024];
    int found = 0;
    char msg[] = "Enter Customer Id: ";
    write(sd, msg, sizeof(msg));
    read(sd, c_id, sizeof(c_id));
    printf("Id Received is %s\n",c_id);
    int cid = atoi(c_id);

    char pass_msg[] = "Enter decision(Approve/Reject): ";
    write(sd, pass_msg, sizeof(pass_msg));
    read(sd, stat, sizeof(stat));
    printf("Decision Received is %s\n",stat);

    int fd_ac = open("account.txt", O_RDWR, 0744);

    if (fd_ac == -1) {
        strcpy(response, "Error opening account file\n");
        send(sd, response, strlen(response) + 1, 0);
        return;
    }
    lseek(fd_ac, 0, SEEK_SET); 
    while (read(fd_ac, &ac, sizeof(ac)) > 0) {
        if (ac.id == cid) {
            found = 1;
            if (strcmp(ac.eusername, uname) != 0) {
                strcpy(response, "You don't have permissions to modify this customer.\n");
                break;
            }
            if (strcmp(ac.status, "Pending") != 0) {
                strcpy(response, "This customer loan status is not pending.\n");
                break;
            }
            if (strcmp(stat, "Approve") == 0) {
                
                strcpy(ac.status, "Approved");
            } else if (strcmp(stat, "Reject") == 0) {
                strcpy(ac.status, "Rejected");
            }

            lseek(fd_ac, -sizeof(ac), SEEK_CUR);
            write(fd_ac, &ac, sizeof(ac));

            snprintf(response, sizeof(response), "Customer %d loan has been %s.\n", cid, ac.status);
            break;
        }
        if (!found) {
        strcpy(response, "Error: Customer not found.\n");  // Customer ID was not found in the file
    }
    }

    close(fd_ac);
}
void process_loan(int sd,char *uname){
    char c_id[1024];
    char msg[] = "Enter Customer Id: ";
    write(sd, msg, sizeof(msg));
    read(sd, c_id, sizeof(c_id));
    printf("Id Received is %s\n",c_id);
    int cid = atoi(c_id);

    int fd = open("account.txt", O_RDWR, 0744);

    if (fd == -1) {
        strcpy(response, "Error opening account file\n");
        return;
    }
    lseek(fd,(cid-1)*sizeof(ac),SEEK_SET);
    if (strcmp(ac.eusername, uname) != 0) {
                strcpy(response, "You don't have permissions for this customer.\n");
                return;
    }
    if (strcmp(ac.status, "Approved") != 0) {
                strcpy(response, "This customer loan status is not aproved.\n");
                return;
    }
    struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (cid-1)*sizeof(ac);
	lock.l_len = sizeof(ac);
	lock.l_pid = getpid();
    fcntl(fd,F_SETLKW,&lock);
	lseek(fd,(cid-1)*sizeof(ac),SEEK_SET);
	read(fd,&ac,sizeof(ac));
    ac.balance += ac.loan;  
    int offset = strlen(ac.transactions); 
    snprintf(ac.transactions + offset, sizeof(ac.transactions) - offset, "Loan credited %d", ac.loan);
    ac.transaction_count++;
    strcpy(ac.status,"Credited");
    lseek(fd, -sizeof(ac), SEEK_CUR);  
    write(fd, &ac, sizeof(ac));  
    lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
    printf("Sent success\n");
    strcpy(response,"Loan credited successfully\n");
    return;
}