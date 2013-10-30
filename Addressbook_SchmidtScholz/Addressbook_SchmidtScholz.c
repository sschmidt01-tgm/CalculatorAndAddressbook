/*
Name of file	: Addressbuch_SchmidtScholz.c
Author			: Samuel Schmidt <sschmidt01@student.tgm.ac.at>, Scholz Dominik <dscholz@student.tgm.ac.at>
Version			: 1
Description		: Simple Calculator
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
	char firstname[NAME];
	char lastname[NAME];
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
char display[MAX];

int main()
{
	int menuChoice;
	char linebreak;
	Person person;

	printf("Simple Addressbook\nEnter (1-4)+Linebreak\n 1> Display Entries\n 2> New Entry\n 3> Delete Entry\n 4> Exit\n");
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
	abf = fopen("AddressBook.txt","a+");

	printf("Please Enter the Details(followed by linebreak/enter)\n Person:\n  First Name:\n   ");
	scanf("%s", person.firstname);

	printf("  Last Name:\n   ");
	scanf("%s", person.lastname);

	printf("  Phonenumber:\n   ");
	scanf("%s", &person.phone);

	printf("  E-mail:\n   ");
	scanf("%s", &person.email);
		
	printf(" Address:\n  Street:\n   ");
	scanf("%s", &address.street);

	printf("  Housenumber:\n   ");
	scanf("%s", &address.housenumber);

	fprintf(abf,"%s %s %s %s \n", person.firstname,  person.lastname, person.email, person.phone, address.street, address.housenumber);
	fclose(abf);

}

void deleteEntry()
{
	abf = fopen("AddressBook.txt","r");
	fclose(abf);

}


void displayEntries()
{
	abf = fopen("AddressBook.txt","r");
	

	while(fgets(display, MAX, abf))
	{
		printf("%s\n", display);
	}

	fclose(abf);
}