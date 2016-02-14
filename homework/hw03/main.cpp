//	Created by Frank M. Carrano and Tim Henry.
//	Copyright (c) 2013 __Pearson Education__. All rights reserved.
// E Jo Zimmerman - 110C - Assignment 3
// Creating a double linked list and reverse function

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	cout << "\nThe list contains: " << endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		cout << listPtr->getEntry(pos) << " ";
	} // end for
	cout << endl << endl;
}	// end displayList

void listTester()
{
	ListInterface<string>* listPtr = new LinkedList<string>();
	
	cout << "Testing the Link-Based List:" << endl;
	string data[] = {"one", "two", "three", "four", "five", "six"};
	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	
	for (int i = 0; i < 6; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
		{
			cout << "Inserted " << listPtr->getEntry(i + 1)
			 << " at position " << (i + 1) << endl;
		}
		else
			cout << "Cannot insert " << data[i] << " at position " << (i + 1)
			<< endl;
	}	// end for

	displayList(listPtr);
	
	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
	cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
	
	cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
	
	listPtr->setEntry(3, "THREE");
	cout << "After replacing the entry at position 3 with THREE: ";
	displayList(listPtr);

	listPtr->reverse();

	cout << "After reversing the list: ";
		
	displayList(listPtr);

	cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be THREE" << endl;

	for (int i = 6; i > 0; i--)
	{
		if (listPtr->remove(i))
			cout << "Tail element " << i << " removed.\n";
			
		if (i == 3) // display progress
		{
			cout << "4 elements removed, 'six five' should be left.";
			displayList(listPtr);
		}
	}

	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	
	
} // end listTester



int main()
{
	listTester();
	return 0;
}	// end main

/***** EXPECTED OUTPUT WITH CORRECT INSERT FUNCTION
Testing the Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains 
one two three four five six 

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains 
one two XXX four five six */
