#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int insertionSort(int array[], int size)
{
	int comparisons = 0;
	
	for (int unsorted = 1; unsorted < size; unsorted++) // O(n)
	{
		int nextItem = array[unsorted];
		int loc = unsorted;
		while (loc > 0 && array[loc-1] > nextItem) // O(n(n-1)/2)
		{
			// shift array element to the right
			array[loc] = array[loc-1];
			loc--;
			comparisons++;
		}

		array[loc] = nextItem;
	}

	return comparisons;
}

int insertionSortDesc(int array[], int size)
{
	int comparisons = 0;
	
	for (int unsorted = size-2; unsorted >= 0; unsorted--) // O(n)
	{
		int nextItem = array[unsorted];
		int loc = unsorted;
		while (loc < size-1 && array[loc+1] > nextItem) // O(n(n-1)/2)
		{
			// shift array element to the left
			array[loc] = array[loc+1];
			loc++;
			comparisons++;
		}

		array[loc] = nextItem;
	}
	
	return comparisons;
}

int main()
{
	srand(time(NULL));
	int const SIZE = rand()%95+6;
	int array[SIZE], compares;

	cout << "Array at beginning:\n";
	for (int i=0; i<SIZE; i++)
	{
		array[i] = rand()%100;
		cout << i + 1 << ": " << array[i] << " ";
	}
	cout << endl << endl;
		
	compares = insertionSort(array,SIZE);

	cout << "Array after ascending sort:\n";
	for (int i=0; i<SIZE; i++)
	{
		cout << i + 1 << ": " << array[i] << " ";
	}
	cout << "\nCompared " << compares << " times.\n";

	compares = insertionSortDesc(array,SIZE);

	cout << "Array after descending sort:\n";
	for (int i=0; i<SIZE; i++)
	{
		cout << i + 1 << ": " << array[i] << " ";
	}
	cout << "\nCompared " << compares << " times.\n";
	
	float order = compares/(float)SIZE;
	
	cout << "Worst Case Comparisons per Size " << order << "/" << SIZE << endl;

}