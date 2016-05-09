#include "NotFoundException.h"
#include "Person.h"
#include "PersonDictionary.h"
#include <iostream>
#include <string>

using namespace std;

int birthdayMenu()
{
	cout << "*** Birthday Dictionary ***\n";
	
	return 0;
}

bool birthdayFunction()
{
	int option;
	PersonDictionary birthday;
	
	option = birthdayMenu();
	
	Person bob("Bob Belcher",7,4);
	Person linda("Linda Belcher",9,20);
	Person fischoeder("Calvin Fischoeder",3,28);
	Person larry("Larry Someguy",4,1);
	
	birthday.listAll();
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 0)\n";
	
	Person twinBob = bob;

	birthday.add(bob);
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 1)\n";

	birthday.add(twinBob);
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 1)\n";

	birthday.add(linda);
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 2)\n";
	birthday.add(larry);
	birthday.add(new Person("Gary",5,14));
	if (!birthday.add(fischoeder))
		fischoeder.print();
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 5)\n";

	birthday.remove("Gary");
	cout << "Birthday size: " << birthday.getDictSize() << " (should be 4)\n";

	birthday.listAll();

	return false;
}

int main()
{
	while(birthdayFunction())
		cout << endl;

}