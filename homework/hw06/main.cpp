#include "ArrayStack.h"
#include "StackCalculator.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// strings for calculator demonstration
	string infix1 = "8-3+4";
	string infix2 = "8-(3+4)";
	string postfix = "834+-";
	string mulfix = "2+2*3-4";
	string bigfix = "1+(3*2-2)+6/3";
	
	// strings for error tests
	string badOpFix = "1+(3*2--2)+6/3";
	string badPFix = "1+(3*2)-2)+6/3";
	string badNumFix = "1+(32-2)+6/3";
	string veryBadFix = "Go Giants!";

	cout << "\n** infix 1 **\n";
	StackCalculator tony(infix1);
	if (tony.convert())
	{
		cout << "Original infix: " << infix1 << " is now: " << tony.getPostfix() << endl;
		cout << infix1 << " = " << tony.calculate() << endl;
	}
	else
		cout << "** failed **\n";
	
	cout << "\n** infix 2 **\n";
	tony.setInfix(infix2);
	if (tony.convert())
	{
		cout << "Original infix: " << infix2 << " is now: " << tony.getPostfix() << endl;
		cout << infix2 << " = " << tony.calculate() << endl;
	}
	else
		cout << "** failed **\n";
	
	cout << "\n** postfix **\n";
	tony.setPostfix(postfix);
	cout << "Raw postfix input: " << tony.getPostfix() << endl;
	cout << postfix << " = " << tony.calculate() << endl;
	
	cout << "\n** multiplication infix **\n";
	tony.setInfix(mulfix);
	if (tony.convert())
	{
		cout << "Original infix: " << mulfix << " is now: " << tony.getPostfix() << endl;
		cout << mulfix << " = " << tony.calculate() << endl;
	}
	else
		cout << "** failed **\n";
		
	cout << "\n** big infix **\n";
	tony.setInfix(bigfix);
	if (tony.convert())
	{
		cout << "Original infix: " << bigfix << " is now: " << tony.getPostfix() << endl;
		cout << bigfix << " = " << tony.calculate() << endl;
	}
	else
		cout << "** failed **\n";
		
	cout << "\n** bad operator infix **\n";
	tony.setInfix(badOpFix);
	if (tony.convert())
	{
		cout << "Original infix: " << badOpFix << " is now: " << tony.getPostfix() << endl;
		cout << badOpFix << " = " << tony.calculate() << endl;
	}
	else
		cout << badOpFix << " failed ****\n";
		
	cout << "\n** bad parenthesis infix **\n";
	tony.setInfix(badPFix);
	if (tony.convert())
	{
		cout << "Original infix: " << badPFix << " is now: " << tony.getPostfix() << endl;
		cout << badPFix << " = " << tony.calculate() << endl;
	}
	else
		cout << badPFix << " failed ****\n";
		
	cout << "\n** bad number infix **\n";
	tony.setInfix(badNumFix);
	if (tony.convert())
	{
		cout << "Original infix: " << badNumFix << " is now: " << tony.getPostfix() << endl;
		cout << badNumFix << " = " << tony.calculate() << endl;
	}
	else
		cout << badNumFix << " failed ****\n";
		
	cout << "\n** not even an infix **\n";
	tony.setInfix(veryBadFix);
	if (tony.convert())
	{
		cout << "Original infix: " << veryBadFix << " is now: " << tony.getPostfix() << endl;
		cout << veryBadFix << " = " << tony.calculate() << endl;
	}
	else
		cout << veryBadFix << " failed ****\n";
		
}
