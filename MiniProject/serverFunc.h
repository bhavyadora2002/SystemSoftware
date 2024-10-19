
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
    int active;
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
        int active;
}ac,sender_ac,receiver_ac;

void read_users_from_file() {
    int fd_c = open("customer.txt", O_RDONLY, 0744);
    lseek(fd_c, 0, SEEK_SET);
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d,Status: %d\n", c.id, c.username, c.password, c.flag,c.active);
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
        printf("\nID: %d, Username: %s, Balance: %d, Loan: %d, TransactionNo: %d, EID: %d, EUsername: %s,Status: %s,Active: %d\n", ac.id, ac.username, ac.balance, ac.loan,ac.transaction_count,ac.eid,ac.eusername,ac.status,ac.active);
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

void deposit_money(int sd, char *uname) {
    struct flock lock;
    char msg[] = "Enter amount to deposit: ";
    char bal[1024];

    // Notify the user to enter the amount to deposit
    write(sd, msg, sizeof(msg));
    read(sd, bal, sizeof(bal));
    int balance = atoi(bal);

    int fd_ac = open("account.txt", O_RDWR, 0744);
    if (fd_ac == -1) {
        perror("ERROR Opening File");
        return;
    }

    // Lock the file for writing
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0; // Lock the whole file
    lock.l_len = 0;   // 0 means to the end of the file
    fcntl(fd_ac, F_SETLKW, &lock); // Apply the lock

    lseek(fd_ac, 0, SEEK_SET); // Reset the pointer to the beginning
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n", uname);

    while (i > 0) {
        if (strcmp(ac.username, uname) == 0) {
            ac.balance += balance; // Update the balance
            ac.transaction[ac.transaction_count] = balance; // Record the transaction
            ac.transaction_count++;

            lseek(fd_ac, -sizeof(ac), SEEK_CUR); // Move back to update
            write(fd_ac, &ac, sizeof(ac)); // Write back to file
            strcpy(response, "Deposit Done");
            break;
        }
        i = read(fd_ac, &ac, sizeof(ac));
    }

    if (i <= 0) {
        strcpy(response, "User not logged in\n");
    }

    // Unlock the file
    lock.l_type = F_UNLCK; // Set lock type to unlock
    fcntl(fd_ac, F_SETLK, &lock); // Release the lock
    close(fd_ac);
}

void withdraw_money(int sd, char *uname) {
    struct flock lock;
    char msg[] = "Enter amount to withdraw: ";
    char bal[1024];

    // Notify the user to enter the amount to withdraw
    write(sd, msg, sizeof(msg));
    read(sd, bal, sizeof(bal));
    int balance = atoi(bal);

    int fd_ac = open("account.txt", O_RDWR, 0744);
    if (fd_ac == -1) {
        perror("ERROR Opening File");
        return;
    }

    // Lock the file for writing
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0; // Lock the whole file
    lock.l_len = 0;   // 0 means to the end of the file
    fcntl(fd_ac, F_SETLKW, &lock); // Apply the lock

    lseek(fd_ac, 0, SEEK_SET); // Reset the pointer to the beginning
    int i = read(fd_ac, &ac, sizeof(ac));
    printf("Uname %s\n", uname);

    while (i > 0) {
        if (strcmp(ac.username, uname) == 0) {
            if (balance > ac.balance) {
                strcpy(response, "Insufficient Balance");
                break;
            }
            if (balance <= 0) {
                strcpy(response, "ERROR: Amount should be greater than zero");
                break;
            }

            ac.balance -= balance; // Update the balance
            ac.transaction[ac.transaction_count] = -1 * balance; // Record withdrawal
            ac.transaction_count++;

            lseek(fd_ac, -sizeof(ac), SEEK_CUR); // Move back to update
            write(fd_ac, &ac, sizeof(ac)); // Write back to file
            strcpy(response, "Withdraw Done");
            break;
        }
        i = read(fd_ac, &ac, sizeof(ac));
    }

    if (i <= 0) {
        strcpy(response, "User not logged in\n");
    }

    // Unlock the file
    lock.l_type = F_UNLCK; // Set lock type to unlock
    fcntl(fd_ac, F_SETLK, &lock); // Release the lock
    close(fd_ac);
}
void transfer_funds(int sd, char *uname) {
    struct flock lock;
    char msg[] = "Enter receiver's ID: ";
    char recid[1024];
    char transfer[1024];

    // Notify the user to enter the receiver's ID
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

    // Lock the file for writing
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0; // Lock the whole file
    lock.l_len = 0;   // 0 means to the end of the file
    fcntl(fd, F_SETLKW, &lock); // Apply the lock

    int sender_found = 0, receiver_found = 0;
    off_t receiver_pos = 0; // Position to store where the receiver record is

    // First, find the sender's account
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
        fcntl(fd, F_UNLCK, &lock); // Release the lock
        close(fd);
        return;
    }

    if (sender_ac.id == rid) {
        strcpy(response, "Self-transfer is not allowed\n");
        write(sd, response, strlen(response) + 1);
        fcntl(fd, F_UNLCK, &lock); // Release the lock
        close(fd);
        return;
    }

    // Now find the receiver's account
    lseek(fd, 0, SEEK_SET);  
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
        fcntl(fd, F_UNLCK, &lock); // Release the lock
        close(fd);
        return;
    }

    if (sender_ac.balance < amt) {
        strcpy(response, "Insufficient balance\n");
        write(sd, response, strlen(response) + 1);
        fcntl(fd, F_UNLCK, &lock); // Release the lock
        close(fd);
        return;
    }

    // Perform the transfer: deduct from sender and add to receiver
    sender_ac.balance -= amt;  // Update sender's balance
    lseek(fd, -sizeof(sender_ac), SEEK_CUR);  // Move back to the sender's record
    write(fd, &sender_ac, sizeof(sender_ac));  // Write back updated sender balance

    lseek(fd, receiver_pos, SEEK_SET);  // Move to the receiver's position
    receiver_ac.balance += amt;  // Update receiver's balance
    write(fd, &receiver_ac, sizeof(receiver_ac));  // Write back updated receiver balance

    // Send success message
    strcpy(response, "Transfer successful\n");
    write(sd, response, strlen(response) + 1);

    // Unlock the file
    lock.l_type = F_UNLCK; // Set lock type to unlock
    fcntl(fd, F_SETLK, &lock); // Release the lock
    close(fd);
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

