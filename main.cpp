#include <iostream>
#include <string>
#include "cqueue.h"


using namespace std;

enum choice { BOOKED, WAITING };
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue* qAirLine);
void deletePassenger(CQueue* qAirLine);
void showPassengers(CQueue* qAirLine);

int main (void)
{
	CQueue qPassengers[LINES];
	int x;
	do {
		x = showMenu();
		switch (x)
		{
		case 1: addPassenger(qPassengers);
			break;
		case 2: deletePassenger(qPassengers);
			break;
		case 3: showPassengers(qPassengers);
			break;
		}
	} while (x != 4);

	return 0;
}

int showMenu(void)
{
	int select;

	cout << "Menu\n";
	cout << "========\n";
	cout << "1. Add Passenger\n";
	cout << "2. Delete Passenger\n";
	cout << "3. Show Passengers\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	return select;
}

void addPassenger(CQueue* qAirLine)
{
	Passenger pName;
	cout << "Enter passenger name: ";
	cin >> pName.name;

	if (!qAirLine[BOOKED].IsFull() && qAirLine[WAITING].IsEmpty())
	{
		qAirLine[BOOKED].Enqueue(pName);
		cout << "Booking " << pName.name << " on the flight\n";
	}
	else if (qAirLine[BOOKED].IsFull() && !qAirLine[WAITING].IsFull())
	{
		qAirLine[WAITING].Enqueue(pName);
		cout << "Adding " << pName.name << " to the waiting list\n";
	}
	else if (qAirLine[BOOKED].IsFull() && qAirLine[WAITING].IsFull())
	{
		cout << "Sorry. Plane and waiting list fully booked. Try later" << endl;
	}

}

void deletePassenger(CQueue* qAirLine)
{
	if (qAirLine[BOOKED].IsEmpty() && qAirLine[WAITING].IsEmpty())
	{
		cout << "No passengers to delete\n";
	}
	else if (!qAirLine[BOOKED].IsFull() && qAirLine[WAITING].IsEmpty())
	{
		cout << "Removing " << qAirLine[BOOKED].Front().name << " from booked passengers\n";
		qAirLine[BOOKED].Dequeue();
	}
	else if (qAirLine[BOOKED].IsFull() && !qAirLine[WAITING].IsFull())
	{
		cout << "Removing " << qAirLine[BOOKED].Front().name << " from booked passengers list\n";
		qAirLine[BOOKED].Dequeue();
		cout << "Adding passenger " << qAirLine[WAITING].Front().name << " from the waiting list to booked\n";
		qAirLine[BOOKED].Enqueue(qAirLine[WAITING].Front());
		qAirLine[WAITING].Dequeue();
	}
	else if (qAirLine[BOOKED].IsFull() && qAirLine[WAITING].IsFull())
	{
		cout << "Removing " << qAirLine[BOOKED].Front().name << " from booked passengers\n";
		qAirLine[BOOKED].Dequeue();
		cout << "Adding passenger " << qAirLine[WAITING].Front().name << " from the waiting list to booked\n";
		qAirLine[BOOKED].Enqueue(qAirLine[WAITING].Front());
		qAirLine[WAITING].Dequeue();
	}

}

void showPassengers(CQueue* qAirLine)
{
	string firstPassenger;
	Passenger temp;
	if (qAirLine[BOOKED].IsEmpty() && qAirLine[BOOKED].IsEmpty())
		cout << "Booked and Waiting list are empty\n";
	else if (!qAirLine[BOOKED].IsEmpty() && qAirLine[WAITING].IsEmpty())
	{
		firstPassenger = qAirLine[BOOKED].Front().name;
		cout << "Booked Passengers\n";
		cout << "===================\n";
		do
		{
			cout << qAirLine[BOOKED].Front().name <<endl;
			temp = qAirLine[BOOKED].Front();
			qAirLine[BOOKED].Dequeue();
			qAirLine[BOOKED].Enqueue(temp);
		} while (qAirLine[BOOKED].Front().name!=firstPassenger);
		cout << "No passengers on Waiting list\n";
	}

	else if (qAirLine[BOOKED].IsFull() && !qAirLine[WAITING].IsEmpty())
	{
		cout << "Booked Passengers\n";
		cout << "===================\n";
		firstPassenger = qAirLine[BOOKED].Front().name;
		do
		{
			cout << qAirLine[BOOKED].Front().name <<endl;
			temp = qAirLine[BOOKED].Front();
			qAirLine[BOOKED].Dequeue();
			qAirLine[BOOKED].Enqueue(temp);
		} while (qAirLine[BOOKED].Front().name != firstPassenger);
		cout << "Waiting Passengers\n";
		cout << "**********************\n";
		firstPassenger = qAirLine[WAITING].Front().name;
		do
		{
			cout << qAirLine[WAITING].Front().name <<endl;
			temp = qAirLine[WAITING].Front();
			qAirLine[BOOKED].Dequeue();
			qAirLine[BOOKED].Enqueue(temp);
		} while (firstPassenger != qAirLine[WAITING].Front().name);
	}

}