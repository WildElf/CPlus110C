// E Jo Zimmerman CS110C
// Assignment 7: Palindrome
// A palin-drone to detect palindromes using a stack and a queue
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include <iostream>
#include <string>

using namespace std;

// clears passed stack and queue arrays
// returns false if either fill before string 
bool stackAndQueue(string s, ArrayStack &stack, ArrayQueue &queue)
{
	// ensure a clear stack & queue to start
	while (!stack.isEmpty())
		stack.pop();
	while (!queue.isEmpty())
		queue.dequeue();

	bool filled = false;
	int index = 0;
	// test the success of the queue and stack while incrementing index
	while (index<s.length() && queue.enqueue(s.at(index)) && stack.push(s.at(index)))
		index++;

	if (index < s.length()) // loop failed before the end of the string
	{
		cout << "\"" << s << "\" too large \nto test with a size of " << s.length() << " characters.\n";
		filled = true;
	}
	else // string successfully imported
		cout << "\"" << s << "\" being tested with a size of " << s.length() << ".\n";
		
	return !filled;

}

// takes a string, an empty stack, and empty queue
// empties stack & queue if not empty
bool isPalindrome(string s, ArrayStack &stack, ArrayQueue &queue)
{
	// use import test as a primary determinant
	bool palindrome = stackAndQueue(s, stack, queue);

	while (palindrome && !queue.isEmpty())
	{
		if (stack.peek() == queue.peekFront())
		{
			stack.pop();
			queue.dequeue();
		}
		else
			palindrome = false;
	}
	cout << endl;
	return palindrome;
}

void queueTester()
{
	ArrayQueue forQueue;

	cout << "**Start test:\n";
	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 1)\n";
	cout << "Removing item: " << forQueue.dequeue() << " (should be 0)\n";
	cout << "\nAdding f: " << forQueue.enqueue('f') << " (should be 1)\n";
	cout << "Adding i: " << forQueue.enqueue('i') << " (should be 1)\n";
	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 0)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 1)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 0)\n";
	cout << "\nPeeking at front: " << forQueue.peekFront() << " (should be 'f')\n";
	cout << "Removing item: " << forQueue.dequeue() << " (should be 1)\n";
	cout << "Removing item: " << forQueue.dequeue() << " (should be 1)\n";
	cout << "Adding o: " << forQueue.enqueue('o') << " (should be 1)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 1)\n";

	cout << "\nPeeking at the queue and dequeuing... ";
	while (!forQueue.isEmpty())
	{
		cout << forQueue.peekFront();
		forQueue.dequeue();
	}
	cout << " (should be 'lol')\n";
	
	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 1)\n";
}

int main()
{
//	queueTester();
	
	ArrayStack backStack;
	ArrayQueue forQueue;

	string test = "kinikinik";

	if (isPalindrome(test, backStack, forQueue))
		cout << test << " is a palindrome\n\n";
	else	
		cout << test << " failed the palindrome test.\n\n";

	test = "able was I ere I saw elba";
	if (isPalindrome(test, backStack, forQueue))
		cout << test << " is a palindrome\n\n";
	else	
		cout << test << " failed the palindrome test.\n\n";

	test = "acrobats stab orca";
	if (isPalindrome(test, backStack, forQueue))
		cout << test << " is a palindrome\n\n";
	else	
		cout << test << " failed the palindrome test.\n\n";
		
	test = "For up to 10% extra credit, implement your queue using this approach.";
	if (isPalindrome(test, backStack, forQueue))
		cout << test << " is a palindrome\n\n";
	else	
		cout << test << " failed the palindrome test.\n\n";

}

/* Sample output
"kinikinik" being tested with a size of 9.

kinikinik is a palindrome

"able was I ere I saw elba" being tested with a size of 25.

able was I ere I saw elba is a palindrome

"acrobats stab orca" being tested with a size of 18.

acrobats stab orca failed the palindrome test.

"For up to 10% extra credit, implement your queue using this approach." too large 
to test with a size of 69 characters.

For up to 10% extra credit, implement your queue using this approach. failed the palindrome test.
*/
