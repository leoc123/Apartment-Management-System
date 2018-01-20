#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

MYSQL * estConnection(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);
void printDatabase(MYSQL *mysql);
void executeSQL(MYSQL *mysql, const char *stmt_str);
void print(MYSQL *mysql, char *searchTerm, int mode);
