#include "inner.h"
#include "menu.h"

#define host "localhost"
#define user "root"
#define passwd "q"
#define port 0
#define unix_socket NULL
#define client_flag CLIENT_MULTI_STATEMENTS
#define createSQL "CREATE DATABASE "
#define initateSQL "CREATE TABLE Tenants (`Person ID` int AUTO_INCREMENT, Suite varchar(255), `First Name` varchar(255), `Last Name` varchar(255), `Building Address` varchar(255), `Rental Amount of Unit($)` double, `Number of Occupants` int, `Occupied`  int, `Moved In` varchar(255), `Moved Out` varchar(255), `Rent Increase(%)` double, `Total Rent($)` double, `Own a parking Spot` int,  PRIMARY KEY (`Person ID`)); CREATE TABLE `Occupiants Info` (`Person ID` int, `First Name` varchar(255), `Last Name` varchar(255), Age int, `Phone Number` varchar(255), `Current Home Address` varchar(255), `Current Home City` varchar(255), `Current Home LandLord's Phone Number` varchar(255), `Current Home Duration` varchar(255), `Previous Home Address` varchar(255), `Previous Home City` varchar(255), `Previous Home LandLord's Phone Number` varchar(255), `Previous Home Duration` varchar(255), `Current Employer` varchar(255), `Current Employer's PhoneNumber` varchar(255), `Current Job Duration` varchar(255), `Previous Employer` varchar(255), `Previous Employer's Phone Number` varchar(255), `Previous Job Duration` varchar(255), Occupation varchar(255), `Income Monthly` double, `Income Yearly` double, Bank varchar(255), Relationship varchar(255)); CREATE TABLE Reference (`Person ID` int, `Reference's Name` varchar(255), `Reference's Phone Number` varchar(255), `Reference's Occupation` varchar(255)); CREATE TABLE `Emergency Contacts` (`Person ID` int, `Emergency Name` varchar(255), `Phone Number` varchar(255)); CREATE TABLE `Parking Spots` (`Person ID` int, `Make Of Car` varchar(255), Colour varchar(255), Year int, `LIC of Car` varchar(255), `Driver's LIC` varchar(255), Amount double, Name varchar(255)); CREATE TABLE Notes (`Person ID` int, Notes varchar(255));"
#define SQL "SELECT * FROM "
#define obtainingIDSQL "SELECT * FROM apartment.Tenants ORDER BY `Person ID` DESC LIMIT 1"

void function1() {

	
		MYSQL * connection = estConnection(host, user, passwd, NULL, port, unix_socket,  client_flag);
		char * dbName = (char*)malloc(255 * sizeof(char));
		char * execute = (char*)malloc(255 * sizeof(char));

		printf("\nEnter database name to be created: ");

		fgets(dbName, 255, stdin);
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
	char * fullName = (char*)malloc(255 * sizeof(char));
	

	while ((strcmp(userInput, "name") != 0) && (strcmp(userInput, "suite") != 0) && (strcmp(userInput, "Name") != 0) && (strcmp(userInput, "Suite") != 0))  {
		userInput = (char*)malloc(255 * sizeof(char));

		printf("Enter Name or Suite: ");

		fgets(userInput, 255, stdin);
		userInput[strlen(userInput)-1] = '\0';

		if ((strcmp(userInput, "name") != 0) && (strcmp(userInput, "suite") != 0) && (strcmp(userInput, "Name") != 0) && (strcmp(userInput, "Suite") != 0))
		{
			printf("Invalid Input\n");
		}
	}

	if ((strcmp(userInput, "name") == 0) || (strcmp(userInput, "Name")) == 0) {

		MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);

		printf("\nEnter Full Name: ");
		fgets(fullName, 255, stdin);
		fullName[strlen(fullName)-1] = '\0';

		print(connection, fullName, 0);
	}

	else if ((strcmp(userInput, "suite") == 0) || (strcmp(userInput, "Suite")) == 0) {

		MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);

		printf("\nEnter Suite Number: ");
		fgets(fullName, 255, stdin);
		fullName[strlen(fullName)-1] = '\0';

		print(connection, fullName, 1);
	}

	free(userInput);
	free(fullName);
}

