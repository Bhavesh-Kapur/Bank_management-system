#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 #include<mysql/mysql.h>
int main(){
    float credit, debit, bal;
    MYSQL *conn;
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn, "localhost", "root", "root", "BANK", 0, NULL, 0)){
        fprintf(stderr,"Database Connection Failed \n");
        return "Error Occured";
    }

printf("Welcome to workd of transactions !!");
char option;
printf("Enter your option credit or withrawal the money. For credit enter D and for debit enter W. ");
scanf(" %c", &option);
if (option == 'D' || option =='d'){
    printf("Enter the amount you wish to credit.");
    scanf("%f",&credit);
    bal = bal + credit;
    printf("\nYour current balance is : %f",bal);
}
else if (option=='W' || option == 'w')
{
 printf("Enter the amount you wish to debit. ");
    scanf("%f",&debit);
    bal = bal - debit;
    printf("Your current balance is : %f",bal);   
    }

else{
    printf("No money credited or debited.");
    printf("\nYour balance is %f",bal);
}
return 0;
}