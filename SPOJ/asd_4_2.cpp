//Spoj 4.2 Kolejka
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


#define SIZE 10


class Queue
{
	int* arr;		
	int capacity;	
	int front;		
	int rear;		
	int count;		

public:
	Queue(int size = SIZE); 	
	~Queue();   				

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
	void print();
};


Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

Queue::~Queue()
{
	delete arr;
}


void Queue::dequeue()
{

	if (isEmpty())
	{
		cout << "Error: queue is empty" << endl;
	}
	else
	{
		cout << arr[front] << endl;
		front = (front + 1) % capacity;
		count--;
	}
}

void Queue::enqueue(int item)
{

	if (isFull())
	{
		cout << "Error: queue is full" << endl;
	}
	else
	{
		cout << "--->" << '\n';
		rear = (rear + 1) % capacity;
		arr[rear] = item;
		count++;
	}
}

int Queue::peek()
{
	if (isEmpty())
	{
		cout << "Error: Queue us empty" << endl;;
	}
	return arr[front];
}


int Queue::size()
{
	return count;
}


bool Queue::isEmpty()
{
	return (size() == 0);
}


bool Queue::isFull()
{
	return (size() == capacity);
}

void Queue::print()
{
	cout << "Print: ";
	if (isEmpty())
	{
		cout << "Queue is empty";
	}
	else
	{
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}


int main()
{
	int value;
	string sampletext;
	Queue q(10);
	
	while (cin >> sampletext)
	{
		if (sampletext == "Enqueue")
		{
			cin >> value;
			q.enqueue(value);
		}
		if (sampletext == "Dequeue")
		{
			q.dequeue();
		}
		if (sampletext == "Print")
		{
			q.print();
		}
	}
	return 0;
}
