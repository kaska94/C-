#include "Employee.h"
using namespace std;

Employee::Employee(char* F_name, int f_size, char* M_name, int m_size, char* L_name, int l_size, int EGN[], double salary)
{
	this->f_size = f_size + 1;
	this->F_name = new char[this->f_size];
	if (F_name == nullptr)
	{
		cout << "Error: memory could not be allocated" << endl;
	}

	this->m_size = m_size + 1;
	this->M_name = new char[this->m_size];
	if (M_name == nullptr)
	{
		cout << "Error: memory could not be allocated" << endl;
	}

	this->l_size = l_size + 1;
	this->L_name = new char[this->l_size];
	if (L_name == nullptr)
	{
		cout << "Error: memory could not be allocated" << endl;
	}

	this->EGN = new int[10];
	if (EGN == nullptr)
	{
		cout << "Error: memory could not be allocated" << endl;
	}

	for (int i = 0; i < this->f_size; i++)
	{
		this->F_name[i] = F_name[i];
	}
	for (int i = 0; i < this->m_size; i++)
	{
		this->M_name[i] = M_name[i];
	}
	for (int i = 0; i < this->l_size; i++)
	{
		this->L_name[i] = L_name[i];
	}
	for (int i = 0; i < 10; i++)
	{
		this->EGN[i] = EGN[i];
	}
	this->salary = salary;
}
Employee::Employee()
{

}
Employee::~Employee()
{
	delete[] this->F_name;
	delete[] this->M_name;
	delete[] this->L_name;
	delete[] this->EGN;
}

bool operator>(Employee& e1, Employee& e2)
{
	return e1.salary > e2.salary;
}

bool operator==(Employee& e1, Employee& e2)
{
	return e1.salary == e2.salary;
}
Employee& Employee::operator=(const Employee& e1)
{
	if (this != &e1)
	{
		if ((F_name != NULL) && (M_name != NULL) && (L_name != NULL))
		{
			delete[] F_name;
			delete[] M_name;
			delete[] L_name;
		}
			f_size = e1.f_size;
			F_name = new char[f_size];
			for (int i = 0; i < f_size; i++)
				F_name[i] = e1.F_name[i];

			m_size = e1.m_size;
			M_name = new char[m_size];
			for (int i = 0; i < m_size; i++)
				M_name[i] = e1.M_name[i];

			l_size = e1.l_size;
			L_name = new char[l_size];
			for (int i = 0; i < l_size; i++)
				L_name[i] = e1.L_name[i];

			EGN = e1.EGN;
			EGN = new int[10];
			for (int i = 0; i < 10; i++)
				EGN[i] = e1.EGN[i];

			salary = e1.salary;
		
	}
	return *this;
}
void Employee::show_info()
{
	cout << this->F_name << " " << this->M_name << " " << this->L_name << " " <<
		"with EGN " << int_array_to_string(this->EGN, EGN_CONST) << " and Salary " << this->salary << endl;
}

char* int_array_to_string(int int_array[], int size_of_array)
{
	
	char* returnstring = new char[size_of_array+1];
	int temp_i;
	int temp;
	for (temp = 0 ; temp < size_of_array; temp++)
	{
		temp_i = int_array[temp] + 48;
		returnstring[temp] = temp_i;
	}
	returnstring[temp] = '\0';
	return returnstring;
}
void Employee::sort(Employee arr_of_empl[], int size_of_array)
{
	Employee temp;
	for (int i = (size_of_array - 1); i > 0; i--)
	{
		for (int j = 0; j < (i - 1); j++)
		{
			if (arr_of_empl[j] > arr_of_empl[j + 1])
			{
				temp = arr_of_empl[j];
				arr_of_empl[j] = arr_of_empl[j + 1];
				arr_of_empl[j + 1] = temp;
			}
		}
	}
}

char* Employee::get_F_name()
{
	return this->F_name;
}
char* Employee::get_M_name()
{
	return this->M_name;
}
char* Employee::get_L_name()
{
	return this->L_name;
}
int* Employee::get_EGN()
{
	return this->EGN;
}
double Employee::get_Salary()
{
	return this->salary;
}
