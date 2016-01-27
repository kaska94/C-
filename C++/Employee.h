#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

const int EGN_CONST = 10;


class Employee
{
public:

	Employee(char* F_name, int f_size, char* M_name, int m_size, char* L_name, int l_size, int EGN[], double salary);
	Employee();
	~Employee();

	friend bool operator>(Employee& e1, Employee& e2);
	friend bool operator ==(Employee& e1, Employee& e2);
	Employee& operator=(const Employee& e1);

	friend char* int_array_to_string(int int_array[], int size_of_array);
	static void sort(Employee arr_empl[], int size_of_the_array);
	void show_info();
	char* get_F_name();
	char* get_M_name();
	char* get_L_name();
	int* get_EGN();
	double get_Salary();
private:

	char* F_name;
	int f_size;
	char* M_name;
	int m_size;
	char* L_name;
	int l_size;
	int *EGN;
	double salary;

};

#endif