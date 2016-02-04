// Array-based List Class for Playlists
// Max Luttrell CS 110C
// Eric Zimmerman

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
  private:
    static const int CHUNK_SIZE=2;
    ItemType *list;
    int numItems;
    int maxItems;
  public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE; 
             list = new ItemType[CHUNK_SIZE]; }
    ~List() { delete [] list; }

    // list member functions
    bool isEmpty() { return numItems==0; }
    int getLength() { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there 
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }

    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const throw(invalid_argument);

    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item) throw(invalid_argument);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
  bool canAdd;

  canAdd = ((pos > 0) && (pos <= numItems + 1));
  if (canAdd)
  {
  // if the current array is full, we'll increase the maximum size first
  if (numItems == maxItems)
  {
    maxItems += CHUNK_SIZE;
    ItemType *newList = new ItemType[maxItems];
    
    for (int i=0;i<numItems;i++)
    {
      newList[i] = list[i];      
    }
    
    delete [] list;
    list = newList;
  }

    // move everything after our insertion point over one position
    // to make room for our new item.  start at the back of the list.
    // don't forget arrays start at postion zero and our list ADT starts at
    // position 1.
    for(int i=numItems; i>=pos; i--)
      list[i] = list[i-1];

    // now put our item at position pos-1
    list[pos-1] = item;

    numItems++;
  }

  return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const throw(invalid_argument)
{
  if(pos<1 || pos>numItems) {
    throw invalid_argument("ERROR: getEntry() using invalid position");
  }
  return list[pos-1];
}

// return false if pos is invalid
template<class ItemType>
bool List<ItemType>::remove(int pos)
{
  bool canRemove;
  canRemove = (pos>0 && pos<=numItems);
    
  if (canRemove)
  {    
    if (pos == numItems) {
//      list[pos-1] = NULL;
      numItems--;
      return true;
    }
    else {
      for (int i=pos-1; i<numItems-1; i++)
        list[i] = list[i+1];
//      list[numItems-1] = NULL;
      numItems--;
      return true;
    }
    
    // be good memory handlers & decrease the list 
    // size if it is larger than necessary
    if (numItems == maxItems - CHUNK_SIZE)
    {
      maxItems -= CHUNK_SIZE;
      ItemType *newList = new ItemType[maxItems];
    
      for (int i=0;i<numItems;i++)
      {
        newList[i] = list[i];      
      }
    
      delete [] list;
      list = newList;
    }
  }
  else
    return false;
}

// throw invalid_argument if pos<1 or pos>getLength()
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item) throw(invalid_argument)
{
  if (pos<1 || pos>numItems) {
    throw invalid_argument("ERROR: setEntry() using invalid position");
  }
  else
    list[pos-1] = item;
}

// Utility function to input a track number with some input checking 
// to make sure it's a number
int validPos(string request)
{
  bool inputCheck;
  int trackNumber;

  do
  {
    inputCheck = true;
    cout << request;
    if (!(cin >> trackNumber))
    {
      cout << "Please enter numbers only.\n";
      cin.clear(); 
      cin.ignore(10000,'\n');
      inputCheck = false;
    }
    else {
      cin.clear(); 
      cin.ignore(10000,'\n');
	}
  } while (!inputCheck);
  return trackNumber;
}

// Utility function to display track information
template<class ItemType>
void displayTrack(ItemType &list)
{
  int trackNumber = validPos("Please enter the track number you'd like to view: ");
  string trackName;

  try
  {
    trackName = list.getEntry(trackNumber);
  }
  catch (invalid_argument arg)
  {
    cout << arg.what() << endl;
    trackName = "Does not exist at " + to_string(trackNumber);
  }
  cout << "Your track name is " << trackName << endl;
}

template<class ItemType>
void addTrack(ItemType &list)
{
  int newPos;
  string trackName;
  bool success = false;
  
  newPos = validPos("Enter the position for the new track: ");

  cout << "Enter the name of the track: ";
  getline(cin, trackName);
    
  if (list.insert(newPos, trackName))
    cout << "The song " << trackName << " was added at position " << newPos << endl;
  else  
    cout << "Adding " << trackName << " to position " << newPos << " failed.\n";

//    cin.clear(); 
//    cin.ignore(10000,'\n');

}

template<class ItemType>
void removeTrack(ItemType &list)
{
  int delPos = validPos("Enter position of the track to remove: ");
  
  if (list.remove(delPos))
    cout << "Track " << delPos << " removed\n";
  else
    cout << "No track found at " << delPos << endl;
}

template<class ItemType>
void changeTrack(ItemType &list)
{
  int chngPos = validPos("Enter position of the track to change: ");
  string trackName;
  
  cout << "Enter the new name of the track: ";
  getline(cin, trackName);

  try {
    list.setEntry(chngPos, trackName);
  }
  catch (invalid_argument arg) {
    cout << arg.what() << endl;
    trackName = "Invalid";
  }
  cout << "Track at " << chngPos << " is " << trackName << endl;
  
}

// Utility to print the user menu 
// and sets the selection value to quit
int printMenu()
{
  cout << "1. Show Track\n";
  cout << "2. Add Track\n";
  cout << "3. Remove Track\n";
  cout << "4. Change Track\n";
  cout << "5. List All Tracks\n";
  cout << "6. Quit\n";
  
  // returns the quit option
  return 6;
}

int main()
{
  List<string> songs;
  int selection, quit = 0;

  // Insert some songs into our list
  songs.insert(1, "One More Saturday Night");
  songs.insert(1, "Friday I'm in Love");
  songs.insert(3, "Sunday Morning Coming Down");
  songs.insert(1, "California Love");

  cout << "Welcome! ";
  do
  {
    cout << "There are " << songs.getLength() << " tracks.\n";
    quit = printMenu();

    cout << "Select Option: ";
    cin >> selection;
    
    if (selection == 1)
      displayTrack(songs);
    else if (selection == 2)
      addTrack(songs);
    else if (selection == 3)
      removeTrack(songs);
    else if (selection == 4)
      changeTrack(songs);
    else if (selection == 5)
    	for (int i = 1; i<=songs.getLength(); i++)
    		cout << "Track " << i << ": " << songs.getEntry(i) << endl;
    else if (selection < 1 || selection > quit)
      cout << "Invalid selection.\n";
      
    cout << endl;
  } while (selection != quit);

  cout << "Rock on!\n";
  return 0; 
}


