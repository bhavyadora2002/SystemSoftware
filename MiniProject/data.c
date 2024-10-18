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
	}c,a,m,e;
    
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
        write(fd_c,&c,sizeof(c));
	}
    lseek(fd_c, 0, SEEK_SET);

    int i = read(fd_c, &c, sizeof(c));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", c.id, c.username, c.password, c.flag);
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
        ac.loan = 50000 *(i+1);
        ac.transaction_count = 0;
        for (int j = 0; j < 1024; j++) {
            ac.transaction[j] = 0.0;  
        }
        ac.eid = i+1;
        char str2[10] = "emp";
        sprintf(str,"%d",i+1);
        strcat(str2,str);
        strcpy(ac.eusername,str2);
        strcpy(ac.status,"Active");
        write(fd_ac,&ac,sizeof(ac));
    }
    lseek(fd_ac, 0, SEEK_SET);

    i = read(fd_ac, &ac, sizeof(ac));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Balance: %d, Loan: %d, TransactionNo: %d, EID: %d, EUsername: %s,Status: %s\n", ac.id, ac.username, ac.balance, ac.loan,ac.transaction_count,ac.eid,ac.eusername,ac.status);
        for(int i = 0;i<=ac.transaction_count;i++){
            printf("%f ",ac.transaction[i]);
        }
        i = read(fd_ac, &ac, sizeof(ac));
    }
    close(fd_ac);

    int fd_a = open("admin.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	a.id = 1;
    strcpy(a.username ,"admin");
    strcpy(a.password,"passad");
    a.flag = 0;
    write(fd_a,&a,sizeof(a));
	
    lseek(fd_a, 0, SEEK_SET);

    i = read(fd_a, &a, sizeof(a));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", a.id, a.username, a.password, a.flag);
        i = read(fd_a, &a, sizeof(a));
    }
    close(fd_a);

    int fd_m = open("manager.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	m.id = 1;
    strcpy(m.username ,"manager");
    strcpy(m.password,"managerpass");
    m.flag = 0;
    write(fd_m,&m,sizeof(m));
    lseek(fd_m, 0, SEEK_SET);
    i = read(fd_m, &m, sizeof(m));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", m.id, m.username, m.password, m.flag);
        i = read(fd_m, &m, sizeof(m));
    }
    close(fd_m);

    int fd_e = open("employee.txt",O_RDWR|O_TRUNC|O_CREAT,0744);
	for(int i =0;i<2;i++){
        e.id = i+1;
        char str1[10] = "emp";
        char str2[10] = "epass";
        char str[3];
        sprintf(str, "%d", i+1); // Convert integer to string
        strcat(str1, str); 
        strcat(str2,str);
		strcpy(e.username,str1);
		strcpy(e.password,str2);
        e.flag = 0;
        write(fd_e,&e,sizeof(e));
	}
    lseek(fd_e, 0, SEEK_SET);
    i = read(fd_e, &e, sizeof(e));
    while (i > 0) {
        printf("\nID: %d, Username: %s, Password: %s, Active: %d\n", e.id, e.username, e.password, e.flag);
        i = read(fd_e, &e, sizeof(e));
    }
    close(fd_e);


}

