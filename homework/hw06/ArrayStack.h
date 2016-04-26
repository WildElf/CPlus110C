// E Jo Zimmerman CS110C
// Assignment 6: Calculator
// An array stack for a variety of purposes 
// that don't require more than 50 entries

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

int const SIZE = 50;

class ArrayStack
{
private:
	char* theStack;
	int size;
	int top;
public:
	ArrayStack()
		{ theStack = new char[SIZE];
		  top = 0; }
	~ArrayStack()
		{ delete [] theStack; }
	bool isEmpty();
	bool push(char);
	char peek();
	bool pop();
};

#endif