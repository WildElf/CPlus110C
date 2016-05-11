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

	for (int i=0;i<13;i++)
		monthHash[i] = nullptr;
}

int PersonDictionary::binarySearch(string s, int min, int max) const
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

	if (!found && search == 0)
		search = -1;
	else if (!found)
		search *= -1;


	return search;
}

int PersonDictionary::binarySearch(Person p, int min, int max) const
{
	return binarySearch((string)(p.getName()), min, max);
}

PersonEntry* PersonDictionary::addToMonthHash(Person &p)
{
	int mon = p.getMonth();
	PersonEntry* pers = new PersonEntry;
	pers->p = p;
	pers->nextPerson = nullptr;
	
	if (monthHash[mon] != nullptr) // no entries for this month
		pers->nextPerson = (PersonEntry*)(monthHash[mon]);
	
//	pers->p.print();
	
	return pers;
}

bool PersonDictionary::removeFromMonthHash(const Person &p)
{
	int m = p.getMonth();
	bool removed = false;

	PersonEntry* thisPerson = monthHash[m];
	PersonEntry* prevPerson = nullptr;
	
	while (thisPerson->p != p || thisPerson == nullptr) // advance until thisPerson == p
	{
		prevPerson = thisPerson;
		thisPerson = monthHash[m]->nextPerson;
	}
	cout << endl;

	if (prevPerson == nullptr) // deleted person was in first entry
	{
		if (thisPerson->nextPerson == nullptr) // deleted person is only entry
			monthHash[m] = nullptr;
		else
			monthHash[m] = thisPerson->nextPerson;
			
		removed = true;
			
	}
	else if (thisPerson->p == p) // found a match
	{
		if (thisPerson->nextPerson == nullptr) // is at the end of the chain
			prevPerson->nextPerson = nullptr;
		else
		{
			prevPerson->nextPerson = thisPerson->nextPerson;
		}
		
		removed = true;
	}
//	else // while reached the end of the chain without finding a match
	
	return removed;

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
//			cout << "Searching " << location << " between " << min << " and " << max << "... ";

			if (dictionary[location] == "")
			{
//				cout << "End of array, " << p.getName() << " probably goes at the end.\n";
				min = location;
				max = 0;
			}
			else if (dictionary[location] > p)
			{
//				cout << dictionary[location].getName() << " > " << p.getName() << ".\n";
				max = location-1;
			}
			else if (dictionary[location] < p)
			{
//				cout << dictionary[location].getName() << " < " << p.getName() << ".\n";
				min = location+1;
			}
			else // (dictionary[location] == s) exactly
			{
//				cout << dictionary[location].getName() << " == " << p.getName() << ".\n";
//				cout << "Crazy town...";
				found = true;
			}
		}
		
		insertLocation = min;
		
		if (!found)
		{
			for (int i = numPersons;i>insertLocation;i--)
				dictionary[i] = dictionary[i-1];
			
			dictionary[insertLocation] = p;
			numPersons++;
			added = true;
		}
	}
	
	if (added)
	{
		string before, after;
		
		if (numPersons == 1)
		{
//			before = "no one";
//			after = "no one";
		}
		else if (insertLocation == 0)
		{
//			after = "no one";
			before = dictionary[insertLocation+1].getName();
		}
		else if (insertLocation == numPersons - 1)
		{
//			before = "no one";
			after = dictionary[insertLocation-1].getName();
		}
		else
		{
			before = dictionary[insertLocation+1].getName();
			after = dictionary[insertLocation-1].getName();
		}
		
//		cout << "Added " << p.getName() << " to position " << insertLocation;
//		cout << " before " << before << " and after " << after << ".\n";
		
		monthHash[p.getMonth()] = addToMonthHash(p);
	}
		
	return added;
}

bool PersonDictionary::remove(string n)
{

	bool removed = false;
	int removeLocation;
	Person deleted;
	
	// perform search unless empty
	if (!isEmpty())
		removeLocation = binarySearch(n,0,numPersons);
	else
		removeLocation = -1;


	if (removeLocation >= 0)
	{
		numPersons--;
		deleted = dictionary[removeLocation]; 

		for (int i=removeLocation;i<numPersons;i++)
			dictionary[i] = dictionary[i+1];
		
		removed = true;		
	}
	
	if (removed) // clean up the monthHash entry
	{
		removed = removeFromMonthHash(deleted);
	}
	
	return removed;
}

Person PersonDictionary::getBirthday(string n) const throw(NotFoundException)
{
	int found = binarySearch(n, 0, numPersons);

	if (found < 0)
	{
		string err = "Entry \"" + n + "\" does not exist";
		throw NotFoundException(err);
	}

	return dictionary[found];			
}

//Person PersonDictionary::searchMonth(int m) throw(NotFoundException)

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
	if (m < 1 || m > 12)
		cout << "Invalid month.\n";
	else if (monthHash[m] == nullptr)
		cout << "No one has a birthday in \"" + to_string(m) + "\" month.\n";
	else
	{
		PersonEntry* found = monthHash[m];
		while (found != nullptr)
		{
			found->p.print();
			found = found->nextPerson;
		}
	}
}	

//	void listDay(int d);
