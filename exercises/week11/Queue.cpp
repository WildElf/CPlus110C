// CS110C - ADT Queues
// Exercise C
#include <iostream>

using namespace std;

// global size variable
const int MAX_QUEUE = 3;

class Queue 
{
private:
	char entries[MAX_QUEUE];
	int front;
	int back;
	int count;
public:
	Queue()
	{ front = 0; back = MAX_QUEUE - 1; count = 0; }
	bool enqueue(char c);
	bool dequeue();
	char peekFront();
	bool isEmpty();
	void done();
};

bool Queue::enqueue(char c)
{
	bool success = true;
	if (count == MAX_QUEUE)
		success = false;
	else
	{
		back=(back+1)%MAX_QUEUE;
		entries[back] = c;
		count++;
	}

	return success;
}

bool Queue::dequeue()
{
	bool success = true;
	if (count == 0)
		success = false;
	else
	{
		front = (front+1)%MAX_QUEUE;
		count--;
	}

	return success;
}

char Queue::peekFront()
{
	if (isEmpty())
		return 0;
	else
		return entries[front];
}

bool Queue::isEmpty()
{
	return (count == 0);
}

int main()
{
	Queue forQueue;

	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 1)\n";
	cout << "Adding f: " << forQueue.enqueue('f') << " (should be 1)\n";
	cout << "Adding i: " << forQueue.enqueue('i') << " (should be 1)\n";
	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 0)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 1)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 0)\n";
	cout << "Peeking at first item: " << forQueue.peekFront() << " (should be 'f')\n";
	cout << "Removing first item: " << forQueue.dequeue() << " (should be 1)\n";
	cout << "Adding l: " << forQueue.enqueue('l') << " (should be 1)\n";

	cout << "Peeking at the queue and dequeuing...\n";
	while (!forQueue.isEmpty())
	{
		cout << forQueue.peekFront();
		forQueue.dequeue();
	}
	cout << " (should be 'ill')\n";
	
	cout << "Queue is empty: " << forQueue.isEmpty() << " (should be 1)\n";
	
}