void add_feedback(int sd){
    char fb[1024];
    int fd_f = open("feedback.txt", O_WRONLY|O_APPEND|O_CREAT,0744);
    char fb_msg[] = "Enter Feedback: ";
    write(sd, fb_msg, sizeof(fb_msg));
    read(sd, fb, sizeof(fb));
    printf("Feedback Received is %s\n",fb);
    lseek(fd_f,0,SEEK_END);
    strcat(fb,"\n");
    int i = write(fd_f,&fb,strlen(fb));
	close(fd_f);
    if(i>0)
    strcpy(response,"Added Feedback\n");
    else
    strcpy(response,"Unable to add feedback");
}

void apply_loan(int sd,char *uname){
    char loan[1024];
    int lamt;
    int fd_ac = open("account.txt", O_RDWR,0744);
    int i = read(fd_ac, &ac, sizeof(ac));
    
    while (i > 0) {
        printf("\nID: %d, Username: %s\n", ac.id,ac.username);
        if (strcmp(ac.username, uname) == 0 ) {
            if(ac.active){
                if(strcmp(ac.status,"No") == 0){
                    printf("Uname %s\n",uname);
                    char loan_msg[] = "Enter Loan Amount: ";
                    write(sd, loan_msg, sizeof(loan_msg));
                    read(sd, loan, sizeof(loan));
                    printf("Loan Amount entered is %s\n",loan);
                    lamt = atoi(loan);
                    ac.loan = lamt;
                    strcpy(ac.status,"Pending");
                    lseek(fd_ac, -sizeof(ac), SEEK_CUR);  
                    int by = write(fd_ac, &ac, sizeof(ac)); 
                    if(by>0){
                    close(fd_ac);
                    strcpy(response,"Loan applied Successfuly\n");
                    return;
                    }
                    else{
                    close(fd_ac);
                    strcpy(response,"Error updating loan info\n");
                    return;
                    }
                    }
                else{
                close(fd_ac);
                strcpy(response,"Cannot apply for multiple loans\n");
                return;
                }
            }
                strcpy(response,"Not Active User\n");
                close(fd_ac);
                return;
            } 
            i = read(fd_ac, &ac, sizeof(ac));     
    }   
    strcpy(response, "User record not found\n");
    close(fd_ac);
    return;
}
int validate_login(int type,char *uname,char *pass) {
    int i;
    printf("%d\n",type);
    switch (type) {
    case 1:
    int fd_ad = open("admin.txt",O_RDWR,0744);
    lseek(fd_ad, 0, SEEK_SET);
    i = read(fd_ad, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", a.id, a.username, a.password, a.flag);
        if (strcmp(a.username, uname) == 0 &&
                strcmp(a.password, pass) == 0 && a.active) {
                if (a.flag == 0) {
                    a.flag = 1;
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
    case 2:
    int fd_m = open("manager.txt",O_RDWR,0744);
    lseek(fd_m, 0, SEEK_SET);
    i = read(fd_m, &m, sizeof(m));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", m.id, m.username, m.password, m.flag);
        if (strcmp(m.username, uname) == 0 &&
                strcmp(m.password, pass) == 0 && m.active) {
                if (m.flag == 0) {
                    m.flag = 1;
                    lseek(fd_m, -sizeof(m), SEEK_CUR);  
                    write(fd_m, &m, sizeof(m)); 
                    close(fd_m);
                    return 1;  // Login successful
                } else {
                    m.flag = 0;
                    lseek(fd_m, -sizeof(m), SEEK_CUR);  
                    write(fd_m, &m, sizeof(m)); 
                    close(fd_m);
                    return -1;  // User already logged in
                }
            }   
            i = read(fd_m, &m, sizeof(m));        
        }
        close(fd_m);
        break;
    case 3:
    int fd_e = open("employee.txt", O_RDWR,0744);
    lseek(fd_e, 0, SEEK_SET);
    i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", e.id, e.username, e.password, e.flag);
        if (strcmp(e.username, uname) == 0 &&
                strcmp(e.password, pass) == 0 && e.active) {
                if (e.flag == 0) {
                    e.flag = 1;
                    lseek(fd_e, -sizeof(e), SEEK_CUR);  
                    write(fd_e, &e, sizeof(e)); 
                    close(fd_e);
                    return 1;  // Login successful
                } else {
                    e.flag = 0;
                    lseek(fd_e, -sizeof(e), SEEK_CUR);  
                    write(fd_e, &e, sizeof(e)); 
                    close(fd_e);
                    return -1;  // User already logged in
                }
            }   
            i = read(fd_e, &e, sizeof(e));        
        }
        close(fd_e);
        break;  
    case 4:
    int fd_c = open("customer.txt", O_RDWR,0744);
    lseek(fd_c, 0, SEEK_SET);
    i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
        if (strcmp(c.username, uname) == 0 &&
                strcmp(c.password, pass) == 0 && c.active) {
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
            strcpy(response, "User already logged in..Logging out previous session\n");
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
    case 2:
    int fd_m = open("manager.txt", O_RDWR, 0744);
     i = read(fd_m, &m, sizeof(m));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", m.id, m.username, m.password, m.flag);
        if (strcmp(m.username, uname) == 0) {
                if (m.flag == 1) {
                    m.flag = 0;
                    strcpy(uname,"");
                    lseek(fd_m, -sizeof(m), SEEK_CUR);
                    write(fd_m,&m,sizeof(m));
                    close(fd_m);
                    return 1;  
                } else{
                    close(fd_m);
                    return 0;
                }
            }   
            i = read(fd_m, &m, sizeof(m));        
        }
        close(fd_m);
        break;

    case 3:
    int fd_e = open("employee.txt", O_RDWR, 0744);
     i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", e.id, e.username, e.password, e.flag);
        if (strcmp(e.username, uname) == 0) {
                if (e.flag == 1) {
                    e.flag = 0;
                    strcpy(uname,"");
                    lseek(fd_e, -sizeof(e), SEEK_CUR);
                    write(fd_e,&e,sizeof(e));
                    close(fd_e);
                    return 1;  
                } else{
                    close(fd_e);
                    return 0;
                }
            }   
            i = read(fd_e, &e, sizeof(e));        
        }
        close(fd_e);
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