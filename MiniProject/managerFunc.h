#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char response[1024];

void activate_account(int sd){
    char uname[1024];
    char msg[] = "Enter Username of customer: ";
    write(sd, msg, sizeof(msg));
    read(sd, uname, sizeof(uname));
    printf("Username Received is %s\n",uname);
    int fd_c = open("customer.txt", O_RDWR, 0744);
    int fd_a = open("account.txt", O_RDWR, 0744);

        // Find customer in customer.txt
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        if (strcmp(c.username, uname) == 0) {
            if (c.active == 1) {
                strcpy(response, "User already activated\n");
                close(fd_c);
                close(fd_a);
                return;
            }
            c.active = 1;
            lseek(fd_c, -sizeof(c), SEEK_CUR);
            int by = write(fd_c, &c, sizeof(c));
            if (by > 0) {
                int j = read(fd_a, &ac, sizeof(ac));
                while (j > 0) {
                    if (strcmp(ac.username, uname) == 0) {
                        ac.active = 1; // Activate the account
                        lseek(fd_a, -sizeof(ac), SEEK_CUR);
                        int ba = write(fd_a, &ac, sizeof(ac));
                        if (ba > 0) {
                            strcpy(response, "Activation Successful\n");
                        } else {
                            strcpy(response, "Error updating account file\n");
                        }
                        close(fd_c);
                        close(fd_a);
                        return;
                    }
                    j = read(fd_a, &ac, sizeof(ac));
                }
                strcpy(response, "Account record not found\n");
            } else {
                strcpy(response, "Error updating customer file\n");
            }
            close(fd_c);
            close(fd_a);
            return;
        }
        i = read(fd_c, &c, sizeof(c));
    }

    strcpy(response, "User doesn't exist\n");
    close(fd_c);
    close(fd_a);
    return;

}

void deactivate_account(int sd){
    char uname[1024];
    char msg[] = "Enter Username of customer: ";
    write(sd, msg, sizeof(msg));
    read(sd, uname, sizeof(uname));
    printf("Username Received is %s\n",uname);

    int fd_c = open("customer.txt", O_RDWR, 0744);
    int fd_a = open("account.txt", O_RDWR, 0744);

        // Find customer in customer.txt
    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        if (strcmp(c.username, uname) == 0) {
            if (c.active == 0) {
                strcpy(response, "User already deactivated\n");
                close(fd_c);
                close(fd_a);
                return;
            }
            c.active = 0;
            lseek(fd_c, -sizeof(c), SEEK_CUR);
            int by = write(fd_c, &c, sizeof(c));
            if (by > 0) {
                int j = read(fd_a, &ac, sizeof(ac));
                while (j > 0) {
                    if (strcmp(ac.username, uname) == 0) {
                        ac.active = 0; 
                        lseek(fd_a, -sizeof(ac), SEEK_CUR);
                        int ba = write(fd_a, &ac, sizeof(ac));
                        if (ba > 0) {
                            strcpy(response, "Deactivation Successful\n");
                        } else {
                            strcpy(response, "Error updating account file\n");
                        }
                        close(fd_c);
                        close(fd_a);
                        return;
                    }
                    j = read(fd_a, &ac, sizeof(ac));
                }
                strcpy(response, "Account record not found\n");
            } else {
                strcpy(response, "Error updating customer file\n");
            }
            close(fd_c);
            close(fd_a);
            return;
        }
        i = read(fd_c, &c, sizeof(c));
    }

    strcpy(response, "User doesn't exist\n");
    close(fd_c);
    close(fd_a);
    return;
}

void review_feedback(int sd){
    int fd_f;
    char buffer[1024];
    int bytes_read;
    fd_f = open("feedback.txt", O_RDONLY);
    if (fd_f < 0) {
        perror("Error opening feedback.txt");
        return;
    }
    while ((bytes_read = read(fd_f, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';

        if (write(sd, buffer, bytes_read) < 0) {
            strcpy(response,"Error Writing to Client\n");
            close(fd_f);
            return;
        }
    }

    if (bytes_read < 0) {
        strcpy(response,"Error reading feedback\n");
        return;
    }
    close(fd_f);
    strcpy(response,"End of FEEDBACK\n");
    return;
}

int change_password_man(int sd,char *uname){
    char new_pass[1024];
    int fd_c = open("manager.txt", O_RDWR, 0744);
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

void assign_employee(int sd) {
    char id[1024];
    char u_name[1024];
    int fd_ac = open("account.txt", O_RDWR, 0744);
    char cust_id[1024];
    
    if (fd_ac == -1) {
        strcpy(response, "Error opening account file\n");
        return;
    }

    char cid_msg[256];
    strcpy(cid_msg,"Enter Customer Id: \n");
    write(sd, cid_msg, strlen(cid_msg) + 1);
    read(sd, cust_id, sizeof(cust_id));
    printf("Customer Id received: %s\n", cust_id);

    char id_msg[256];
    strcpy(id_msg,"Enter Employee Id :\n");
    write(sd, id_msg, strlen(id_msg) + 1);
    read(sd, id, sizeof(id));
    printf("Employee Id received: %s\n", id);

    char uname_msg[256];
    strcpy(uname_msg, "Enter Employee Username:\n");
    write(sd, uname_msg, strlen(uname_msg) + 1);
    read(sd, u_name, sizeof(u_name));
    printf("Employee Username received: %s\n", u_name);
    int cid = atoi(cust_id);
    int eid = atoi(id);

    int emp_found = 0;
    int fd = open("employee.txt", O_RDWR, 0744);
    lseek(fd, 0, SEEK_SET);
    while (read(fd, &e, sizeof(e)) > 0) {
        if (strcmp(e.username, u_name) == 0 && e.id == eid) {
            emp_found = 1;
            break;
        }
    }

    if(emp_found == 0){
        strcpy(response, "Employee not found\n");
        return;
    }

    int i = read(fd_ac, &ac, sizeof(ac));
    while (i > 0) {
        if (ac.active && ac.eid == -1 && strcmp(ac.status, "Pending") == 0 && ac.id == cid) {

            ac.eid = atoi(id);
            strcpy(ac.eusername, u_name);

            lseek(fd_ac, -sizeof(ac), SEEK_CUR);
            int by = write(fd_ac, &ac, sizeof(ac));

            if (by > 0) {
                snprintf(response, sizeof(response), "Employee '%s' assigned to account '%s'\n", u_name, ac.username);
                return;
            } else {
                snprintf(response, sizeof(response), "Error updating employee info\n");
                close(fd_ac);
                return;
            }
        }
        i = read(fd_ac, &ac, sizeof(ac)); 
    }

    strcpy(response, "Please enter correct details\n");
    close(fd_ac);
    return;
}
