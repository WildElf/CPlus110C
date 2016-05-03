// Assignment 10, Emergency Room
// E. Jo Zimmerman, 110C
// Patient class definition & implementation
#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <iostream>

using namespace std;

class Patient
{
private:
	string name;
	int priority;
public:
	// constructors
	Patient()
	{ name = "Unknown"; priority = 0; }
	Patient(string s, int p)
	{ name = s; priority = p; }

	// name methods
	void setName(string s)
	{ name = s; }
	string getName()
	{ return name; }
	void printName()
	{ cout << name; }

	// priority methods
	void setPriority(int p)
	{ priority = p; }
	int getPriority()
	{ return priority; }
	bool operator<(Patient p)
	{ return (priority < p.priority); }
	bool operator>(Patient p)
	{ return (priority > p.priority); }
	Patient operator=(Patient p)
	{ name = p.name; priority = p.priority;
		return *this; }
};


#endif