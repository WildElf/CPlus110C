// E Jo Zimmerman CS110C
// Assignment 7: Palindrome
// An array queue for a variety of purposes 
// that don't require more than 50 entries
#include "ArrayQueue.h"
#include <iostream>

using namespace std;

bool ArrayQueue::isEmpty()
{
	return (back == front);
}

bool ArrayQueue::enqueue(char value)
{
	bool success = false;

	if (front%(SIZE+1) != (back+1)%(SIZE+1))
	{
		theQueue[++back] = value;
		success = true;
	}
	
	if (back > SIZE)
		back = back%(SIZE+1);

	return success;
}

char ArrayQueue::peekFront()
{
	if (isEmpty())
		return 0;
	else
		return theQueue[front+1];
}

bool ArrayQueue::dequeue()
{
	bool success = false;
	
	if (!isEmpty())
	{
		front++;
		success = true;
	}

	if (front > SIZE)
		front = front%(SIZE+1);

	return success;	
}
