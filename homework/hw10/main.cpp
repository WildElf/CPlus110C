// Assignment 10, Emergency Room
// E. Jo Zimmerman, 110C
#include "Heap.h"

using namespace std;

int main()
{
	Heap ER;
	Patient helivac1("Rajib",11);
	Patient helivac2("Riha",3);
	
	cout << "The ER is open with " << ER.getNumberOfNodes() << " patients waiting.\n";
	ER.add(Patient("Bob", 5));
	ER.add(Patient("Mary", 9));
	ER.add(Patient("Max", 1));

	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	ER.add(Patient("Julio", 3));

	cout << "The ER is open with " << ER.getNumberOfNodes() << " patients waiting.\n";
	ER.add(Patient("Stacy", 7));
	ER.add(Patient("Paul", 4));
	ER.add(Patient("Reiko", 2));
	ER.add(Patient("Jennifer", 6));
	ER.add(Patient("Chang", 5));

	cout << "The ER is open with " << ER.getNumberOfNodes() << " patients waiting.\n";
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << "The ER is open with " << ER.getNumberOfNodes() << " patients waiting.\n";
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	ER.add(Patient("Betta", 6));
	ER.add(helivac1);
	ER.add(helivac2);

	cout << "The ER is open with " << ER.getNumberOfNodes() << " patients waiting.\n";
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	
	cout << "The ER is closing with " << ER.getNumberOfNodes() << " patient waiting.\n";
	cout << "We're sorry " << ER.peekTop() << ", the ER is now closed for remodeling.\n";
	
}

