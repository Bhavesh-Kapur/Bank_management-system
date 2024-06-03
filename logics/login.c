#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main() {
    MYSQL *con = mysql_init(NULL);
    
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root", "BANK", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    int accNo, pin;

    printf("Enter account number: ");
    scanf("%d", &accNo); // Corrected
    printf("Enter pin: ");
    scanf("%d", &pin); // Corrected

    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM accounts WHERE accNo='%d' AND pin='%d'", accNo, pin);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    MYSQL_RES *res = mysql_store_result(con);

    if (res == NULL) {
        finish_with_error(con);
    }

    MYSQL_ROW row;

    if ((row = mysql_fetch_row(res))) {
        printf("Login Successful. Welcome %d!\n", accNo);
        // Here you could call another function to load a dashboard or proceed with the application
    } else {
        printf("Invalid accNo or pin\n");
    }

    mysql_free_result(res);
    mysql_close(con);

    return 0;
}
