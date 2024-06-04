#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include "link.h"
#include <time.h>
#include <unistd.h>

int main(){
    printf("Welcome To Our Banking Services \n");
    printf("Press 1 to Create a new Account in our bank\n");
    printf("Press 2 to Login into your account \n");
    printf("Press 3 to Download MiniStatment \n");
    int c;
    scanf("%d", &c);
    switch (c)
    {
        case 1:
        printf("Welcome to our bank");
       char* z= newUser();
       printf("%s",z);
        break;
        
        case 2:
        printf("Welcome To Login, Login using Account no and Your Pin \n");
        printf("Enter your account no \n");
        int accNo;
        scanf("%d", &accNo);
        printf("Enter your Account Pin \n");
        int pin;
        scanf("%d", &pin);
        //  int x= login(accNo,pin);
        // printf("%d", x);
        char* y= slipGeneration(accNo);
        printf("%s", y);
        break;

        case 3:
        printf("Enter your accNo");
        scanf("%d",&accNo);
        printf("%s", miniStmt(accNo));
        break;
    default:
    printf("Wrong choice entered");
        break;
    }

}