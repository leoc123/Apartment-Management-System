#include "inner.h"
#include "menu.h"

#define host "localhost"
#define user "root"
#define passwd "q"
#define port 0
#define unix_socket NULL
#define client_flag CLIENT_MULTI_STATEMENTS
#define createSQL "CREATE DATABASE "
#define initateSQL "CREATE TABLE Tenants (`Person ID` int AUTO_INCREMENT, Suite varchar(255), `First Name` varchar(255), `Last Name` varchar(255), `Building Address` varchar(255), `Rental Amount of Unit` double, `Number of Occupants` int, `Currently Living`  varchar(255), PRIMARY KEY (`Person ID`)); CREATE TABLE `Occupiants Info` (`Person ID` int, `First Name` varchar(255), `Last Name` varchar(255), Age int, `Phone Number` varchar(255), `Current Home Address` varchar(255), `Current Home City` varchar(255), `Current Home LandLord's Phone Number` varchar(255), `Current Home Duration` int, `Previous Home Address` varchar(255), `Previous Home City` varchar(255), `Previous Home LandLord's Phone Number` varchar(255), `Previous Home Duration` int, `Current Employer` varchar(255), `Current Employer's PhoneNumber` varchar(255), `Current Job Duration` int, `Previous Employer` varchar(255), `Previous Employer's Phone Number` varchar(255), `Previous Job Duration` int, Occupation varchar(255), `Income Monthly` double, `Income Yearly` double, Bank varchar(255), Relationship varchar(255)); CREATE TABLE Reference (`Person ID` int, `Reference's Name` varchar(255), `Reference's Phone Number` varchar(255), `Reference's Occupation` varchar(255)); CREATE TABLE `Emergency Contacts` (`Person ID` int, `Emergency Name` varchar(255), `Phone Number` varchar(255)); CREATE TABLE `Parking Spots` (`Person ID` int, `Make Of Car` varchar(255), Colour varchar(255), Year int, `LIC of Car` varchar(255), `Driver's LIC` varchar(255), Amount double); CREATE TABLE Notes (`Person ID` int, Notes varchar(255));"
#define SQL "SELECT * FROM "

void function1() {

	
		MYSQL * connection = estConnection(host, user, passwd, NULL, port, unix_socket,  client_flag);
		char * dbName = (char*)malloc(maxSize * sizeof(char));
		char * execute = (char*)malloc(maxSize * sizeof(char));

		printf("\nEnter database name to be created: ");

		fgets(dbName, maxSize, stdin);
		dbName[strlen(dbName)-1] = '\0';

		strcpy(execute, createSQL);
		strcat(execute, dbName);

		executeSQL(connection, execute);
		printf("%s database has been created!\n", dbName);

		connection = estConnection(host, user, passwd, dbName, port, unix_socket,  client_flag);

		executeSQL(connection, initateSQL);
		printf("Setup is now Complete");

		free(dbName);
		free(execute);
}

void function2() {

	char * userInput = "Testing";
	char * fullName = (char*)malloc(maxSize * sizeof(char));
	

	while ((strcmp(userInput, "name") != 0) && (strcmp(userInput, "suite") != 0) && (strcmp(userInput, "Name") != 0) && (strcmp(userInput, "Suite") != 0))  {
		userInput = (char*)malloc(maxSize * sizeof(char));

		printf("Enter Name or Suite: ");

		fgets(userInput, maxSize, stdin);
		userInput[strlen(userInput)-1] = '\0';

		if ((strcmp(userInput, "name") != 0) && (strcmp(userInput, "suite") != 0) && (strcmp(userInput, "Name") != 0) && (strcmp(userInput, "Suite") != 0))
		{
			printf("Invalid Input\n");
		}
	}

	if ((strcmp(userInput, "name") == 0) || (strcmp(userInput, "Name")) == 0) {

		MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);

		printf("\nEnter Full Name: ");
		fgets(fullName, maxSize, stdin);
		fullName[strlen(fullName)-1] = '\0';

		print(connection, fullName, 0);
	}

	else if ((strcmp(userInput, "suite") == 0) || (strcmp(userInput, "Suite")) == 0) {

		MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);

		printf("\nEnter Suite Number: ");
		fgets(fullName, maxSize, stdin);
		fullName[strlen(fullName)-1] = '\0';

		print(connection, fullName, 1);
	}

	free(userInput);
	free(fullName);
}

void function3() {

	

}
	



