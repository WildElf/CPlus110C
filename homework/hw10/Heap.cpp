#include "Heap.h"
//#include "Patient.h"

void Heap::swap(Patient &a, Patient &b)
{
	Patient temp = a;
	a = b;
	b = temp;
}

void Heap::heapRebuild(int root)
{
//	cout << "rebuilding at " << root << endl;
	// root's left child, if exists, means root has children
	if (root*2 + 1 < size)
	{
		// assume left child is largest, get right child's index
		int largestChildIndex = root * 2 + 1;
		int rightChildIndex = root * 2 + 2;
		
		// check if root has a right child
		if (rightChildIndex < size) // then compare to left
			if (patients[rightChildIndex] > patients[largestChildIndex])
				largestChildIndex = rightChildIndex;
		
		if (patients[root] < patients[largestChildIndex])
		{
			swap(patients[root], patients[largestChildIndex]);
			heapRebuild(largestChildIndex); 
		}
		
	}
}

Heap::Heap(Patient array[], int numItems)
{
	size = numItems;
	max = (size%10+1)*10;
	patients = new Patient[max];
	
	for (int i = 0; i < size; i++)
		patients[i] = array[i];	
	
	for (int i = size/2 -1; i >=0; i--)
		heapRebuild(i);
}

bool Heap::add(Patient p)
{
	bool added = true;
	if (size == max)
		added = false;
	else
	{
//		cout << "adding " << p.getName() << " to position " << size << endl;
		patients[size] = p;
//		cout << "Added " << patients[size].getName() << " with priority " << patients[size].getPriority() << " at " << size << endl;

		int newIndex = size;
		bool inPlace = false;

		while (newIndex > 0 && !inPlace)
		{
			int parentIndex = (newIndex-1)/2;
			if (patients[newIndex] < patients[parentIndex])
				inPlace = true;
			else
			{
//				cout << "swapping " << patients[parentIndex].getName() << " with " << patients[newIndex].getName() << endl;
				swap(patients[parentIndex],patients[newIndex]);	
//				cout << "Now " << patients[parentIndex].getName() << " and " << patients[newIndex].getName() << " are swapped\n";
				newIndex = parentIndex;
			}
		}
		size++;	
//		cout << "Added " << patients[0].getName() << " with priority " << patients[0].getPriority() << endl;
	}
	
	return added;	
}

string Heap::peekTop()
{
	return patients->getName();
}

bool Heap::remove()
{
	bool removed = true;
	if (size == 0)
		removed = false;
	else
	{
		for (int i = 1; i<size; i++)
		{
			patients[i-1] = patients[i];
		}
		size--;
		heapRebuild(0);
	}
	return removed;
}
