#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<mysql/mysql.h>
int main(){
    float deposit, withdrawal, bal;
    
printf("Welcome to workd of transactions !!");
char option;
printf("Enter your option deposit or withrawal the money. For deposit enter D and for withdrawal enter W. ");
scanf(" %c", &option);
if (option == 'D' || option =='d'){
    printf("Enter the amount you wish to deposit.");
    scanf("%f",&deposit);
    bal = bal + deposit;
    printf("\nYour current balance is : %f",bal);
}
else if (option=='W' || option == 'w')
{
 printf("Enter the amount you wish to withdraw. ");
    scanf("%f",&withdrawal);
    bal = bal - withdrawal;
    printf("Your current balance is : %f",bal);   
    }

else{
    printf("No money deposisted or withdrawal.");
    printf("\nYour balance is %f",bal);
}
return 0;
}
