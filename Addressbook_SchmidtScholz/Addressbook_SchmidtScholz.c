/*
Name of file	: Addressbook_SchmidtScholz.c
Author			: Samuel Schmidt <sschmidt01@student.tgm.ac.at>, Scholz Dominik <dscholz@student.tgm.ac.at>
Version			: 1
Description		: Simple Addressbook
*/

/*
TODO
				: %s alternative bei fprintf in newEntry() finden
				: dynamischer Speicher um beim Hinzufuegen von neuen Personen nicht auf einen statischen Wert berschraenkt zu sein
				: deleteEntry implementieren
				: Bugs finden und terminieren
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NAME 50
#define PHONE 20
#define EMAIL 30
#define ADDRESS 40
#define HNR 10
#define MAX NAME+ADDRESS+PHONE+EMAIL

/* Structs */
typedef struct
{
	char name[NAME];
	char phone[PHONE];
	char email[EMAIL];
} Person;
typedef struct
{
	char street[ADDRESS];
	char housenumber[ADDRESS];
} Address;

/* Prototypes */
void displayEntries();
void newEntry();
void deleteEntry();

FILE *abf;
FILE *temp;
char display[MAX];

int main()
{
	int menuChoice;
	char linebreak;
	Person person;

	printf(" 1> Display Entries\n 2> New Entry\n 3> Delete Entry\n 4> Exit\n");
	if(!(scanf("%d%c", &menuChoice, &linebreak) == 2 ||linebreak == 10 || (menuChoice >= 1 && menuChoice <= 4))){
		printf("Follow the instructions!\n");
		getch();
		return EXIT_FAILURE;
	}
	

	switch(menuChoice){
		case 1:
			displayEntries();
			main();
			break;
		case 2:
			newEntry();
			main();
			break;
		case 3:
			deleteEntry();
			main();
			break;
		case 4:
			return EXIT_SUCCESS;
			break;
		default:
			break;
	}
	getch();
	return EXIT_SUCCESS;
}

/* Functions */
void newEntry()
{
	Person person;
	Address address;

	printf("Please Enter the Details(followed by linebreak/enter)\n Person:\n  Name:\n   ");
	gets(person.name);

	printf("  Phonenumber:\n   ");
	gets(person.phone);

	printf("  E-mail:\n   ");
	gets(person.email);
		
	printf(" Address:\n  Street:\n   ");
	gets(address.street);

	printf("  Housenumber:\n   ");
	gets(address.housenumber);

	abf = fopen("AddressBook_SchmidtScholz.txt","a+");
	fprintf(abf,"%s, %s, %s, %s, %s \n", person.name, person.email, person.phone, address.street, address.housenumber);
	fclose(abf);

}

void deleteEntry()
{
	/*
	abf = fopen("AddressBook_SchmidtScholz.txt","r");
	char email[EMAIL];
	printf("Enter Email");
	scanf("%s", &email);
	



	fclose(abf);
	*/

}


void displayEntries()
{
	if((abf=fopen("AddressBook_SchmidtScholz.txt","r"))==NULL){
		printf("\n\nAddressBook_SchmidtScholz.txt does not exist\n\n");
	}
	else{
		printf("\n\nName, E-mail, Phone, Street, Housenumber\n\n");

		while(fgets(display, MAX, abf))
		{
			printf("%s", display);
		}

		printf("\n");
		fclose(abf);
	}
}