void function3() {

	MYSQL * connection = estConnection(host, user, passwd, "Apartment", port, unix_socket,  client_flag);
	int error = 0;

	char * suite = (char*)malloc(255 * sizeof(char));
	int personID;
char * repeat = (char*)malloc(255 * sizeof(char));
	char * firstName = (char*)malloc(255 * sizeof(char));
	char * lastName = (char*)malloc(255 * sizeof(char));
	char * buildingAddress = (char*)malloc(255 * sizeof(char));
	char * injectionSQL = (char*)malloc(400 * sizeof(char));

	
	char * movedIN = (char*)malloc(255 * sizeof(char));
	


	


	char * parkingSpot = (char*)malloc(255 *sizeof(char));
	int parkingSpotNumber;

	int CurrentlyLiving = 1;

	char * rentAmount = (char*)malloc(255 * sizeof(char));
	double rentAmountNumber;

	char * occupants = (char*)malloc(255 * sizeof(char));
	int occupantNumber;

	

	printf("---Tenants---\n");
	do{
	
	error = 0;
	printf("Enter Suite Number: ");
	fgets(suite, 255, stdin);
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

}while(error == 1);

printf("\nEnter First Name: ");
fgets(firstName, 255, stdin);
firstName[strlen(firstName)-1] = '\0';

printf("\nEnter Last Name: ");
fgets(lastName, 255, stdin);
lastName[strlen(lastName)-1] = '\0';


do {
	error = 0;
printf("\nWhich Building Will the tenant take?\n");
printf("6 Saranac Blvd (1) OR 6 Convington RD (2): ");
fgets(buildingAddress, 255, stdin);
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
	fgets(rentAmount, 255, stdin);
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
	fgets(occupants, 255, stdin);
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
fgets(movedIN, 255, stdin);
movedIN[strlen(movedIN)-1] = '\0';

do {
	error = 0;
printf("\nWill the tenant acquire a parking spot\n");
printf("Yes (1) or No (2): ");
fgets(parkingSpot, 255, stdin);
parkingSpot[strlen(parkingSpot)-1] = '\0';

if ((strlen(parkingSpot) <= 0) || atoi(parkingSpot) >= 3 || atoi(parkingSpot) == 0 || strlen(parkingSpot) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(parkingSpot, "1") == 0) {
		parkingSpotNumber = 1;
	}

	else
	{
		parkingSpotNumber = 0;
	}
}

}while(error == 1);

sprintf(injectionSQL, "INSERT INTO `apartment`.`Tenants` (`Suite`, `First Name`, `Last Name`, `Building Address`, `Rental Amount of Unit($)`, `Number of Occupants`, `Occupied`, `Moved In`, `Own a parking Spot`) VALUES ('%s', '%s', '%s', '%s', '%lf', '%d', '%d', '%s', '%d');", suite, firstName, lastName, buildingAddress, rentAmountNumber, occupantNumber, CurrentlyLiving, movedIN, parkingSpotNumber);

executeSQL(connection, injectionSQL);
personID = obtainingID(connection, obtainingIDSQL);
free(suite);
free(firstName);
free(lastName);
free(movedIN);
free(rentAmount);
free(occupants);
free(injectionSQL);

do{
	repeat = (char*)malloc(255 * sizeof(char));
	char * occupantsSQL = (char*)malloc(1000 * sizeof(char));
	char * phoneNumber = (char*)malloc(255 * sizeof(char));
	char * currentHomeAddress = (char*)malloc(255 * sizeof(char));
	char * currentHomeCity = (char*)malloc(255 * sizeof(char));
	char * currentHomeLandLordPhoneNumber = (char*)malloc(255 * sizeof(char));
	char * currentHomeDuration = (char*)malloc(255 * sizeof(char));
	char * previousHomeAddress = (char*)malloc(255 * sizeof(char));
	char * previousHomeCity = (char*)malloc(255 * sizeof(char));
	char * previousHomeLandLordPhoneNumber = (char*)malloc(255 * sizeof(char));
	char * previousHomeDuration = (char*)malloc(255 * sizeof(char));
	char * currentEmployer = (char*)malloc(255 * sizeof(char));
	char * currentEmployerPhoneNumber = (char*)malloc(255 * sizeof(char));
	char * currentJobDuration = (char*)malloc(255 * sizeof(char));
	char * previousEmployer = (char*)malloc(255 * sizeof(char));
	char * previousEmployerPhoneNumber = (char*)malloc(255 * sizeof(char));
	char * previousJobDuration = (char*)malloc(255 * sizeof(char));
	char * job = (char*)malloc(255 * sizeof(char));
	char * bank = (char*)malloc(255 * sizeof(char));
	char * relationship = (char*)malloc(255 * sizeof(char));

	char * incomeMonthly = (char*)malloc(255 * sizeof(char));
	double incomeMonthlyNumber;

	char * incomeYearly = (char*)malloc(255 * sizeof(char));
	double incomeYearlyNumber;

	char * age = (char*)malloc(255 * sizeof(char));
	int ageNumber;

	char * firstName2 = (char*)malloc(255 * sizeof(char));
	char * lastName2 = (char*)malloc(255 * sizeof(char));


printf("\n---Occupiants Info---");
printf("\nEnter First Name: ");
fgets(firstName2, 255, stdin);
firstName2[strlen(firstName2)-1] = '\0';

printf("\nEnter Last Name: ");
fgets(lastName2, 255, stdin);
lastName2[strlen(lastName2)-1] = '\0';

do{
	
	error = 0;
	printf("\nEnter Age: ");
	fgets(age, 255, stdin);
	age[strlen(age)-1] = '\0';

	if (strlen(age) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(age); i++){
		if ((isdigit(age[i]) == 0) || (atoi(age) == 0))
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
		ageNumber = atoi(age);
	}

}while(error == 1);

printf("\nEnter Phone Number (XXX)-(XXX)-(XXXX): ");
fgets(phoneNumber, 255, stdin);
phoneNumber[strlen(phoneNumber)-1] = '\0';

printf("\nEnter Current Home Address: ");
fgets(currentHomeAddress, 255, stdin);
currentHomeAddress[strlen(currentHomeAddress)-1] = '\0';

printf("\nEnter Current Home City: ");
fgets(currentHomeCity, 255, stdin);
currentHomeCity[strlen(currentHomeCity)-1] = '\0';

printf("\nEnter Current Home LandLord's PhoneNumber (XXX)-(XXX)-(XXXX): ");
fgets(currentHomeLandLordPhoneNumber, 255, stdin);
currentHomeLandLordPhoneNumber[strlen(currentHomeLandLordPhoneNumber)-1] = '\0';

printf("\nEnter Current Home Duration: ");
fgets(currentHomeDuration, 255, stdin);
currentHomeDuration[strlen(currentHomeDuration)-1] = '\0';

printf("\nEnter Previous Home Address: ");
fgets(previousHomeAddress, 255, stdin);
previousHomeAddress[strlen(previousHomeAddress)-1] = '\0';

printf("\nEnter Previous Home City: ");
fgets(previousHomeCity, 255, stdin);
previousHomeCity[strlen(previousHomeCity)-1] = '\0';

printf("\nEnter Previous Home LandLord's Phone Number (XXX)-(XXX)-(XXXX): ");
fgets(previousHomeLandLordPhoneNumber, 255, stdin);
previousHomeLandLordPhoneNumber[strlen(previousHomeLandLordPhoneNumber)-1] = '\0';

printf("\nEnter Previous Home Duration: ");
fgets(previousHomeDuration, 255, stdin);
previousHomeDuration[strlen(previousHomeDuration)-1] = '\0';

printf("\nEnter Current Employer: ");
fgets(currentEmployer, 255, stdin);
currentEmployer[strlen(currentEmployer)-1] = '\0';

printf("\nEnter Current Employer's Phone Number (XXX)-(XXX)-(XXXX): ");
fgets(currentEmployerPhoneNumber, 255, stdin);
currentEmployerPhoneNumber[strlen(currentEmployerPhoneNumber)-1] = '\0';

printf("\nEnter Current Job Duration: ");
fgets(currentJobDuration, 255, stdin);
currentJobDuration[strlen(currentJobDuration)-1] = '\0';

printf("\nEnter Previous Employer: ");
fgets(previousEmployer, 255, stdin);
previousEmployer[strlen(previousEmployer)-1] = '\0';

printf("\nEnter Previous Employer's Phone Number (XXX)-(XXX)-(XXXX): ");
fgets(previousEmployerPhoneNumber, 255, stdin);
previousEmployerPhoneNumber[strlen(previousEmployerPhoneNumber)-1] = '\0';

printf("\nEnter Previous Job Duration: ");
fgets(previousJobDuration, 255, stdin);
previousJobDuration[strlen(previousJobDuration)-1] = '\0';

printf("\nEnter Occupation: ");
fgets(job, 255, stdin);
job[strlen(job)-1] = '\0';

do{
	
	error = 0;
	printf("\nEnter Monthly Income: ");
	fgets(incomeMonthly, 255, stdin);
	incomeMonthly[strlen(incomeMonthly)-1] = '\0';

	if (strlen(incomeMonthly) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(incomeMonthly); i++){
		if ((isdigit(incomeMonthly[i]) == 0) || (atoi(incomeMonthly) == 0))
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
		incomeMonthlyNumber = atof(incomeMonthly);
	}

}while(error == 1);

do{
	
	error = 0;
	printf("\nEnter Yearly Income: ");
	fgets(incomeYearly, 255, stdin);
	incomeYearly[strlen(incomeYearly)-1] = '\0';

	if (strlen(incomeYearly) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(incomeYearly); i++){
		if ((isdigit(incomeYearly[i]) == 0) || (atoi(incomeYearly) == 0))
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
		incomeYearlyNumber = atof(incomeYearly);
	}

}while(error == 1);

printf("\nEnter Bank Branch: ");
fgets(bank, 255, stdin);
bank[strlen(bank)-1] = '\0';

printf("\nEnter Relationship: ");
fgets(relationship, 255, stdin);
relationship[strlen(relationship)-1] = '\0';

do {
	error = 0;
printf("\nInsert Another Entry?\n");
printf("YES (1) OR NO (2): ");
fgets(repeat, 255, stdin);
repeat[strlen(repeat)-1] = '\0';

if ((strlen(repeat) <= 0) || atoi(repeat) >= 3 || atoi(repeat) == 0 || strlen(repeat) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(repeat, "1") == 0) {
		repeat = "1";
	}

	else
	{
		repeat = "0";
	}
}

}while(error == 1);
sprintf(occupantsSQL, "INSERT INTO `apartment`.`Occupiants Info` (`Person ID`,`First Name`, `Last Name`, `Age`, `Phone Number`, `Current Home Address`, `Current Home City`, `Current Home LandLord's Phone Number`, `Current Home Duration`, `Previous Home Address`, `Previous Home City`, `Previous Home LandLord's Phone Number`, `Previous Home Duration`, `Current Employer`, `Current Employer's PhoneNumber`, `Current Job Duration`, `Previous Employer`, `Previous Employer's Phone Number`, `Previous Job Duration`, `Occupation`, `Income Monthly`, `Income Yearly`, `Bank`, `Relationship`) VALUES ('%d','%s', '%s', '%d', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s','%s', '%s', '%s', '%s', '%s', '%s', '%lf', '%lf', '%s','%s');",personID, firstName2,lastName2,ageNumber,phoneNumber,currentHomeAddress,currentHomeCity,currentHomeLandLordPhoneNumber,currentHomeDuration,previousHomeAddress,previousHomeCity,previousHomeLandLordPhoneNumber,previousHomeDuration,currentEmployer,currentEmployerPhoneNumber,currentJobDuration,previousEmployer,previousEmployerPhoneNumber,previousJobDuration,job,incomeMonthlyNumber,incomeYearlyNumber,bank,relationship);
executeSQL(connection,occupantsSQL);
free(firstName2);
free(lastName2);
free(age);
free(phoneNumber);
free(currentHomeAddress);
free(currentHomeLandLordPhoneNumber);
free(currentHomeCity);
free(currentHomeDuration);
free(previousHomeAddress);
free(previousHomeCity);
free(previousHomeLandLordPhoneNumber);
free(previousHomeDuration);
free(currentEmployer);
free(currentEmployerPhoneNumber);
free(currentJobDuration);
free(previousEmployer);
free(previousEmployerPhoneNumber);
free(previousJobDuration);
free(job);
free(incomeMonthly);
free(incomeYearly);
free(bank);
free(relationship);
free(occupantsSQL);
}while(strcmp(repeat, "1") == 0);

