//****************************************************
// File: PurchaseQueue.cpp
//
// Purpose:  Source file for PurchaseQueue class
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************
#include "PurchaseQueue.h"


//****************************************************
// Function: Default constructor
//
// Purpose: Set front and rear to NULL default values
//          Set size to 0
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
PurchaseQueue::PurchaseQueue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}

//****************************************************
// Function: Copy constructor
//
// Purpose: Create a deep copy of the passed in instance
//          using operator= overload
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
PurchaseQueue::PurchaseQueue(const PurchaseQueue & rhs)
{
	if (rhs.rear == NULL)
		return;

	*this = rhs;
}

//****************************************************
// Function: Clear
//
// Purpose: Clear the Queue
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
void PurchaseQueue::Clear()
{
	PurchaseQueueNode *temp;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	size = 0;
	rear = NULL;
}

//****************************************************
// Function: Size
//
// Purpose: Returns number of elemets currently on the queue
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
int PurchaseQueue::Size()
{
	return size;
}

//****************************************************
// Function: Enqueue
//
// Purpose: Adds purchase instance to end of queue
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
void PurchaseQueue::Enqueue(Purchase p)
{
	if (size == MAX_SIZE)
	{
		std::cout << "Queue is full" << std::endl;
		return;
	}
	else
	{
		PurchaseQueueNode *temp;
		temp = new PurchaseQueueNode;

		temp->data = p;
		temp->next = NULL;

		if (rear == NULL)
			front = temp;
		else
			rear->next = temp;

		rear = temp;
		size++;
	}

}


//****************************************************
// Function: Dequeue
//
// Purpose: Removes and returns first element in the queue
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
bool PurchaseQueue::Dequeue(Purchase & returnedPurchase)
{
	if (size == 0)
	{
		std::cout << "Queue is empty" << std::endl;
		return false;
	}
	else
	{
		PurchaseQueueNode *temp;
		temp = front;

		returnedPurchase = front->data;

		front = front->next;

		if (front == NULL)
			rear = NULL;

		size--;
		delete temp;
		return true;
	}
}

//****************************************************
// Function: Operator= overload
//
// Purpose: Makes a deep copy of the PurchaseQueue parameter
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
PurchaseQueue & PurchaseQueue::operator=(const PurchaseQueue & rhs)
{
	//cannot copy an empty list so return 
	if (rhs.rear == NULL)
		return *this;

	//make sure current instance is empty
	this->Clear();
	
	PurchaseQueueNode *location = rhs.front;

	while (location != NULL)
	{	
		PurchaseQueueNode *temp = new PurchaseQueueNode;
		temp->data = location->data;
		Enqueue(temp->data);
		location = location->next;
	}

	return *this;
}

//****************************************************
// Function: Operator<< Overload
//
// Purpose: Prints the values of all elemets on the queue
//          to the given ostream
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
std::ostream & operator<<(std::ostream & out, const PurchaseQueue & rhs)
{
	PurchaseQueueNode *current = rhs.front;
	while (current != NULL)
	{
		out << current->data << std::endl;
		current = current->next;
	}

	return out;
}

//****************************************************
// Function: Destructor
//
// Purpose: Release queue's memory
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
PurchaseQueue::~PurchaseQueue()
{
	Clear();
}