// Assignment 10, Emergency Room
// E. Jo Zimmerman, 110C
// (Patient) Heap class definition, for a heap of patients
#ifndef HEAP_H
#define HEAP_H
#include "Patient.h"
#include <cmath>

class Heap
{
private:
	Patient* patients;
	int size;
	int max;
	void heapRebuild(int root);
	void swap(Patient& a, Patient& b);
public:
	Heap()
	{ size = 0; max = 10; patients = new Patient[max];  }
	Heap(int num)
	{ size = 0; max = num; patients = new Patient[max];  }
	Heap(Patient[], int);
	~Heap()
	{ delete [] patients; }
	bool isEmpty()
	{ return size == 0; }
	int getHeight()
	{ return log2(size)+1; }
	int getNumberOfNodes()
	{ return size; }
	void clear()
	{ while (size > 0) remove(); }
	bool add(Patient p);
	string peekTop();
	bool remove();
};

#endif