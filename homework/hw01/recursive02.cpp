// CS 110C, Assignment 1, Part 2
// Eric Zimmerman
// Rewrite the function writeBackward2 on page 61 of the text as a C++ function.  You 
// may use either C-strings (char *)  or C++ string objects for the string.  
#include <iostream>
#include <string>

using namespace std;

void writeBackward2(string s)
{
	cout << "Entering writerBackward2 with string: " << s << endl;
	
	if (s == "")
		3 + 2;
		// nothing happens
	else
	{
		writeBackward2(s.substr(1,s.length()));
		cout << "About to write first character of string: " << s << endl;
		cout << s[0];
	}
	cout << "Leaving writeBackward2 with string: " << s << endl;
}

int main()
{
	string s = "recursion";
	
	writeBackward2(s);
}

/* 
Entering writerBackward2 with string: recursion
Entering writerBackward2 with string: ecursion
Entering writerBackward2 with string: cursion
Entering writerBackward2 with string: ursion
Entering writerBackward2 with string: rsion
Entering writerBackward2 with string: sion
Entering writerBackward2 with string: ion
Entering writerBackward2 with string: on
Entering writerBackward2 with string: n
Entering writerBackward2 with string: 
Leaving writeBackward2 with string: 
About to write first character of string: n
nLeaving writeBackward2 with string: n
About to write first character of string: on
oLeaving writeBackward2 with string: on
About to write first character of string: ion
iLeaving writeBackward2 with string: ion
About to write first character of string: sion
sLeaving writeBackward2 with string: sion
About to write first character of string: rsion
rLeaving writeBackward2 with string: rsion
About to write first character of string: ursion
uLeaving writeBackward2 with string: ursion
About to write first character of string: cursion
cLeaving writeBackward2 with string: cursion
About to write first character of string: ecursion
eLeaving writeBackward2 with string: ecursion
About to write first character of string: recursion
rLeaving writeBackward2 with string: recursion
*/
