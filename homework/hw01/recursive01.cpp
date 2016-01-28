// CS 110C, Assignment 1, Part 1
// Eric Zimmerman
// Chapter 2, exercise 9: Write a recursive C++ function that writes the digits of a 
// positive decimal integer in reverse order.  Hint: 2015 % 10 == 5, 2015 / 10 == 201.  
// Example: if given the integer 2015, your function should write out: 5102. 
#include <iostream>

using namespace std;

void reverseDigit(int x)
{
	if (x < 10)
		cout << x << endl;
	else
	{
		cout << x % 10;
		reverseDigit(x / 10);
	}
}

int main ()
{
	unsigned int x;
	
	cout << "Enter a number two or more digits in length: ";
	cin >> x;
	
	reverseDigit(x);

}

/*
Enter a number two or more digits in length: 89
98
Silica:hw01 ez$ a.out 
Enter a number two or more digits in length: 2015
5102
Silica:hw01 ez$ a.out 
Enter a number two or more digits in length: 18945
54981
*/
