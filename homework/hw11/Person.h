// Assignment 11: Birthdays
// E Jo Zimmerman, 110C
// A person class that stores a name and birthday
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class Person
{
private:
	string name;
	int month;
	int day;
	bool validMonth();
	bool validDay();
	string getMonthName();
	int loop;
public:
	Person();
	Person(string, int, int);
	Person(const Person &p);
	Person(const Person *p);
	void setName(string n);
	void setMonth(int m);
	void setDay(int d);
	void setBirthday(int m, int d);
	string getName() const
	{ return name; }
	int getMonth() const
	{ return month; }
	void print();
	bool operator<(const Person &p);
	bool operator>(const Person &p);	
	bool operator==(const Person &p);
	bool operator!=(const Person &p);
	bool operator<(string n);
	bool operator>(string n);	
	bool operator==(string n);
	const Person& operator=(const Person& p);
};

#endif

