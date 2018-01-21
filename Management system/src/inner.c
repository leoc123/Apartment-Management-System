#include "inner.h"
#include "menu.h"

#define host "localhost"
#define user "root"
#define passwd "q"
#define port 0
#define unix_socket NULL
#define client_flag CLIENT_MULTI_STATEMENTS
#define createSQL "CREATE DATABASE "
#define initateSQL "CREATE TABLE Tenants (`Person ID` int AUTO_INCREMENT, Suite varchar(maxSize), `First Name` varchar(maxSize), `Last Name` varchar(maxSize), `Building Address` varchar(maxSize), `Rental Amount of Unit($)` double, `Number of Occupants` int, `Occupied`  varchar(maxSize), `Moved In` varchar(maxSize), `Moved Out` varchar(maxSize), `Rent Increase(%)` varchar(maxSize), PRIMARY KEY (`Person ID`)); CREATE TABLE `Occupiants Info` (`Person ID` int, `First Name` varchar(maxSize), `Last Name` varchar(maxSize), Age int, `Phone Number` varchar(maxSize), `Current Home Address` varchar(maxSize), `Current Home City` varchar(maxSize), `Current Home LandLord's Phone Number` varchar(maxSize), `Current Home Duration` int, `Previous Home Address` varchar(maxSize), `Previous Home City` varchar(maxSize), `Previous Home LandLord's Phone Number` varchar(maxSize), `Previous Home Duration` int, `Current Employer` varchar(maxSize), `Current Employer's PhoneNumber` varchar(maxSize), `Current Job Duration` int, `Previous Employer` varchar(maxSize), `Previous Employer's Phone Number` varchar(maxSize), `Previous Job Duration` int, Occupation varchar(maxSize), `Income Monthly` double, `Income Yearly` double, Bank varchar(maxSize), Relationship varchar(maxSize)); CREATE TABLE Reference (`Person ID` int, `Reference's Name` varchar(maxSize), `Reference's Phone Number` varchar(maxSize), `Reference's Occupation` varchar(maxSize)); CREATE TABLE `Emergency Contacts` (`Person ID` int, `Emergency Name` varchar(maxSize), `Phone Number` varchar(maxSize)); CREATE TABLE `Parking Spots` (`Person ID` int, `Make Of Car` varchar(maxSize), Colour varchar(maxSize), Year int, `LIC of Car` varchar(maxSize), `Driver's LIC` varchar(maxSize), Amount double); CREATE TABLE Notes (`Person ID` int, Notes varchar(maxSize));"
#define SQL "SELECT * FROM "
#define obtainingIDSQL "SELECT * FROM apartment.Tenants ORDER BY `Person ID` DESC LIMIT 1"

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

	MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);
	int error = 0;

	char * suite = (char*)malloc(maxSize * sizeof(char));
	int suiteNumber;

	char * firstName = (char*)malloc(maxSize * sizeof(char));
	char * lastName = (char*)malloc(maxSize * sizeof(char));
	char * buildingAddress = (char*)malloc(maxSize * sizeof(char));
	char * injectionSQL = (char*)malloc(maxSize * sizeof(char));
	char * movedIN = (char*)malloc(maxSize * sizeof(char));
	char * CurrentlyLiving = "YES";

	char * rentAmount = (char*)malloc(maxSize * sizeof(char));
	double rentAmountNumber;

	char * occupants = (char*)malloc(maxSize * sizeof(char));
	int occupantNumber;


	do{
	
	error = 0;
	printf("Enter Suite Number: ");
	fgets(suite, maxSize, stdin);
	suite[strlen(suite)-1] = '\0';

	if (strlen(suite) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(suite); i++){
		if ((isdigit(suite[i]) == 0) || (atoi(suite) == 0) || (atoi(suite) == 13) || (atoi(suite) == 4))
		{
			if ((strcmp(suite, "3A") == 0) || (strcmp(suite, "3a") == 0) || (strcmp(suite, "12a") == 0) || (strcmp(suite, "12A") == 0))
			{
				if ((strcmp(suite, "3A") == 0) || (strcmp(suite, "3a") == 0)){

					error = 0;
					break;
				}

				else if ((strcmp(suite, "12A") == 0) || (strcmp(suite, "12a") == 0))
				{
					error = 0;
					break;
				}
			}

			else
			{
				error = 1;
				break;
			}
		}
	}
}
	if (error == 1)
	{
		printf("\nInvalid Input\n");
	}

	else {

		printf("%s", suite);
	}

}while(error == 1);

printf("\nEnter First Name: ");
fgets(firstName, maxSize, stdin);
firstName[strlen(firstName)-1] = '\0';

printf("\nEnter Last Name: ");
fgets(lastName, maxSize, stdin);
lastName[strlen(lastName)-1] = '\0';


do {
	error = 0;
printf("\nWhich Building Will the tenant take?\n");
printf("6 Saranac Blvd (1) OR 6 Convington RD (2): ");
fgets(buildingAddress, maxSize, stdin);
buildingAddress[strlen(buildingAddress)-1] = '\0';

if ((strlen(buildingAddress) <= 0) || atoi(buildingAddress) >= 3 || atoi(buildingAddress) == 0 || strlen(buildingAddress) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(buildingAddress, "1") == 0) {
		buildingAddress = "6 Saranac Blvd";
	}

	else
	{
		buildingAddress = "30 Convington RD";
	}
}

}while(error == 1);

	do{
	
	error = 0;
	printf("\nEnter Rent Amount: ");
	fgets(rentAmount, maxSize, stdin);
	rentAmount[strlen(rentAmount)-1] = '\0';

	if (strlen(rentAmount) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(rentAmount); i++){
		if ((isdigit(rentAmount[i]) == 0) || (atoi(rentAmount) == 0))
		{
				error = 1;
				break;
		}
	}
}
	if (error == 1)
	{
		printf("\nInvalid Input");
	}

	else {

		rentAmountNumber = atof(rentAmount);
	}

}while(error == 1);

do{
	
	error = 0;
	printf("\nNumber of Occupants that will live in the unit: ");
	fgets(occupants, maxSize, stdin);
	occupants[strlen(occupants)-1] = '\0';

	if (strlen(occupants) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(occupants); i++){
		if ((isdigit(occupants[i]) == 0) || (atoi(occupants) == 0))
		{
				error = 1;
				break;
		}
	}
}
	if (error == 1)
	{
		printf("\nInvalid Input");
	}

	else {

		occupantNumber = atof(occupants);
	}

}while(error == 1);


printf("\nWhen will the Tenant move in (MM/DD/YY): ");
fgets(movedIN, maxSize, stdin);
movedIN[strlen(movedIN)-1] = '\0';



sprintf(injectionSQL, "INSERT INTO `apartment`.`Tenants` (`Suite`, `First Name`, `Last Name`, `Building Address`, `Rental Amount of Unit`, `Number of Occupants`, `Currently Living`, `Moved In`) VALUES ('%s', '%s', '%s', '%s', '%lf', '%d', '%s', '%s');", suite, firstName, lastName, buildingAddress, rentAmountNumber, occupantNumber, CurrentlyLiving, movedIN);
executeSQL(connection, injectionSQL);


obtainingID(connection, obtainingIDSQL);

}


