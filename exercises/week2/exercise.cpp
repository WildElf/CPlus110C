// Week 2 Exercise
// exceptions
#include<iostream>
#include<stdexcept>

using namespace std;

template<class ItemType> 
class Box 
{ 
	private: 
		ItemType item; 
	public: 
		void setItem(const ItemType& i) 
			{ item = i; }
		ItemType getItem() const 
			{ return item; }
};

Box<int> findBox(Box<int> boxes[], int size, int target)
{
	if (target < 0)
	{
		throw logic_error("Search target cannot be negative!");
	}	

	int i = 0; 
	bool found = false; 
	while (!found && (i<size))
	{ 
		if (target==boxes[i].getItem()) 
			found = true; 
		else
			i++;
	}
	if (!found)
		throw logic_error("Target not found in any box!");
	return boxes[i];
}

int main()
{
	Box<int> searchBox;
	Box<int> socials[5];
	socials[0].setItem(457);
	socials[1].setItem(202);
	socials[2].setItem(101);
	socials[3].setItem(444);
	socials[4].setItem(747);
	
	int input;
	bool error = false;
	cout << "Enter 3-Digit social security # to search for: ";
	cin >> input;

	try {
		searchBox = findBox(socials, 5, input);
	}
	catch (logic_error logErr)
	{
		cout << logErr.what() << endl;
		error = true;
	}

	if (!error)
		cout << searchBox.getItem() << endl;
	
}