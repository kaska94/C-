#pragma once
#ifndef PSEUDOSTRING_H
#define PSEUDOSTRING_H
#include <iostream>

class PseudoString
{
public:
	PseudoString(int size);
	PseudoString();
	PseudoString(const PseudoString& str);//Copy constructor
	~PseudoString();
	void show();
	void enterString(char* str);

	friend PseudoString operator+(const PseudoString& str1, const PseudoString& str2);
	PseudoString& operator = (const PseudoString& S);
	//bool is_containing_numbers();
private:
	char *p_to;
	int size;
};

#endif
