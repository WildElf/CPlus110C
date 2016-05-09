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
	Person* nextPerson;	
};

class PersonDictionary
{
private:
	Person* dictionary;
	PersonEntry* monthHash[13];
	int numPersons;
	int maxSize;
	int binarySearch(string n, int min, int max);
	int binarySearch(Person p, int min, int max);
public:
	PersonDictionary();
	~PersonDictionary()
	{ delete [] dictionary; }
	bool isEmpty();
	bool add(Person p);
	bool remove(string n);
	Person searchName(string s) throw(NotFoundException);
//	Person searchMonth(int m) throw(NotFoundException);
//	Person searchDay(int d);
	void listAll();
	void listMonth(int m);
//	void listDay(int d);
	int getDictSize()
	{ return numPersons; }
};

#endif
