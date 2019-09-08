#include "cqueue.h"
#include <iostream>
#include <string>

using namespace std;

CQueue::CQueue()
{
	front = MAX - 1;
	rear = MAX - 1;
}

bool CQueue::IsEmpty()
{
	return front == rear;
}

bool CQueue::IsFull()
{
	return ((rear + 1) % MAX == front);
}

void CQueue::Enqueue(Passenger Name)
{
	if (!IsFull())
	{
		rear = (rear + 1) % MAX;
		passengers[rear]=Name;
	}
		
}

Passenger CQueue::Front()
{
	return (passengers[(front+1)%MAX]);
}

void CQueue::Dequeue()
{
	if (!IsEmpty())
		front = (front + 1) % MAX;
}