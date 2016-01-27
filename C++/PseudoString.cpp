#include "PseudoString.h"
using namespace std;
PseudoString::PseudoString(int size)
{

	this->size = size + 1;
	this->p_to = new char[size + 1];
	cout << "Constructed!" << endl;
	if (p_to == nullptr)
	{
		cout << "Error: memory could not be allocated";
	}
}

PseudoString::PseudoString()
{
	size = 1;
	p_to = new char[size];
	p_to[0] = '\0';
}

PseudoString::~PseudoString()
{
	cout << "Destroy!" << endl;
	delete[] p_to;
}
PseudoString::PseudoString(const PseudoString& str)
{
	size = str.size;  // we know this is correct!
	p_to = new char[size];
	for (int i = 0; i < (str.size - 1); i++)
	{
		p_to[i] = str.p_to[i];
	}
	cout << "Coppy constructor called" << endl;
}

PseudoString operator+(const PseudoString& str1, const PseudoString& str2)
{
	int temp_size = (str1.size - 1) + (str2.size - 1) + 1;
	char * temp = new char[temp_size + 1];
	for (int i = 0; i < (str1.size - 1); i++)
	{
		temp[i] = str1.p_to[i];
	}

	int j = 0;
	for (short k = str2.size - 1, j = 0; k < (temp_size); k++, j++)
	{
		temp[k] = str2.p_to[j];
	}

	temp[temp_size - 1] = '\0';

	PseudoString return_string(temp_size);
	return_string.enterString(temp);
	return_string.show();
	return return_string;
}
PseudoString& PseudoString::operator =(const PseudoString &str)
{
	size = str.size;
	delete[] p_to;
	p_to = new char[size + 1];
	for (int i = 0; i < (size - 1);i++)
	{
		p_to[i] = str.p_to[i];
	}
	p_to[(size - 1)] = '\0';
	return *this;
}




void PseudoString::show()
{
	int n;
	cout << "You have entered: ";
	for (n = 0; n< size; n++)
		cout << p_to[n] << ", ";
	cout << endl;
}
void PseudoString::enterString(char *str)
{
	int n;

	for (n = 0; n < size; n++)
	{
		p_to[n] = str[n];
	}

	p_to[size - 1] = '\0';
	cout << "Size" << size << endl;
}