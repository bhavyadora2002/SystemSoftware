#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
	struct{
        int id;
		char username[15];
		char password[15];
        int flag;
        int active;
	}c,a,m,e;

    struct{
        int id;
        char username[15];
        int balance;
        int loan;
        int transaction_count;
        char transactions[1024];        
        int eid;
        char eusername[15];
        char status[15];
        int active;
    }ac;

    int fd_c = open("customer.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	for(int i =0;i<3;i++){
        c.id = i+1;
        char str1[10] = "cust";
        char str2[10] = "cpass";
        char str[3];
        sprintf(str, "%d", i+1); // Convert integer to string
        strcat(str1, str); 
        strcat(str2,str);
		strcpy(c.username,str1);
		strcpy(c.password,str2);
        c.flag = 0;
        c.active = 1;
        write(fd_c,&c,sizeof(c));
	}
    lseek(fd_c, 0, SEEK_SET);

    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active_Session: %d,Status: %d\n", c.id, c.username, c.password, c.flag, c.active);
        i = read(fd_c, &c, sizeof(c));
    }
    close(fd_c);

        int fd_ac = open("account.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
    for(int i = 0;i<3;i++){
        ac.id = i+1;
        char str1[10] = "cust";
        char str[3];
        sprintf(str,"%d",i+1);
        strcat(str1,str);
        strcpy(ac.username,str1);
        ac.balance = 10000*(i+1);
        ac.loan = 0;
        ac.transaction_count = 0;
        strcpy(ac.transactions, "");  
        
        ac.eid = -1;
        char str2[10] = "";
        ac.active = 1;
        strcpy(ac.eusername,str2);
        strcpy(ac.status,"No");
        write(fd_ac,&ac,sizeof(ac));
    }
    lseek(fd_ac, 0, SEEK_SET);

    i = read(fd_ac, &ac, sizeof(ac));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Balance: %d, Loan: %d, Transaction Count: %d, EID: %d, EUsername: %s, Status: %s, Active: %d\n", 
               ac.id, ac.username, ac.balance, ac.loan, ac.transaction_count, ac.eid, ac.eusername, ac.status, ac.active);
        
        // Display each transaction by splitting with '\n'
        char *transaction = strtok(ac.transactions, "\n");
        while (transaction != NULL) {
            printf("Transaction: %s\n", transaction);
            transaction = strtok(NULL, "\n");
        }

        i = read(fd_ac, &ac, sizeof(ac));
    }
    close(fd_ac);

    int fd_a = open("admin.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	a.id = 1;
    strcpy(a.username ,"admin");
    strcpy(a.password,"passad");
    a.flag = 0;
    a.active = 1;
    write(fd_a,&a,sizeof(a));
	
    lseek(fd_a, 0, SEEK_SET);

    i = read(fd_a, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active_session: %d,Status: %d\n", a.id, a.username, a.password, a.flag,a.active);
        i = read(fd_a, &a, sizeof(a));
    }
    close(fd_a);

    int fd_m = open("manager.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	m.id = 1;
    strcpy(m.username ,"manager");
    strcpy(m.password,"passman");
    m.flag = 0;
    m.active = 1;
    write(fd_m,&m,sizeof(m));
    lseek(fd_m, 0, SEEK_SET);
    i = read(fd_m, &m, sizeof(m));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active_session: %d,Status: %d\n", m.id, m.username, m.password, m.flag,m.active);
        i = read(fd_m, &m, sizeof(m));
    }
    close(fd_m);

    int fd_e = open("employee.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	for(int i =0;i<2;i++){
        e.id = i+1;
        char str1[10] = "emp";
        char str2[10] = "epass";
        char str[3];
        sprintf(str, "%d", i+1); 
        strcat(str1, str); 
        strcat(str2,str);
		strcpy(e.username,str1);
		strcpy(e.password,str2);
        e.flag = 0;
        e.active = 1;
        write(fd_e,&e,sizeof(e));
	}
    lseek(fd_e, 0, SEEK_SET);
    i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active_Session: %d,Status: %d\n", e.id, e.username, e.password, e.flag,e.active);
        i = read(fd_e, &e, sizeof(e));
    }
    close(fd_e);


}

