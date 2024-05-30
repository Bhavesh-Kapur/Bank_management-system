#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include "link.h"

int main(){
    printf("Welcome To Our Banking Services");
    printf("Press 1 to Create a new Account in our bank");
    printf("Press 2 to Login into your account");
    int c;
    scanf("%d", &c);
    switch (c)
    {
        case 1:
        printf("Welcome to our bank");
       char* z= newUser();
       printf("%s",z);
        break;
    
    default:
    printf("Wrong choice entered");
        break;
    }

}