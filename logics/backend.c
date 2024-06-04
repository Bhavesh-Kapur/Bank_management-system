#include "link.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

#include<mysql/mysql.h>

char* newUser(){
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
        return "Error Occured";
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
        return "Error Ocurred";
    }
    mysql_close(conn);

    return "New Account Created";
}


char* slipGeneration(int accNo){
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[512];
    static char result[4096];
    int num_fields, i;
    conn = mysql_init(NULL);

    if(!mysql_real_connect(conn, "localhost", "root", "root", "BANK" ,0 ,NULL, 0)){
        fprintf(stderr,"Database Connection Failed");
        return "Internal Error Occured";
    }

    // if(mysql_query(conn, "select * from transactions where accNo = %d", accNo)){
    //     fprintf(stderr, "%s\n", mysql_error(conn));
    //     return "Error Fetching";
    // }

    snprintf(query,sizeof(query),
    "select * from transactions where accNo =%d", accNo);

    if (mysql_query(conn, query) != 0)
    {
        fprintf(stderr, "Error fetching");
        mysql_close(conn);
        return "Error Occured while fetching";

    }
    res = mysql_use_result(conn);
    if (!res) {
        fprintf(stderr, "Error storing result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return "Error Occurred while fetching";
    }
     strcpy(result, "Transactions are:\n");

    num_fields = mysql_num_fields(res);


    while ((row = mysql_fetch_row(res)) != NULL) {
        for (i = 0; i < num_fields; i++) {
            strcat(result, row[i] ? row[i] : "NULL");
            if (i < num_fields - 1) {
                strcat(result, ", ");
            }
        }
        strcat(result, "\n");
    }
    
    mysql_free_result(res);
    mysql_close(conn);
// if (result == NULL)
//     return "No data is fetched";  
// else
    return result;
    
}




char* miniStmt(int accNo){
    MYSQL *conn;
    MYSQL_RES *res;
    FILE *fptr;
    MYSQL_ROW row;
    char query[512];
    static char result[4096];
    int num_fields, i;
    conn = mysql_init(NULL);
     if(!mysql_real_connect(conn, "localhost", "root", "root", "BANK" ,0 ,NULL, 0)){
        fprintf(stderr,"Database Connection Failed");
        return "Internal Error Occured";
    }

    fptr = fopen("Statement.txt", "w");
      snprintf(query,sizeof(query),
    "select * from transactions where accNo =%d", accNo);

    if (mysql_query(conn, query) != 0)
    {
        fprintf(stderr, "Error fetching");
        mysql_close(conn);
        return "Error Occured while fetching";

    }
       res = mysql_use_result(conn);
    if (!res) {
        fprintf(stderr, "Error storing result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return "Error Occurred while fetching";
    }
     strcpy(result, "Transactions are:\n");

    num_fields = mysql_num_fields(res);

        while ((row = mysql_fetch_row(res)) != NULL) {
        for (i = 0; i < num_fields; i++) {
            strcat(result, row[i] ? row[i] : "NULL");
            if (i < num_fields - 1) {
                strcat(result, ", ");
            }
        }
        strcat(result, "\n");
    }
    
    mysql_free_result(res);
    mysql_close(conn);


    fprintf(fptr, result);
    fclose(fptr);
    return "Your Mini Statement Has been Downloaded ";

}


// int login(int accNo, int pin){
//     MYSQL *conn;
//     conn = mysql_init(NULL);
//     char query[512];
//     static char result[4096];
//      int num_fields, i, flag = 0;
//     MYSQL_RES *res;
//     MYSQL_ROW row;
//      if(!mysql_real_connect(conn, "localhost", "root", "root", "BANK", 0, NULL, 0)){
//         fprintf(stderr,"Database Connection Failed \n");
//         return 0;
//     }

//     snprintf(query, sizeof(query),
//         "select name, mobNo from accounts where accNo = '%d' and pin = '%d'", accNo, pin);

//         if(mysql_query(conn, query) != 0){
//             fprintf(stderr, "Error Connecting: %s\n", mysql_error(conn));
//             mysql_close(conn);
//             return 0;
//         }

//         res = mysql_use_result(conn);
//         if(!res){
//             fprintf(stderr, "Error storing result: %s\n", mysql_error(conn));
//             mysql_close(conn);
//             return 0;
//         }

//     num_fields = mysql_num_fields(res); 
//     while ((row = mysql_fetch_row(res)) != NULL) {
//         flag = 1;
//         for (i = 0; i < num_fields; i++) {
//             strcat(result, row[i] ? row[i] : "NULL");
//             if (i < num_fields - 1) {
//                 strcat(result, ", ");
//             }
//         }
//         strcat(result, "\n");
//     }
    
//     printf("%s", result);
//     mysql_free_result(res);
//     mysql_close(conn);

//     if(flag == 1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
//     // if(result != NULL){
//     //     return 1;
//     // }
//     // else 
//     // return 0;
// }





