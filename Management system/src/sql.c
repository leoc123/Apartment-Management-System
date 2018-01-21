#include "sql.h"
#include "menu.h"

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

void print(MYSQL *mysql, char * searchTerm, int mode) {

	char *token;
	int counter = 0;
	char * personID = (char*)malloc(maxSize * sizeof(char));
	char * firstName = (char*)malloc(maxSize * sizeof(char));
	char * lastName= (char*)malloc(maxSize * sizeof(char));
	char * searchSQL = (char*)malloc(maxSize * sizeof(char));
if (mode == 0)
{
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
	printf("\n");
	sprintf(searchSQL, "SELECT * FROM apartment.tenants WHERE `First Name` LIKE '%%%s%%' AND `Last Name` LIKE '%%%s%%'", firstName, lastName);

	executeSQL(mysql, searchSQL);

	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	MYSQL_ROW row;
	int rows = mysql_num_fields(result);

	printf("-----Tenant(s)-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
			counter++;
		}
		printf("\n");
	}

	
	if (counter <= 1)
	{
		printf("Couldn't Find Anything with the name: '%s %s'",firstName, lastName);
		return;
	}

	else 
	{
		printf("Enter the person ID: ");
		fgets(personID, maxSize, stdin);
		personID[strlen(personID)-1] = '\0';
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Emergency Contacts` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Emergency Contact-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Occupiants Info` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Occupiants Info-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Parking Spots` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Parking Spot-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Reference` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Reference(s)-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.Notes WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Notes-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	free(firstName);
	free(lastName);
	free(personID);
	free(searchSQL);
	mysql_free_result(result);
}

else if (mode == 1)
{
	printf("\n");
	sprintf(searchSQL, "SELECT * FROM apartment.tenants WHERE Suite LIKE '%%%s%%'", searchTerm);

	executeSQL(mysql, searchSQL);

	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	MYSQL_ROW row;
	int rows = mysql_num_fields(result);

	printf("-----Tenant(s)-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
			counter++;
		}
		printf("\n");
	}

	
	if (counter <= 1)
	{
		printf("Couldn't Find Anything with the Suite Number: '%s'",searchTerm);
		return;
	}

	else 
	{
		printf("Enter the person ID: ");
		fgets(personID, maxSize, stdin);
		personID[strlen(personID)-1] = '\0';
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Emergency Contacts` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Emergency Contact-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Occupiants Info` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Occupiants Info-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.`Parking Spots` WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Parking Spot-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.Reference WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Reference(s)-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	sprintf(searchSQL, "SELECT * FROM apartment.Notes WHERE `Person ID` LIKE '%%%s%%'", personID);
	executeSQL(mysql, searchSQL);
	result = mysql_store_result(mysql);
	fields = mysql_fetch_fields(result);

	rows = mysql_num_fields(result);

	printf("-----Notes-----\n");
	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			printf("%s: %s\n", fields[i].name, row[i]);
		}
		printf("\n");
	}

	free(firstName);
	free(lastName);
	free(personID);
	free(searchSQL);
	mysql_free_result(result);
}
}

int obtainingID(MYSQL *mysql, char *stmt_tr) {

	executeSQL(mysql, stmt_tr);
	char * personID = (char*)malloc(maxSize * sizeof(char));
	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	MYSQL_ROW row;
	int rows = mysql_num_fields(result);

	while((row = mysql_fetch_row(result))){
		for (int i = 0; i < rows; i++)
		{
			if (strcmp(fields[i].name,"Person ID") == 0)
			{
				personID = row[i];
			}	
		}
	}

	

	return atoi(personID);
}


