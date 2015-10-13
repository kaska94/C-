/*
*	Mladen Kralev 2014
*	Last updated 10/20/2015
*	Simple contact telephonebook. Lot's of bugs and bad scripting here.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct personsdData arrayOfPersonsData[MAX];
int current = 0;

int main()
{
	fflush(stdin);
	fflush(stdout);
	int option;

	do {
		option = menu();
		switch (option)
		{
		case 1:
			enter();
			break;
		case 2:
			load();
			break;
		case 3:
			break;
		case 4:
			break;
		}
	} while (1);
	return 0;
}

void display(int i)
{
	if (arrayOfPersonsData[i].name[0] != '\0')
	{
		printf("Name: %s\nPost code: %d\nNumber: %s \n",
			arrayOfPersonsData[i].name, arrayOfPersonsData[i].
			number, arrayOfPersonsData[i].telNumber);
	}
}
int menu()
{
	int number;
	printf("1.Enter\n"
		"2.Load\n"
		"3.Search\n"
		"4.Quit\n");

	scanf_s("%d", &number);
	if (number<1 || number > 4)
		menu();
	return number;
}
void enter()
{
	FILE *fp;
	int i = 0, j = 0;
	errno_t err;

	if ((err = fopen_s(&fp, "DEFAULT", "wb")) != 0)
	{
		printf("I cannot open the file");
		exit(1);
	}
	printf("How many contants you need to add?\n");
	scanf_s("%d", &j);
	do {
		j--;
		fflush(stdin);
		fflush(stdout);

		printf("Enter person's name:\n");
		fgets(arrayOfPersonsData[i].name, 16, stdin);

		if (arrayOfPersonsData[i].name[0] == '\n') break;
		if (arrayOfPersonsData[i].name[0] == '\0') break;
		if (!arrayOfPersonsData[i].name[0]) break;
		fflush(stdin);
		fflush(stdout);

		printf("Enter person's post number:\n");
		scanf_s("%d", &(arrayOfPersonsData[i].number));


		fflush(stdin);
		fflush(stdout);
		printf("Enter person's Number:\n");
		fgets(arrayOfPersonsData[i].name, 16, stdin);


		fflush(stdin);
		fflush(stdout);
		i++;
	} while (j>0);

	current = i;

	fclose(fp);

	save();
}
void save()
{

	FILE *fp;
	int i;
	errno_t err;
	if ((err = fopen_s(&fp,"DEFAULT", "wb")) != 0)
	{
		printf("I cannot open the file");
		exit(1);
	}
	if (fwrite(&current, sizeof current, 1, fp) != 1)
	{
		printf("Error Reading");
		exit(1);
	}
	for (i = 0; i <= current; i++)
	{
		if (fwrite(&arrayOfPersonsData[i], sizeof(struct personsdData), 1, fp) != 1)
		{
			printf("Error");
			exit(1);
		}
	}
}
void load()
{
	FILE *fp;
	int i;
	errno_t err;
	if ((err = fopen_s(&fp,"DEFAULT", "rb")) != 0)
	{
		printf("I cannot open the file");
		exit(1);
	}
	if (fread(&current, sizeof current, 1, fp) != 1)
	{
		printf("Error Reading");
		exit(1);
	}
	for (i = 0; i <= current; i++)
	{
		if (fread(&arrayOfPersonsData[i], sizeof(struct personsdData), 1, fp) != 1)
		{
			printf("Error");
			exit(1);
		}
	}
	for (i = 0; i <= current; i++)
		display(i);
}






