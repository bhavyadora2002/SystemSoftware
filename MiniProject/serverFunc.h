
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char response[1024];

char success[1024];

struct cust {
    int id;
    char username[15];
    char password[15];
    int flag;
} c,a,e,m;

struct{
        int id;
        char username[15];
        int balance;
        int loan;
        int transaction_count;
        float transaction[1024];
        int eid;
        char eusername[15];
        char status[15];
}ac,sender_ac,receiver_ac;

void read_users_from_file() {
    int fd_c = open("customer.txt", O_RDONLY, 0744);
    lseek(fd_c, 0, SEEK_SET);
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        i = read(fd_c, &c, sizeof(c));
    }

    int fd_a = open("admin.txt", O_RDONLY, 0744);
     i = read(fd_a, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", a.id, a.username, a.password, a.flag);
        i = read(fd_a, &a, sizeof(a));
    }

    int fd_m = open("manager.txt", O_RDONLY, 0744);
     i = read(fd_m, &m, sizeof(m));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", m.id, m.username, m.password, m.flag);
        i = read(fd_m, &m, sizeof(m));
    }

    int fd_e = open("employee.txt", O_RDONLY, 0744);
     i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", e.id, e.username, e.password, e.flag);
        i = read(fd_e, &e, sizeof(e));
    }

    int fd_ac = open("account.txt", O_RDONLY, 0744);

    i = read(fd_ac, &ac, sizeof(ac));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Balance: %d, Loan: %d, TransactionNo: %d, EID: %d, EUsername: %s,Status: %s\n", ac.id, ac.username, ac.balance, ac.loan,ac.transaction_count,ac.eid,ac.eusername,ac.status);
        for(int i = 0;i<=ac.transaction_count;i++){
            printf("%f ",ac.transaction[i]);
        }
        i = read(fd_ac, &ac, sizeof(ac));
    }
}
void view_balance(char *uname){
    
    int fd_ac = open("account.txt", O_RDONLY,0744);
    lseek(fd_ac,0,SEEK_SET);
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n",uname);
    while (i > 0) {
        printf("\nID: %d, Username: %s\n", ac.id,ac.username);
        if (strcmp(ac.username, uname) == 0) {
                char str[15];
                sprintf(str, "%d", ac.balance);
                sprintf(response, "Balance is  %s\n",str);
                return;
            } 
            i = read(fd_ac, &ac, sizeof(ac));     
    }   
    strcpy(response, "user not logged in\n");

    close(fd_ac);
   
}

void deposit_money(int sd,char *uname){

    int fd_ac = open("account.txt", O_RDWR,0744);
    lseek(fd_ac, 0, SEEK_SET);
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n",uname);
    while (i > 0) {
        printf("\nID: %d, Username: %s\n", ac.id,ac.username);
        if (strcmp(ac.username, uname) == 0) {
                char msg[] = "Enter amount to deposit: ";
                char bal[1024];
                write(sd, msg, sizeof(msg));
                read(sd, bal, sizeof(bal));
                int balance = atoi(bal);
                ac.balance = ac.balance+balance;
                ac.transaction[ac.transaction_count] = balance;
                ac.transaction_count++;
                lseek(fd_ac, -sizeof(ac), SEEK_CUR);  
                write(fd_ac, &ac, sizeof(ac)); 
                strcpy(response,"Deposit Done");
                return;
            } 
            i = read(fd_ac, &ac, sizeof(ac));     
    }   
    strcpy(response, "user not logged in\n");

    close(fd_ac);
}

void withdraw_money(int sd,char *uname){
    int fd_ac = open("account.txt", O_RDWR,0744);
    lseek(fd_ac, 0, SEEK_SET);
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n",uname);
    while (i > 0) {
        printf("\nID: %d, Username: %s\n", ac.id,ac.username);
        if (strcmp(ac.username, uname) == 0) {
                char msg[] = "Enter amount to withdraw: ";
                char bal[1024];
                write(sd, msg, sizeof(msg));
                read(sd, bal, sizeof(bal));
                int balance = atoi(bal);
                if(balance>ac.balance){
                    strcpy(response,"Insufficient Balance");
                    return;
                }
                if(balance<=0){
                    strcpy(response,"ERROR:Amount should be greater than zero");
                    return;
                }
                ac.balance = ac.balance-balance;
                ac.transaction[ac.transaction_count] = -1*balance;
                ac.transaction_count++;
                lseek(fd_ac, -sizeof(ac), SEEK_CUR);  
                write(fd_ac, &ac, sizeof(ac)); 
                strcpy(response,"Withdraw Done");
                return;
            } 
            i = read(fd_ac, &ac, sizeof(ac));     
    }   
    strcpy(response, "user not logged in\n");

    close(fd_ac);
}

