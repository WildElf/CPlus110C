// Assignment 11: Birthdays
// E Jo Zimmerman, 110C
// A person class that stores a name and birthday
#include "Person.h"

// Constructors
Person::Person()
{
	name = "";
	month = 0;
	day = 0;
	loop = 0;
}

Person::Person(string n, int m, int d)
{
	name = n;
	month = m;
	day = d;
	loop = 0;
}

Person::Person(const Person &p)
{
	*this = p;
}

Person::Person(const Person *p)
{
	*this = *p;
}
// end constructors

// private helper methods
bool Person::validMonth()
{
	return (month > 0 && month < 12);
}

bool Person::validDay()
{
	if (validMonth())
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return (day >= 1 && day <= 30);
		else if (month == 2)
			return (day >= 1 && day <= 29);
		else
			return (day >= 1 && day <= 31);
	}
	else
		return false;
}

string Person::getMonthName()
{
	switch(month) {
		case 1 :
			return "January";
		case 2 :
			return "February";
		case 3 :
			return "March";
		case 4 :
			return "April";
		case 5 :
			return "May";
		case 6 :
			return "June";
		case 7 :
			return "July";
		case 8 :
			return "August";
		case 9 :
			return "September";
		case 10 :
			return "October";
		case 11 :
			return "November";
		case 12 :
			return "December";
		default :
			return "Invalid Month";
	}
}
// end private helper methods

// public methods
void Person::setName(string n)
{
	name = n;
}

void Person::setMonth(int m)
{
	month = m;
}

void Person::setDay(int d)
{
	day = d;
}

void Person::setBirthday(int m, int d)
{
	month = m;
	day = d;
}

void Person::print()
{
	if (name != "" && validMonth() && validDay())
		cout << name << ": " << getMonthName() << " " << day << ".\n";
	else if (!validDay())
		cout << "This entry is invalid.\n";
	else if (!validDay())
		cout << "This entry is invalid.\n";
	else if (name == "")
		cout << "This entry has no name.\n";
}

bool Person::operator<(const Person &p)
{
	return name < p.name;
}

bool Person::operator>(const Person &p)
{
	return name > p.name;
}

bool Person::operator==(const Person &p)
{
	return name == p.name;
}

bool Person::operator<(string n)
{
	return name < n;
}

bool Person::operator>(string n)
{
	return name > n;
}

bool Person::operator==(string n)
{
	return name == n;
}

const Person& Person::operator=(const Person &p)
{
	name = p.name;
	month = p.month;
	day = p.day;
	
	return p;
}