do{
	repeat = (char*)malloc(255 * sizeof(char));
	char * referenceName = (char*)malloc(255 * sizeof(char));
	char * referencePhoneNumber = (char*)malloc(255 * sizeof(char));
	char * referenceJob = (char*)malloc(255 * sizeof(char));
	char * referenceSQL = (char*)malloc(400 * sizeof(char));

printf("\n---References---");

printf("\nEnter Reference's Name: ");
fgets(referenceName, 255, stdin);
referenceName[strlen(referenceName)-1] = '\0';

printf("\nEnter Reference's Phone Number (XXX)-(XXX)-(XXXX): ");
fgets(referencePhoneNumber, 255, stdin);
referencePhoneNumber[strlen(referencePhoneNumber)-1] = '\0';

printf("\nEnter Reference's Occupation: ");
fgets(referenceJob, 255, stdin);
referenceJob[strlen(referenceJob)-1] = '\0';

do {
	error = 0;
printf("\nInsert Another Entry?\n");
printf("YES (1) OR NO (2): ");
fgets(repeat, 255, stdin);
repeat[strlen(repeat)-1] = '\0';

if ((strlen(repeat) <= 0) || atoi(repeat) >= 3 || atoi(repeat) == 0 || strlen(repeat) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(repeat, "1") == 0) {
		repeat = "1";
	}

	else
	{
		repeat = "0";
	}
}

}while(error == 1);
sprintf(referenceSQL, "INSERT INTO `apartment`.`reference` (`Person ID`,`Reference's Name`, `Reference's Phone Number`, `Reference's Occupation`) VALUES ('%d','%s','%s','%s');",personID,referenceName,referencePhoneNumber,referenceJob);
executeSQL(connection, referenceSQL);
free(referenceName);
free(referencePhoneNumber);
free(referenceJob);
free(referenceSQL);
}while(strcmp(repeat, "1") == 0);

