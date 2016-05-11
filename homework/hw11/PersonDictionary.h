// Assignment 11: Birthdays
// E Jo Zimmerman, 110C
// Implementation of a Person based dictionary
// with O(log n) search using binary tree structure + hash reference table
#ifndef PERSON_DICTIONARY_H
#define PERSON_DICTIONARY_H
#include "Person.h"
#include "NotFoundException.h"

struct PersonEntry {
	Person p;
	PersonEntry* nextPerson;	
};

class PersonDictionary
{
private:
	Person* dictionary;
	PersonEntry* monthHash[13];
	int numPersons;
	int maxSize;
	int binarySearch(string n, int min, int max) const;
	int binarySearch(Person p, int min, int max) const;
	PersonEntry* addToMonthHash(Person &p);
	bool removeFromMonthHash(const Person &p);
public:
	PersonDictionary();
	~PersonDictionary()
	{ delete [] dictionary; }
	bool isEmpty();
	bool add(Person p);
	bool remove(string n);
	Person getBirthday(string s) const throw(NotFoundException);
//	void searchMonth(int m) throw(NotFoundException);
//	Person searchDay(int d);
	void listAll();
	void listMonth(int m);
//	void listDay(int d);
};

#endif
