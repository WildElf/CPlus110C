// E Jo Zimmerman CS110C
// Assignment 6: Calculator
// A postfix calculator using an array stack

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "ArrayStack.h"
#include <string>

using namespace std;

class StackCalculator
{
private:
	ArrayStack stack;
	string infix;
	char* postfix;
	int size;
public:
	StackCalculator()
	{ infix = ""; postfix = new char[50]; size = 50; }
	StackCalculator(string in)
	{ infix = in; size = in.size() + 1; postfix = new char[size]; convert(); }
	~StackCalculator()
	{ delete [] postfix; }
	void setInfix(string in)
	{ infix = in; }
	void setPostfix(string in)
	{ delete [] postfix; postfix = new char[in.size()+1]; strcpy(postfix,(const char*)in.c_str()); }
	bool convert();
	int calculate();
	char* getPostfix()
	{ return postfix; }
};

#endif