if (parkingSpotNumber == 1)
{
	do{
	repeat = (char*)malloc(255 * sizeof(char));
	char * makeOfCar = (char*)malloc(255 * sizeof(char));
	char * colour = (char*)malloc(255 * sizeof(char));
	char * year = (char*)malloc(255 * sizeof(char));
	char * licOFCAR = (char*)malloc(255 * sizeof(char));
	char * driveLIC = (char*)malloc(255 * sizeof(char));
	char * name = (char*)malloc(255 * sizeof(char));
	char * amount = (char*)malloc(255 * sizeof(char));
	double amountNumber;
	char * parkingSpotSQL = (char*)malloc(400 * sizeof(char));
	char *amountUpdateSQL = (char*)malloc(400 * sizeof (char));

printf("\n---Parking Spots---");

printf("\nEnter Name: ");
fgets(name, 255, stdin);
name[strlen(name)-1] = '\0';

printf("\nEnter Make Of Car: ");
fgets(makeOfCar, 255, stdin);
makeOfCar[strlen(makeOfCar)-1] = '\0';

printf("\nEnter Colour of Car: ");
fgets(colour, 255, stdin);
colour[strlen(colour)-1] = '\0';

printf("\nEnter Year of Car: ");
fgets(year, 255, stdin);
year[strlen(year)-1] = '\0';

printf("\nEnter License of Car: ");
fgets(licOFCAR, 255, stdin);
licOFCAR[strlen(licOFCAR)-1] = '\0';

printf("\nEnter Driver License: ");
fgets(driveLIC, 255, stdin);
driveLIC[strlen(driveLIC)-1] = '\0';

do{
	
	error = 0;
	printf("\nEnter Amount: ");
	fgets(amount, 255, stdin);
	amount[strlen(amount)-1] = '\0';

	if (strlen(amount) < 1)
	{
		error = 1;
	}

	else
	{
		for (int i = 0; i < strlen(amount); i++){
		if ((isdigit(amount[i]) == 0) || (atoi(amount) == 0))
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
		amountNumber = atof(amount);
	}

}while(error == 1);

do {
	error = 0;
printf("\nInsert Another Entry?\n");
printf("YES (1) OR NO (2): ");
fgets(repeat, 255, stdin);
repeat[strlen(repeat)-1] = '\0';

if ((strlen(repeat) <= 0) || atoi(repeat) >= 3 || atoi(repeat) == 0 || strlen(repeat) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(repeat, "1") == 0) {
		repeat = "1";
	}

	else
	{
		repeat = "0";
	}
}

}while(error == 1);
sprintf(parkingSpotSQL, "INSERT INTO `apartment`.`Parking Spots` (`Person ID`,`Make Of Car`, `Colour`, `Year`, `LIC of Car`, `Driver's LIC`, `Amount`, `Name`) VALUES ('%d','%s','%s','%s','%s','%s','%lf','%s');",personID,makeOfCar,colour,year,licOFCAR,driveLIC,amountNumber,name);
sprintf(amountUpdateSQL, "UPDATE apartment.Tenants SET `Total Rent($)`='%lf' WHERE `Person ID` ='%d'", amountNumber+rentAmountNumber, personID);
executeSQL(connection, parkingSpotSQL);
executeSQL(connection, amountUpdateSQL);
free(makeOfCar);
free(colour);
free(year);
free(licOFCAR);
free(driveLIC);
free(amount);
free(name);
free(parkingSpotSQL);
free(amountUpdateSQL);
}while(strcmp(repeat, "1") == 0);
}

