// E Jo Zimmerman - 110C - Assignment 3
// Sort class that can sort for 
// O(n^2) using selection sort
// O(n log n) using merge sort
// And "bucket" sort for O(???)
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Sort
{
private:
	int* theArray;
	int size;
	bool arrayExists()
		{ return !(theArray == NULL); }
	int merge(int*, int, int, int);
	int mergeRecursion(int*, int, int);


public:
	Sort() { theArray = NULL; size = 0; }
	Sort(int* array, int s)
		{ theArray = array; size = s; }
	~Sort()
		{ theArray = NULL; }
	void setNewArray(int* array, int s)
		{ theArray = array; size = s; }
	int selectionSort();
	int mergeSort();
	int bucketSort();
	int getItemAtIndex(int i)
		{ return theArray[i]; }
};

// private helper function for merge sort
int Sort::mergeRecursion(int* array, int first, int last)
{
	int compares = 0;
	
	if (first<last)
	{
		int mid = (first+last)/2;
		mergeRecursion(array, first, mid);
		mergeRecursion(array, mid+1, last);
		
		compares = merge(array, first, mid, last);
	}
	
	return compares;
}

// private helper function for merge sort
int Sort::merge(int* array, int first, int mid, int last)
{
	int compares = 0;
	int leftPointer = first;
	int rightPointer = mid+1;
	int tempPointer = 0;
	int* tempArray = new int[last-first+1];

	while (tempPointer <= last-first)
	{
		if (leftPointer > mid && rightPointer <= last)
		{
			tempArray[tempPointer] = array[rightPointer];
			rightPointer++;
		}		
		else if (rightPointer > last && leftPointer <= mid)
		{
			tempArray[tempPointer] = array[leftPointer];
			leftPointer++;
		}			
		else if (array[leftPointer] > array[rightPointer])
		{
			tempArray[tempPointer] = array[leftPointer];
			leftPointer++;
			compares++;
		}
		else
		{
			tempArray[tempPointer] = array[rightPointer];
			rightPointer++;
			compares++;
		}	
		
		tempPointer++;
	}
	
	for (int i=first;i<=last;i++)
		array[i] = tempArray[i-first];
	
//	delete [] tempArray;
	return compares;
}

// public selection sort caller
int Sort::selectionSort()
{
	int compares = 0;
	if (arrayExists())
	{
		for (int i = 0; i < size-1; i++)
		{
			int highest = theArray[i];
			int highIndex = i;
			bool newSelection = false;

			for (int j = i+1; j < size; j++)
			{
				if (theArray[j] > highest)
				{
					highIndex = j;
					highest = theArray[j];
					newSelection = true;
					compares++;
				}
			}
			
			if (newSelection)
			{
				int temp = theArray[i];
				theArray[i] = highest;
				theArray[highIndex] = temp;
			}
		
		}
		
		return compares;
	}
	else
	{
		cout << "No array has been added!\n";
		return 0;
	}
}

// public merge sort caller
int Sort::mergeSort()
{
	if (arrayExists())
	{
		return mergeRecursion(theArray, 0, size-1);
	}
	else
	{
		cout << "No array has been added!\n";
		return 0;
	}
}

// public bucket sort caller
int Sort::bucketSort()
{
	int compares = 0;
	if (arrayExists())
	{		
		int* count = new int[101];
		// to zero this out on hills
		for (int i=0;i<=101;i++)
			count[i] = 0;

		for (int j=0;j<size;j++)
		{
			count[theArray[j]]++;
			compares++;
		}
		
		int arrayStep = 0;

		for (int i=100;i>=0;i--)
		{
			for (int j=0; j<count[i];j++)
			{
				theArray[arrayStep] = i;
				arrayStep++;
				compares++;
			}
		}
		
		delete [] count;
		return compares;
	}
	else
	{
		cout << "No array has been added!\n";
		return compares;
	}
}

int main()
{
	srand(time(NULL));
	int size;
	
	// 2D array for
	// 3 sizes: 8, 32, 128
	// 4 results: 3 passes at each size, plus the average
	double nSquarePass[3][4] = { 0 };
	double nLogPass[3][4] = { 0 };
	double bucketPass[3][4] = { 0 };
	
	for (int pass = 0; pass < 3; pass++)
	{
		int step = 0;
		for (size=8; size<200;size*=4)
		{
	        // raw arrays for sorting
			int* nSquare = new int[size];
			int* nLog = new int[size];
			int* nBucket = new int[size];
			int newInt;

			for (int i=0;i<size;i++)
			{
				// each array gets the same number for cross comparisons
				newInt = rand()%101;
				nSquare[i] = newInt; 		
				nLog[i] = newInt; 		
				nBucket[i] = newInt; 		
			}
			
			// sort objects return the number of compares into 2D array
			Sort tommyLaSorta(nSquare, size);
			nSquarePass[step][pass] = tommyLaSorta.selectionSort();
	
			tommyLaSorta.setNewArray(nLog, size);
			nLogPass[step][pass] = tommyLaSorta.mergeSort();
	
			tommyLaSorta.setNewArray(nBucket, size);	
			bucketPass[step][pass] = tommyLaSorta.bucketSort();
			
			// prep the average index with average totals 
			nSquarePass[step][3] += nSquarePass[step][pass];
			nLogPass[step][3] += nLogPass[step][pass];
			bucketPass[step][3] += bucketPass[step][pass];
			
			step++;
		}

	}
	
	for (size=0;size<3;size++)
	{
		// turn the totals into averages
		nSquarePass[size][3] /= 3.0;
		nLogPass[size][3] /= 3.0;
		bucketPass[size][3] /= 3.0;		
	}
	
	// build a table for comparisons
	// looks good in a terminal (a text editor might need massaging)
	cout << "Sort Algorithm\tArrayLength\tPass 1\tPass 2\tPass 3\tAverage\n";
	for (int types=0;types<3;types++)
	{	

		for (int sizes=0;sizes<3;sizes++)
		{
			// first print the types
			if (types==0)
				cout << "Selection\t";
			else if (types == 1)
				cout << "Merge\t\t";
			else
				cout << "Bucket\t\t";
			
			// then print the array size
			if (sizes==0)
				cout << "8\t\t";
			else if (sizes == 1)
				cout << "32\t\t";
			else
				cout << "128\t\t";
				
			// print the comparison results with tab delimination
			for (int passes=0; passes<=3; passes++)
			{
				if (types==0)
					cout << nSquarePass[sizes][passes] << "\t";
				else if (types==1)
					cout << nLogPass[sizes][passes] << "\t";
				else
					cout << bucketPass[sizes][passes] << "\t";
			}
			
			cout << endl;
		}
	}
}

/* sample output
Sort Algorithm	ArrayLength	Pass 1	Pass 2	Pass 3	Average
Selection		8			8		8		9		8.33333	
Selection		32			80		54		67		67	
Selection		128			460		402		394		418.667	
Merge			8			7		6		6		6.33333	
Merge			32			31		30		31		30.6667	
Merge			128			126		125		125		125.333	
Bucket			8			16		16		16		16	
Bucket			32			64		64		64		64	
Bucket			128			256		256		256		256
*/
