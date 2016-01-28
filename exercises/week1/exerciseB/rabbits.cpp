// C++ 110C, Week 1 Exercise B
// Comparing Fibonacci recursion with an iterative approach
#include <iostream>
#include <ctime>

using namespace std;

// pre: n is an int greater than zero 
// post: returns the fibonacci number 
int rabbit(int n)
{ 

 if ((n==1) || (n==2)) 
	 return 1; 
 else 
	 return rabbit(n-1)+rabbit(n-2); 
}

// pre: n is an int greater than zero 
// post: returns the fibonacci number using an iterative approach 
int rabbitIterative(int n) 
{ 
	int current=1, next=1, previous=1; 
	for (int i=3; i<=n; i++) 
 	{ 
		// first, put rabbit(i) into next 
		next = current+previous; 
		// now, set up previous and current for next 
		previous = current; 
		current = next; 
	} 
	return next; 
}

int main()
{
	int rabbits = 45;
	
	time_t start = time(NULL);
	cout << "Fibonacci: ";
	cout << rabbit(rabbits) << endl;
	double fibSeconds = difftime(time(NULL),start);
	
	time_t start = time(NULL);
	cout << "Iterative: ";
	cout << rabbitIterative(rabbits) << endl;
	double itSeconds = difftime(time(NULL),start);
	
	cout << "Fib took " << fibSeconds << " seconds\n";
	cout << "Iterative took " << itSeconds << " seconds\n";

}