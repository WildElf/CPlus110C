// Assignment 11: Birthdays
// E Jo Zimmerman, 110C
// Implementation of a Person based dictionary
// with O(log n) search using binary tree structure + hash table
#include "PersonDictionary.h"


PersonDictionary::PersonDictionary()
{
	numPersons = 0; 
	maxSize = 29; 
	dictionary = new Person[maxSize];
	
}

int PersonDictionary::binarySearch(string s, int min, int max)
{	
	int search;
	bool found = false;
	
	while (min <= max && !found)
	{
		search = (min+max)/2;

		if (dictionary[search] > s)
			max = search-1;
		else if (dictionary[search] < s)
			min = search+1;
		else // (dictionary[search] == s) exactly
			found = true;
	}

	if (!found)
		search *= -1;
		
	if (!found && search == 0)
		cout << "not found and search is 0\n";

	return search;
}

int PersonDictionary::binarySearch(Person p, int min, int max)
{
	return binarySearch((string)(p.getName()), min, max);
}

bool PersonDictionary::isEmpty()
{
	return numPersons == 0;
}

bool PersonDictionary::add(Person p)
{

	bool added = false;
	int insertLocation = -1;

	// can always add if empty
	if (isEmpty())
	{
		insertLocation = numPersons++;
		dictionary[insertLocation] = p;
		added = true;
	}
	else if (numPersons < maxSize) // search for an insertion point
	{
		bool found = false;
		int location;
		int min = 0;
		int max = numPersons;
		
		while (min <= max && !found)
		{
			location = (min+max)/2;

			if (dictionary[location] > p)
				max = location-1;
			else if (dictionary[location] < p)
				min = location+1;
			else // (dictionary[location] == s) exactly
				found = true;
		}
		
		if (max < location)
			insertLocation = min;
		else if (min > location)
			insertLocation = max;
		
		if (!found)
		{
			for (int i = numPersons;i>insertLocation;i--)
				dictionary[i] = dictionary[i-1];
			
			dictionary[insertLocation] = p;
			numPersons++;
			added = true;
		}
	}
		
	return added;
}

bool PersonDictionary::remove(string n)
{
	bool removed = false;
	int removeLocation;
	
	// perform search unless empty
	if (!isEmpty())
		removeLocation = binarySearch(n,0,numPersons);
	else
		removeLocation = -1;

	if (removeLocation >= 0)
	{
		numPersons--;
		
		for (int i=removeLocation;i<numPersons;i++)
			dictionary[i] = dictionary[i+1];
		
		removed = true;		
	}
	
	return removed;
}

Person PersonDictionary::searchName(string n) throw(NotFoundException)
{
	int found = binarySearch(n, 0, numPersons);

	if (found < 0)
	{
		string err = "Entry \"" + n + "\" does not exist";
		throw NotFoundException(err);
	}

	return dictionary[found];			
}

//	Person PersonDictionary::searchMonth(int m) throw(NotFoundException);

//	Person searchDay(int d);

void PersonDictionary::listAll()
{
	if (isEmpty())
		cout << "No birthday entries.\n";
	else
		for (int i=0; i<numPersons; i++)
			dictionary[i].print();	
}

void PersonDictionary::listMonth(int m)
{

}

//	void listDay(int d);
