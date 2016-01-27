// ProjectTuIII.cpp.cpp : Defines the entry point for the console application.
//

#include <iostream> 
#include <fstream>

using namespace std;
#include "PseudoString.h"
#include "Employee.h"



int main()
{
	const int EMPLOYEE_NUMBER = 4;
	int arr_EGN[][EGN_CONST] = {
							{ 9,4,0,4,1,4,1,4,6,1 },
							{ 8,7,6,5,4,3,2,4,5,2 }, 
							{ 8,0,0,0,0,0,0,0,0,0 },
							{ 8,7,7,7,7,7,7,7,7,2 }
												};
	Employee arr[EMPLOYEE_NUMBER] = {
							Employee("Mladen",6,"Ivanov", 6 , "Kralev", 6, arr_EGN[0], 300.2),
							Employee("Stefan",6,"Krasimirov", 10 , "Petkov", 6, arr_EGN[1], 233.3),
							Employee("Plamen",6,"Rozenov", 7 , "Dimitrov", 8, arr_EGN[2], 600.3),
							Employee("Krasimir",8,"Ivanov", 6 , "Kralev", 6, arr_EGN[3], 565.6),
												};

	arr[0].show_info();
	arr[1].show_info();
	arr[2].show_info();
	arr[3].show_info();

	Employee::sort(arr, EMPLOYEE_NUMBER);
	cout << "After efect" << endl;

	arr[0].show_info();
	arr[1].show_info();
	arr[2].show_info();
	arr[3].show_info();

	ofstream myfile;
	myfile.open("example.txt");
	myfile.flush();

	myfile << "   " << "Firstname " << "Middlename " << "Lastname " << "EGN  " << "Salary" << endl;
	for (int i = 0; i < EMPLOYEE_NUMBER; i++)
	{
		myfile << i+1 << ". " << arr[i].get_F_name() << " " << arr[i].get_M_name() << " " << arr[i].get_L_name()
			<< " " << int_array_to_string(arr[i].get_EGN(), EGN_CONST) << " " << arr[i].get_Salary() << endl;
	}
	myfile.close();

    return 0;
}

