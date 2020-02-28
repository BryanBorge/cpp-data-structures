//****************************************************
// File: PurchaseStack.cpp
//
// Purpose:  Source file for PurchaseStack class
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************
#include "PurchaseStack.h"

//****************************************************
// Function: Default constructor
//
// Purpose: Allocate dynamic memeber array to the max size
//          Set the top of the list to be -1
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
PurchaseStack::PurchaseStack()
{
	data = new Purchase[MAX_SIZE];
	top = -1;
	size = 0;
}

//****************************************************
// Function: Constructor with max size as param
//
// Purpose: Allocate dynamic memeber array to the param value
//          Set the top of the list to be -1
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
PurchaseStack::PurchaseStack(int max)
{
	data = new Purchase[max];
	MAX_SIZE = max;
	top = 0;
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
PurchaseStack::PurchaseStack(PurchaseStack & rhs)
{
	data = new Purchase[rhs.MAX_SIZE];
	*this = rhs;
}

//****************************************************
// Function: Clear
//
// Purpose: Clear the stack
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
void PurchaseStack::Clear()
{
	top = 0;
	size = 0;
}

//****************************************************
// Function: Size
//
// Purpose: Returns number of elemets currently on the stack
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
int PurchaseStack::Size()
{
	return size;
}

//****************************************************
// Function: MaxStorage
//
// Purpose: Return maximum number of elemets the stack
//          can hold
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
int PurchaseStack::MaxStorage()
{
	return MAX_SIZE;
}

//****************************************************
// Function: Push
//
// Purpose: Add an element on the top stack
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
bool PurchaseStack::Push(Purchase p)
{
	//no elements can be added if the stack is full so return false
	if (size == MAX_SIZE) {
		std::cout << "Stack is full" << std::endl;
		return false;
	}
	else
	{
		size++;
		top++;
        data[top] = p;
		return true;
	}
}

//****************************************************
// Function: Pop
//
// Purpose: Removes top element of the stack
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
bool PurchaseStack::Pop()
{
	//if the stack is empty, nothing can be popped off so return false
	if (top < 0)
	{
		std::cout << "Stack is empty" << std::endl;
		return false;
	}
	else
	{
		size--;
		top--;
	}
}

//****************************************************
// Function: Top
//
// Purpose: Returns the top element of the stack without 
//          removing it
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
bool PurchaseStack::Top(Purchase & returnedPurchase)
{
	//if the stack is empty, nothing can be popped off so return false
	if (top <= 0)
		return false;
	returnedPurchase = data[top-1];
}

//****************************************************
// Function: Operator= overload
//
// Purpose: Makes a deep copy of the PurchaseStack parameter
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************

PurchaseStack& PurchaseStack::operator=(PurchaseStack & rhs)
{
	//Avoid self copy
	if (this == &rhs) {
		return *this;
	}

	Clear();
	size = rhs.size;
	top = rhs.top;
	MAX_SIZE = rhs.MAX_SIZE;

	//data = new Purchase[MAX_SIZE];

	for (int i = 0; i <= top; i++)
	{
		data[i] = rhs.data[i];
	}

	return *this;
}

//****************************************************
// Function: Operator<< Overload
//
// Purpose: Prints the values of all elemets on the stack
//          to the given ostream
//
//Big-O Runtime: O(n)
//
// Update Information
// ------------------
//****************************************************
std::ostream & operator<<(std::ostream & out, PurchaseStack & rhs)
{
	//Prints in stack order, that is, starting at the top 
	//and decrementing each iteration
	for (int i = rhs.top; i >= 0; i--) {
		out << rhs.data[i] << std::endl;
	}

	return out;
}

//****************************************************
// Function: Destructor
//
// Purpose: Releasese dynamic memory
//
//Big-O Runtime: O(1)
//
// Update Information
// ------------------
//****************************************************
PurchaseStack::~PurchaseStack()
{
	Clear();
}


