#include "StackCalculator.h"
#include <iostream>
#include <string>

using namespace std;

bool StackCalculator::convert()
{
	bool success = true;
	string processor = infix;
	int out = 0;
	char* output = new char[size];
	
	// two for infix error checking
	bool lastOperation = true;
	short openParen = 0; 
	
	if (infix == "")
		success = false;
	
	while (processor != "" && success)
	{
	  char &ch = processor.at(0);

	  bool op1 = (ch == '+' || ch == '-');
	  bool op2 = (ch == '*' || ch == '/');
	  bool oParen = (ch == '(');
	  bool cParen = (ch == ')');
	  
	  if (oParen)
	  {
	  	stack.push(ch);

	  	if (!lastOperation)
	  	{
	  		success = false;
	  	}
	  	else
	  		lastOperation = true;	  	
	  }
	  else if (op2 || op1)
	  {
	  	while (!stack.isEmpty() && op2 && (stack.peek() == '*' || stack.peek() == '/'))
	  	{
	  		output[out] = stack.peek();
	  		stack.pop();
	  		out++;
	  	}
	  	while (!stack.isEmpty() && op1 && (stack.peek() == '*' 
	  			|| stack.peek() == '/' || stack.peek() == '+' || stack.peek() == '-'))
	  	{
	  		output[out] = stack.peek();
	  		stack.pop();
	  		out++;
	  	}
	  	stack.push(ch);
	  	
	  	if (lastOperation)
	  	{
	  		success = false;
	  	}
	  	else
	  		lastOperation = true;
	  }
	  else if (cParen)
	  {
	  	while (stack.peek() != '(' && !stack.isEmpty())
	  	{
	  		output[out] = stack.peek();
	  		stack.pop();
	  		out++;
	  	}
	  	
	  	if (stack.isEmpty())
	  		success = false;
		else // pop off the (
	  		stack.pop();
	  	
	  	// closing parens cannot come after an operation, must be followed by one
	  	if (lastOperation)
	  	{
	  		success = false;
	  	}
	  	else
	  		lastOperation = false;
	  }
	  else if ( ch >= 48 && ch <= 57 ) // ASCII numerical range
	  {
	  	output[out] = ch;
	  	out++;
	  	if (lastOperation)
	  		lastOperation = false;
	  	else
	  	{
	  		success = false;
	  	}
	  }
	  else
	  	success = false;
	  	
 	  processor = processor.substr(1,processor.size() - 1);
	}
	
	while (!stack.isEmpty())
	{
		output[out] = stack.peek();
		stack.pop();
		out++;
	}
	
	output[out] = '\0';
	size = out + 1;
	
	delete [] postfix;
	postfix = output;
	
	if (openParen != 0) // check for parenthesis imbalance
		success = false;
	
	return success;
}

int StackCalculator::calculate()
{
	char result;
	bool plus, sub, mult, div;
	plus = sub = mult = div = false;
	int opMode = false;
	int op1,op2;
	
	for (int i=0;i<size && postfix[i] != '\0';i++)
	{	
		plus = postfix[i] == '+';
		sub = postfix[i] == '-';
		mult = postfix[i] == '*'; 
		div = postfix[i] == '/';

		if (plus)
		{
			op2 = stack.peek() - '0';
			stack.pop();
			op1 = stack.peek() - '0';
			stack.pop();
			char calc = (op1 + op2) + '0';
//			cout << op1 << " + " << op2 << " = " << calc << endl;
			stack.push(calc);
		}
		else if (sub)
		{
			op2 = stack.peek() - '0';
			stack.pop();
			op1 = stack.peek() - '0';
			stack.pop();
			char calc = (op1 - op2) + '0';
//			cout << op1 << " - " << op2 << " = " << calc << endl;
			stack.push(calc);
		}
		else if (mult)
		{
			op2 = stack.peek() - '0';
			stack.pop();
			op1 = stack.peek() - '0';
			stack.pop();
			char calc = (op1 * op2) + '0';
//			cout << op1 << " * " << op2 << " = " << calc << endl;
			stack.push(calc);
		}
		else if (div)
		{
			op2 = stack.peek() - '0';
			stack.pop();
			op1 = stack.peek() - '0';
			stack.pop();
			char calc = (op1 / op2) + '0';
//			cout << op1 << " / " << op2 << " = " << calc << endl;
			stack.push(calc);
		}
		else // (!plus && !sub && !mult && !div)
			stack.push(postfix[i]);
	}

	if (!stack.isEmpty())
	{
		result = stack.peek();
		stack.pop();
	}
	else
		cout << "no result was pushed.\n";

	return (result - '0');
}