else
{
	char *amountUpdateSQL = (char*)malloc(400 * sizeof (char));
	sprintf(amountUpdateSQL, "UPDATE apartment.Tenants SET `Total Rent($)`='%lf' WHERE `Person ID` ='%d'", rentAmountNumber, personID);
	executeSQL(connection, amountUpdateSQL);
	free(amountUpdateSQL);
}


do{
	repeat = (char*)malloc(255 * sizeof(char));
	char * emergName = (char*)malloc(255 * sizeof(char));
	char * emergPhoneNumber = (char*)malloc(255 * sizeof(char));
	char * emergSQL = (char*)malloc(400 * sizeof(char));

printf("\n---Emergency Contacts---");

printf("\nEnter Emergency Name: ");
fgets(emergName, 255, stdin);
emergName[strlen(emergName)-1] = '\0';

printf("\nEnter Emergency Phone Number: ");
fgets(emergPhoneNumber, 255, stdin);
emergPhoneNumber[strlen(emergPhoneNumber)-1] = '\0';

do {
	error = 0;
printf("\nInsert Another Entry?\n");
printf("YES (1) OR NO (2): ");
fgets(repeat, 255, stdin);
repeat[strlen(repeat)-1] = '\0';

if ((strlen(repeat) <= 0) || atoi(repeat) >= 3 || atoi(repeat) == 0 || strlen(repeat) > 1) {
	error = 1;
}

else
{
	error = 0;
	if (strcmp(repeat, "1") == 0) {
		repeat = "1";
	}

	else
	{
		repeat = "0";
	}
}

}while(error == 1);
sprintf(emergSQL, "INSERT INTO `apartment`.`Emergency Contacts` (`Person ID`,`Emergency Name`, `Phone Number`) VALUES ('%d','%s','%s');",personID,emergName,emergPhoneNumber);
executeSQL(connection, emergSQL);
free(emergName);
free(emergPhoneNumber);
free(emergSQL);
}while(strcmp(repeat, "1") == 0);








}


