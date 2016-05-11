#include "NotFoundException.h"
#include "Person.h"
#include "PersonDictionary.h"
#include <iostream>
#include <string>

using namespace std;

int birthdayMenu()
{
	int menuChoice;
	
	cout << "*** Birthday Dictionary ***\n";
	cout << "1) Add a new entry\n";
	cout << "2) Remove an entry\n";
	cout << "3) Find an entry\n";	
	cout << "4) List all entries\n";
	cout << "5) List all in a month\n";
	cout << "6) Quit **\n";
	cin >> menuChoice;
	cin.ignore(256, '\n');

	return menuChoice;
}

Person add()
{
	string name;
	int month;
	int day;
	
	cout << "Enter name: ";
	getline(cin,name);

	cout << "Enter birth month (numerical): ";
	cin >> month;
	
	cout << "Enter day of month: ";
	cin >> day;
	cin.ignore(256, '\n');
	
	Person p(name,month,day);
	
	return p;
}

bool findBirthday(const PersonDictionary &b)
{
	bool success;
	string searchName;

	cout << "Enter the name (exactly) to search for.\n";
	getline(cin,searchName);

	try
	{
		b.getBirthday(searchName);
		success = true;	
	}
	catch (NotFoundException e)
	{
		cout << "Entry not found... ";
		success = false;
	}

	if (success)
		b.getBirthday(searchName).print();

	return success;
}

int getMonth()
{
	int month;

	cout << "Enter the month to list all birthdays:\n";
	cin >> month;
	
	return month;
}

string getString(string action)
{
	string val;

	cout << "Enter the name (exactly) to " + action + ": ";
	getline(cin,val);

	return val;
}

bool birthdayFunction(PersonDictionary &birthday)
{
	int option;
	bool success = false;
	option = birthdayMenu();

	while (!(option >= 1 && option ))
	{
		cin.clear();
		cin.ignore();
		cout << "\n***BAD ENTRY - TRY AGAIN***\n";

		option = birthdayMenu();
	}

	if (option == 6)
		return success;
	else if (option == 1)
	{
		Person p = add();
		success = birthday.add(p);
	}
	else if (option == 2)
		success = birthday.remove(getString("remove"));
	else if (option == 3)
	{
		success = findBirthday(birthday);
	}
	else if (option == 4)
	{
		birthday.listAll();
		success = true;
	}
	else if (option == 5)
	{
		birthday.listMonth(getMonth());
		success = true;
	}

	if (success)
		cout << "Success.\n";
	else
		cout << "Sorry, I got nothing.";
		
	return success;

/* non-user controlled code, saved for posterity
	Person bob("Bob Belcher",7,4);
	Person linda("Linda Belcher",9,20);
	Person fischoeder("Calvin Fischoeder",3,28);
	Person tiny("Tina Belcher",4,1);
	Person mort("Mort",10,31);
	Person teddy("Teddy",11,13);
	Person ollie("Ollie Pesto",2,19);
	Person andy("Andy Pesto",2,20);

//	birthday.listAll();
	
	Person twinBob = bob;

	birthday.add(bob);
//	birthday.add(twinBob);

	birthday.add(linda);
	birthday.add(teddy);
	birthday.add(new Person("Louise Belcher",5,14));
	if (!birthday.add(fischoeder))
		fischoeder.print();
	
	birthday.remove("Louise Belcher");

	birthday.add(mort);
	birthday.add(ollie);
	birthday.add(andy);

	cout << "All entries...\n";
	birthday.listAll();
	
	cout << "Birthdays in Feb...\n";
	birthday.listMonth(2);

*/
}

int main()
{
	PersonDictionary dictionary;

	while(birthdayFunction(dictionary))
		cout << endl;

}