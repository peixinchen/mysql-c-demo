#include <my_global.h>
#include <mysql.h>
#include <stdlib.h>


void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    if (con != NULL) {
        mysql_close(con);
    }
    exit(1);
}


int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        finish_with_error(con);
    }

    if (mysql_real_connect(con, "localhost", "peixinchen", "pxc_DB", "testdb", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM Cars")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; ++i) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);
}
