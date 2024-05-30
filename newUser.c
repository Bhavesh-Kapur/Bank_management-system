#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(){
    MYSQL *conn;
    char name[20];
    int accNo;
    int pin;
    float debit;
    float credit;
    float bal;
    long long int mobNo;
    char des[250];
    char email[50];
    char query[512];

    conn = mysql_init(NULL);

    if(!mysql_real_connect(conn, "localhost", "root", "root", "BANK", 0, NULL, 0)){
        fprintf(stderr,"Database Connection Failed \n");
        return EXIT_FAILURE;
    }

    printf("Enter name :");
    scanf("%s", &name);
    
    printf("Enter AccountNo :");
    scanf("%d", &accNo);
    
    printf("Enter Pin :");
    scanf("%d", &pin);
    
    printf("Enter Balance :");
    scanf("%f", &bal);
    
    printf("Enter mobile number :");
    scanf("%lld", &mobNo);
    
    
    printf("Enter email :");
    scanf("%s", &email);
    

//     if(mysql_query(conn, "INSERT INTO accounts VALUES('Bhavesh', 000012345 , 0904, 0.0, 0.0, 40000.0, 9027729449, 'nil', 'ddnbhavesh@gmail.com')") != 0) {
//      fprintf(stderr, "Error inserting: %s\n", mysql_error(conn));
//         mysql_close(conn);
//     return EXIT_FAILURE;
// }


    snprintf(query, sizeof(query), 
             "INSERT INTO accounts (name, accNo, pin, bal, mobNo, email) "
             "VALUES('%s', %d, %d, %.2f, %lld, '%s')",
             name, accNo, pin, bal, mobNo, email);

             if(mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error inserting: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    mysql_close(conn);

    return 0;
}