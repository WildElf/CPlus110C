#include "ArrayStack.h"

bool ArrayStack::isEmpty()
{
	return (top == 0);
}

bool ArrayStack::push(char value)
{
	bool success = false;
	if (top < SIZE)
	{
		theStack[top] = value;
		top++;
		success = true;
	}
	
	return success;
}

char ArrayStack::peek()
{
	return theStack[top-1];
}

bool ArrayStack::pop()
{
	bool success = false;
	if (top >= 0)
	{
		theStack[top] = 0;
		top--;
		success = true;
	}
	return success;	
}
