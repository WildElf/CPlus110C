// E Jo Zimmerman CS110C
// Assignment 7: Palindrome
// An array queue for a variety of purposes 
// that don't require more than 50 entries
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#import <iostream>
using namespace std;

class ArrayQueue
{
private:
	static int const SIZE = 50;
	char* theQueue;
	int back;
	int front;
public:
	ArrayQueue()
		{ theQueue = new char[SIZE + 1];
		  front = back = 0; }
	~ArrayQueue()
		{ delete [] theQueue; }
	bool isEmpty();
	bool enqueue(char);
	char peekFront();
	bool dequeue();

};

#endif