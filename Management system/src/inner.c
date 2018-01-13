#include "inner.h"
#include "menu.h"

#define host "XXX"
#define user "XXX"
#define passwd "XXX"
#define port 0
#define unix_socket NULL
#define client_flag 0
#define createSQL "CREATE DATABASE "
#define SQL1 "CREATE TABLE Tenants (PersonID int AUTO_INCREMENT, Suite varchar(255), FirstName varchar(255), LastName varchar(255), buildingAddress varchar(255), rentalAmount double, OccupyAmount int, currentlyLiving int, PRIMARY KEY (PersonID));"
#define SQL2 "CREATE TABLE OccupiantsInfo (PersonID int, FirstName varchar(255), LastName varchar(255), Age int, PhoneNumber varchar(255));"
#define SQL3 "CREATE TABLE previousLandLords (PersonID int, CurrAddress varchar(255), CurrCity varchar(255), CurrlandlordPhoneNumber varchar(255), Currduration int, PrevAddress varchar(255), PrevCity varchar(255), PrevlandlordPhoneNumber varchar(255), Prevduration int, CurrHusbandEmployer varchar(255), CurrHusbandEmployerPhoneNumber varchar(255), CurrHusbandDuration int, PrevHusbandEmployer varchar(255), PrevHusbandEmployerPhoneNumber varchar(255), PrevHusbandDuration int, HusbandOccupation varchar(255), HusbandIncomeMonthly double, HusbandBank varchar(255), CurrWifeEmployer varchar(255), CurrWifeEmployerPhoneNumber varchar(255), CurrWifeDuration int, PrevWifeEmployer varchar(255), PrevWifeEmpliyerPhoneNumber varchar(255), PrevWifeDuration int, WifeOccupation varchar(255), WifeIncomeMonthly double, WifeBank varchar(255));"
#define SQL4 "CREATE TABLE Reference (PersonID int, ReferenceName varchar(255), PhoneNumber varchar(255));"
#define SQL5 "CREATE TABLE EmergencyContact (PersonID int, EmergName varchar(255), PhoneNumber varchar(255));"
#define SQL6 "CREATE TABLE parkingSpot (PersonID int, MakeOfCar varchar(255), ColourOfCar varchar(255), Year int, LIC varchar(255), HusbandDriverLIC varchar(255), WifeDriverLIC varchar(255), Name varchar(255), Amount double);"
#define SQL7 "CREATE TABLE Notes (PersonID int, Notes varchar(255));"
#define SQL8 "SELECT * FROM "

void function1() {

	
		MYSQL * connection = estConnection(host, user, passwd, NULL, port, unix_socket,  client_flag);
		char * dbName = (char*)malloc(maxSize * sizeof(char));
		char * excute = (char*)malloc(maxSize * sizeof(char));

		printf("\nEnter database name to be created: ");

		fgets(dbName, maxSize, stdin);
		dbName[strlen(dbName)-1] = '\0';

		strcpy(excute, createSQL);
		strcat(excute, dbName);

		createDB(connection, excute);
}

void function2() {

	int counter = 1;
	MYSQL * connection = estConnection(host, user, passwd, NULL, port, unix_socket,  client_flag);
	char * userInput = (char*)malloc(maxSize * sizeof(char));

	printf("Select Database to initate Scripts\n");

	printDatabase(connection);

	printf("Enter Database: ");
	fgets(userInput, maxSize, stdin);
	userInput[strlen(userInput)-1] = '\0';

	while(counter != 8) {
	connection = estConnection(host, user, passwd, userInput, port, unix_socket,  client_flag);
	
	if (counter == 1)
	{
		 executeSQL(connection, SQL1);
	}

	else if (counter == 2)
	{
		executeSQL(connection, SQL2);
	}

	else if (counter == 3)
	{
		executeSQL(connection, SQL3);
	}

	else if (counter == 4)
	{
		executeSQL(connection, SQL4);
	}

	else if (counter == 5)
	{
		executeSQL(connection, SQL5);
	}

	else if (counter == 6)
	{
		executeSQL(connection, SQL6);
	}

	else if (counter == 7){
		executeSQL(connection, SQL7);
	}
	counter++;
}
	free(userInput);

	}

void function3() {

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

	if (strcmp(userInput, "name") || strcmp(userInput, "Name")) {

		MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);

		printf("\nEnter Full Name: ");
		fgets(fullName, maxSize, stdin);
		fullName[strlen(fullName)-1] = '\0';

		print(connection, fullName);
	}

	free(userInput);
	free(fullName);
}
	



