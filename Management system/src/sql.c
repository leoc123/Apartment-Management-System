#include "sql.h"
#define SQL "SELECT * FROM apartment.Tenants"
#define SQL2 "SELECT * FROM apartment.EmergencyContact"
#define SQL3 "SELECT * FROM apartment.Notes"
#define SQL4 "SELECT * FROM apartment.OccupiantsInfo"
#define SQL5 "SELECT * FROM apartment.ParkingSpot"
#define SQL6 "SELECT * FROM apartment.PreviousLandLords"
#define SQL7 "SELECT * FROM apartment.Reference"

MYSQL * estConnection(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
{
	MYSQL * connection = mysql_init(NULL);

	if (connection == NULL) {

		printf("%s\n", mysql_error(connection));
		mysql_close(connection);
		exit(1);
	}

	else {

		if (mysql_real_connect(connection, host, user, passwd, db, port, unix_socket, client_flag) == NULL)
		{
			printf("%s\n", mysql_error(connection));
			mysql_close(connection);
			exit(1);
		}

		else
		{
			printf("\nConnection Established!\n");
			return connection;
		}

	}

}

void createDB(MYSQL *mysql, const char *stmt_str)
{
	if (mysql_query(mysql, stmt_str) != 0)
	{
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
	}

	else
	{
		printf("\nDatabase Created!\n");
		mysql_close(mysql);
	}
}

void printDatabase(MYSQL *mysql)
{

	MYSQL_RES *result = mysql_list_dbs(mysql, "%");
	MYSQL_ROW row;

	printf("\n");
	if (result == NULL) {

		printf("%s\n", mysql_error(mysql));
			mysql_close(mysql);
			exit(1);
	}

	else
	{
		while ((row = mysql_fetch_row(result))) {
		printf("%s\n", row[0]);
	}
	}
}


void executeSQL(MYSQL *mysql, const char *stmt_str)
{
	if (mysql_query(mysql, stmt_str) != 0)
	{
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
	}

	else
	{
		printf("SQL Executed!\n");
	}
}

void print(MYSQL *mysql, char * searchTerm) {

	char *token;
	int db = 0;
	char * firstName = (char*)malloc(255 * sizeof(char));
	char * lastName= (char*)malloc(255 * sizeof(char));
	char * searchSQL = (char*)malloc(255 * sizeof(char));
	int personID;
	char * searchID = (char*)malloc(255 * sizeof(char));
	int counter = 0;

	token = strtok(searchTerm, " ");	

	while (token != NULL)
	{
		if (counter == 0)
		{
			strcpy(firstName, token);
		}

		else if(counter == 1)
		{
			strcpy(lastName, token);
		}
		counter++;
		token = strtok(NULL, " ");
	}

	
	sprintf(searchSQL, "SELECT * FROM apartment.tenants WHERE firstName LIKE '%%%s%%' AND lastName LIKE '%%%s%%'", firstName, lastName);

	executeSQL(mysql, searchSQL);
	printf("\n");
	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	MYSQL_ROW row;

	int rows = mysql_num_fields(result);
	printf("-----Tenant-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
			personID = atoi(row[0]);
		}
		printf("\n");
	}

	// while (db != 6)
	// {
	// 	if (db == 0)
	// 	{
	// 		sprintf(searchID, "SELECT * FROM apartment.EmergencyContact WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----EmergencyContact-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
		
	// 	}

	// 	else if (db == 1)
	// 	{
	// 		sprintf(searchID, "SELECT * FROM apartment.Notes WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----Notes-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
	// 	}

	// 	else if (db == 2)
	// 	{
	// 		sprintf(searchID, "SELECT * FROM apartment.OccupiantsInfo WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----Occupiants Info-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
	// 	}

	// 	else if (db == 3)
	// 	{

	// 		sprintf(searchID, "SELECT * FROM apartment.ParkingSpot WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----Parking Spot-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
			
	// 	}

	// 	else if (db == 4)
	// 	{

	// 		sprintf(searchID, "SELECT * FROM apartment.PreviousLandLords WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----Previous Land Lords-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
			
	// 	}

	// 	else if (db == 5)
	// 	{

	// 		sprintf(searchID, "SELECT * FROM apartment.Reference WHERE personID LIKE '%%%d%%'", personID);
	// 		executeSQL(mysql, searchID);
	// 		printf("\n");
	// 		MYSQL_RES *result = mysql_store_result(mysql);
	// 		MYSQL_FIELD *fields = mysql_fetch_fields(result);
	// 		MYSQL_ROW row;

	// int rows = mysql_num_fields(result);
	// printf("-----References-----\n");
	// while((row = mysql_fetch_row(result))){
	// 	for (int i = 0; i < rows; i++)
	// 	{
	// 		printf("%s: %s\n", fields[i].name, row[i]);
	// 	}
	// }
			
	// 	}

	// 	db++;
	// }
}


