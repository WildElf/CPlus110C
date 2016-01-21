// C++ 110C, Week 1 Exercise A
// reverse a string by only printing out the first character
// Eric Zimmerman
#include<iostream>
#include <string>

using namespace std;

void reverseString(string);

int main()
{
	string input = "";
	
	while (input == "")
	{
		cout << "Enter a string to reverse: ";
		getline(cin, input);
	}
	
	reverseString(input);
	cout << endl;
}

void reverseString(string s)
{	
	if (s.length() > 1)
	{
		reverseString(s.substr(1,s.length()));	
	}

	cout << s[0];
}