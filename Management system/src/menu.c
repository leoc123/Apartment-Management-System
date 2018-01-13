#include "menu.h"
#include "inner.h"



void menu()
{
	int lock = 0;
	char * userInput;

	while(lock == 0) {	
	userInput = (char*)malloc(maxSize * sizeof(char));
	
	printf("\nMySQL Client Version %s\n", mysql_get_client_info());
	printf("\n1. Create new DB\n");
	printf("2. Init Table(s)\n");
	printf("3. Print\n");
	printf("4. Add\n");
	printf("5. Edit\n");
	printf("6, Delete\n");
	printf("7. Exit\n");
	printf("Enter Option: ");

	fgets(userInput, maxSize, stdin);
	userInput[strlen(userInput)-1] = '\0';
	

	if ((strlen(userInput) > 1) || (atoi(userInput) == 0)) {

		printf("Invalid Input.\n");
		free(userInput);
	}

	else {

		if (strcmp(userInput, "1") == 0) {

			function1();

		}

		else if (strcmp(userInput, "2") == 0) {
			function2();
		}

		else if (strcmp(userInput, "3") == 0) {
			function3();

		}

		else if (strcmp(userInput, "4") == 0) {


		}

		else if (strcmp(userInput, "5") == 0) {


		}

		else if (strcmp(userInput, "6") == 0) {
			

		}

		else if (strcmp(userInput, "7") == 0) {
				lock = 1;

		}
	}
}

}