void view_history(int sd,char *uname){
    int fd_ac = open("account.txt", O_RDONLY,0744);
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n",uname);
    while (i > 0) {
        printf("\nID: %d, Username: %s\n", ac.id,ac.username);
        if (strcmp(ac.username, uname) == 0) {
                char hist[1024] = "";
                char str[12];
                for(int i = 0;i<ac.transaction_count;i++){
                    sprintf(str, "%.2f", ac.transaction[i]); 
                    strcat(hist, str); 
                    strcat(hist," ");
                }
                send(sd, hist, strlen(hist) + 1, 0);
                return;
            } 
            i = read(fd_ac, &ac, sizeof(ac));     
    }   
    strcpy(response, "user not logged in\n");

    close(fd_ac);
}
int change_password(int sd,char *uname){
    char new_pass[1024];
    int fd_c = open("customer.txt", O_RDWR, 0744);
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        // printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
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

void transfer_funds(int sd,char *uname) {
    struct flock lock;
    char msg[] = "Enter receiver's ID: ";
    char recid[1024];
    char transfer[1024];

    write(sd, msg, sizeof(msg));
    read(sd, recid, sizeof(recid));
    printf("Receiver ID Received: %s\n", recid);
    int rid = atoi(recid);

    char pass_msg[] = "Enter Amount to transfer: ";
    write(sd, pass_msg, sizeof(pass_msg));
    read(sd, transfer, sizeof(transfer));
    printf("Amount Received: %s\n", transfer);
    int amt = atoi(transfer);

    int fd = open("account.txt", O_RDWR, 0744);
    if (fd == -1) {
        perror("ERROR Opening File");
        return;
    }

    int sender_found = 0, receiver_found = 0;

    lseek(fd, 0, SEEK_SET);
    while (read(fd, &sender_ac, sizeof(sender_ac)) > 0) {
        if (strcmp(sender_ac.username, uname) == 0) {
            printf("Sender found: %s\n", uname);
            sender_found = 1;
            break;
        }
    }

    if (!sender_found) {
        strcpy(response, "Sender account not found\n");
        write(sd, response, strlen(response) + 1);
        close(fd);
        return;
    }

    if (sender_ac.id == rid) {
        strcpy(response, "Self-transfer is not allowed\n");
        write(sd, response, strlen(response) + 1);
        close(fd);
        return;
    }

    lseek(fd, 0, SEEK_SET);  
    off_t receiver_pos = 0;  // Position to store where the receiver record is
    while (read(fd, &receiver_ac, sizeof(receiver_ac)) > 0) {
        if (receiver_ac.id == rid) {
            printf("Receiver found: ID %d\n", rid);
            receiver_pos = lseek(fd, 0, SEEK_CUR) - sizeof(receiver_ac);  
            receiver_found = 1;
            break;
        }
    }

    if (!receiver_found) {
        strcpy(response, "Receiver account not found\n");
        write(sd, response, strlen(response) + 1);
        close(fd);
        return;
    }

    lseek(fd, -sizeof(sender_ac), SEEK_CUR);  // Move back to the sender's record
    lock.l_type = F_WRLCK;
    lock.l_start = lseek(fd, 0, SEEK_CUR);  // Lock the sender's record
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(sender_ac);
    fcntl(fd, F_SETLKW, &lock);

    if (sender_ac.balance < amt) {
        strcpy(response, "Insufficient balance\n");
        write(sd, response, strlen(response) + 1);
        fcntl(fd, F_UNLCK, &lock);
        close(fd);
        return;
    }

    sender_ac.balance -= amt;  
    lseek(fd, -sizeof(sender_ac), SEEK_CUR);  
    write(fd, &sender_ac, sizeof(sender_ac));  
    fcntl(fd, F_UNLCK, &lock);  

    lseek(fd, receiver_pos, SEEK_SET);  
    lock.l_type = F_WRLCK;
    lock.l_start = receiver_pos; 
    lock.l_len = sizeof(receiver_ac);
    fcntl(fd, F_SETLKW, &lock);

    receiver_ac.balance += amt; 
    lseek(fd, receiver_pos, SEEK_SET);  
    write(fd, &receiver_ac, sizeof(receiver_ac));  
    fcntl(fd, F_UNLCK, &lock);  

    strcpy(response, "Transfer successful\n");
    write(sd, response, strlen(response) + 1);

    close(fd);
}

void add_feedback(){
    int fd_f = open("feedback.txt", O_WRONLY,0744);
    
}
int validate_login(int type,char *uname,char *pass) {
    int i;
    switch (type) {
    case 1:
    int fd_ad = open("admin.txt",O_RDWR,0744);
    lseek(fd_ad, 0, SEEK_SET);
    i = read(fd_ad, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", a.id, a.username, a.password, a.flag);
        if (strcmp(a.username, uname) == 0 &&
                strcmp(a.password, pass) == 0) {
                    printf("matched\n");
                if (a.flag == 0) {
                    a.flag = 1;
                    printf("flag 0\n");
                    lseek(fd_ad, -sizeof(a), SEEK_CUR);  
                    write(fd_ad, &a, sizeof(a)); 
                    close(fd_ad);
                    return 1;  // Login successful
                } else {
                    close(fd_ad);
                    return -1;  // User already logged in
                }
            }   
            i = read(fd_ad, &a, sizeof(a));        
        }
        close(fd_ad);
        break;
    case 4:
    int fd_c = open("customer.txt", O_RDWR,0744);
    lseek(fd_c, 0, SEEK_SET);
    i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        if (strcmp(c.username, uname) == 0 &&
                strcmp(c.password, pass) == 0) {
                if (c.flag == 0) {
                    c.flag = 1;
                    lseek(fd_c, -sizeof(c), SEEK_CUR);  
                    write(fd_c, &c, sizeof(c)); 
                    close(fd_c);
                    return 1;  // Login successful
                } else {
                    close(fd_c);
                    return -1;  // User already logged in
                }
            }   
            i = read(fd_c, &c, sizeof(c));        
        }
        close(fd_c);
        break;
    }
    return 0;  // Login failed
}

