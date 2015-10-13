#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_
#define MAX 30

int menu();
void enter();
void load();
void save();
void display(int i);

struct personsdData
{
	char name[16];
	int number;
	char telNumber[16];
};


#endif // FOO_H_
