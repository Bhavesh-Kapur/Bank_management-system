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
        printf("Enter your account no \n");
        int accNo;
        scanf("%d", &accNo);
        printf("Press 9 for Your mini statement will be shown \n");
        // sleep(5);
        char* y= slipGeneration(accNo);
        printf("%s", y);
        break;
    default:
    printf("Wrong choice entered");
        break;
    }

}