void login(int type,int sd){
    char uname[1024];
    char pass[1024];
     // Request username and password
    
    char msg[] = "Enter Username: ";
    write(sd, msg, sizeof(msg));
    read(sd, uname, sizeof(uname));
    printf("Username Received is %s\n",uname);

    char pass_msg[] = "Enter Password: ";
    write(sd, pass_msg, sizeof(pass_msg));
    read(sd, pass, sizeof(pass));
    printf("Password Received is %s\n",pass);

   
        int validation_result = validate_login(type,uname,pass);

        if (validation_result == 1) {
            strcpy(response, "Login successful\n");
            strcpy(success, "1\n");
        } else if (validation_result == -1) {
            strcpy(response, "User already logged in\n");
            strcpy(success,"0\n");
        } else {
            strcpy(response, "Login failed\n");
            strcpy(success,"0\n");
        }    
    
}

int validate_logout(int type,char *uname) {
    int i;
    switch (type) {
    case 1:
    int fd_ad = open("admin.txt", O_RDWR, 0744);
     i = read(fd_ad, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", a.id, a.username, a.password, a.flag);
        if (strcmp(a.username, uname) == 0) {
                if (a.flag == 1) {
                    a.flag = 0;
                    strcpy(uname,"");
                    lseek(fd_ad, -sizeof(a), SEEK_CUR);
                    write(fd_ad,&a,sizeof(a));
                    close(fd_ad);
                    return 1;  
                } else{
                    close(fd_ad);
                    return 0;
                }
            }   
            i = read(fd_ad, &a, sizeof(a));        
        }
        close(fd_ad);
        break;

    case 4:
    int fd_c = open("customer.txt", O_RDWR, 0744);
     i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        if (strcmp(c.username, uname) == 0) {
                if (c.flag == 1) {
                    c.flag = 0;
                    strcpy(uname,"");
                    lseek(fd_c, -sizeof(c), SEEK_CUR);
                    write(fd_c,&c,sizeof(c));
                    close(fd_c);
                    return 1;  
                } else{
                    close(fd_c);
                    return 0;
                }
            }   
            i = read(fd_c, &c, sizeof(c));        
        }
        close(fd_c);
        break;
    }
    return -1;  // Logout failed
}

int logout(int type,int sd,char *uname){
    
   
        int validation_result = validate_logout(type,uname);

        if (validation_result == 1) {
            strcpy(response, "Logout successful\n");
        } else if (validation_result == -1) {
            strcpy(response, "User not logged in\n");
        } else {
            strcpy(response, "Logout failed\n");
        } 
    
}