
//****************************************************
// File: PurchaseList.cpp
//
// Purpose:  Source file for PurchaseList class
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//              
//****************************************************
#include "PurchaseList.h"


//****************************************************
// Function: Default constructor
//
// Purpose: Creates an empty list
//
// Big-O Runtime: O(1)
// 
// Update Information
// ------------------
//
//****************************************************
PurchaseList::PurchaseList() 
{
	m_length = 0;
	m_purchaseData = NULL;
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: Perform a deep copy of otherList
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
// 11/5/18 - Changed function to call operator= overload 
// since these functions do the same thing
//****************************************************
PurchaseList::PurchaseList(PurchaseList& otherList)
{
	//if other list is empty nothing can be done so return
	if (otherList.m_purchaseData == NULL) 
		return; 

	*this = otherList;	
}

//****************************************************
// Function: Destructor
//
// Purpose: Clears list and releases dynamic memory
//
// Big-O Runtime: O(n) since the destructor is called for 
//                     every instance?
//yy55yyyyyy55yyy55ggg
// Update Information
// ------------------
//
//****************************************************
PurchaseList::~PurchaseList()
{
	Clear();
}


//****************************************************
// Function: Operator= overload
//
// Purpose: Make a deep copy of the list parameter
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
PurchaseList& PurchaseList::operator=(PurchaseList &rhs)
{
	//if rhs is empty it cannot be copied, so return
	if (rhs.m_purchaseData == NULL)
		return *this; 

	//remove data from current instance;
	this->Clear();

	PurchaseListNode *last, *newNode;
	PurchaseListNode *currentList = rhs.m_purchaseData;

	m_length = rhs.m_length;

	//process first node 
	m_purchaseData = new PurchaseListNode;
	m_purchaseData->data = currentList->data;
	m_purchaseData->next = NULL;
	last = m_purchaseData; //point to previous node
	currentList = currentList->next;

	while (currentList != NULL)
	{
		newNode = new PurchaseListNode;
		newNode->data = currentList->data;
		newNode->next = NULL;
		last->next = newNode;
		last = newNode; //point to previous node
		currentList = currentList->next;
	}
	
	return *this;
}

//****************************************************
// Function: Clear	
//
// Purpose: Clears the current list
// 
// Big-O Runtime: O(n)
// 
// Update Information
// ------------------
//
//****************************************************
void PurchaseList::Clear()
{
	PurchaseListNode *temp;

	while (m_purchaseData != NULL)
	{
		temp = m_purchaseData;
		m_purchaseData = m_purchaseData->next;
		delete temp;
	}
	m_length = 0;
}

//****************************************************
// Function: Length
//
// Purpose: Returns number of items in the current list
//
// Big-O Runtime: O(1)
// 
// Update Information
// ------------------
//
//****************************************************
int PurchaseList::Length()
{
	return m_length;
}


//****************************************************
// Function: Add(Purchase)
//
// Purpose: Adds a purchase instance to the list
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseList::Add(const Purchase p)
{
	PurchaseListNode *temp;

	temp = new PurchaseListNode;
	temp->data = p;
	temp->next = m_purchaseData;

	m_purchaseData = temp;
	m_length++;
}

//****************************************************
// Function: Add(PurchaseList)
//
// Purpose: Appends all elements from otherList onto 
//          the current list
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
// 11/5/18 - Changed loop to use Add method instead of 
// traversing the whole list when appending another list
// - Now otherList is added to the front of the current instance
// - Length is accumlated in the Add method
//****************************************************
void PurchaseList::Add(const PurchaseList& otherList)
{
	//only way to manipulate ref parameter is with this copy
	PurchaseListNode *copy = otherList.m_purchaseData;
	
	//No need to update the length, it accumulates in the Add method
	
	while (copy != NULL)
	{
		Add(copy->data);
		copy = copy->next;
	}
	return;

}


//****************************************************
// Function: FindByItemName
//
// Purpose: Find the Purchase with the given name
//		
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
bool PurchaseList::FindByItemName(std::string itemName, Purchase &result) const
{
	PurchaseListNode *current = m_purchaseData;
	while (current != NULL)
	{
		if (current->data.GetItemName() == itemName)
		{
			result = current->data;
			return true;
		}
		current = current->next;
	}
	return false;
}


//****************************************************
// Function: Delete
//
// Purpose: Deletes the Purchase that matches the item name
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseList::Delete(std::string itemName)
{
	PurchaseListNode *location = m_purchaseData;

	if (itemName == location->data.GetItemName())
	{
		m_purchaseData = m_purchaseData->next;
		delete location;
		m_length--;
		return;
	}

	location = m_purchaseData;
	
	while ((location->next != NULL) && (itemName != (location->next)->data.GetItemName()))
	{
		location = location->next;
	}

	if (location->next == NULL) { return; }

	PurchaseListNode *tempLocation = location->next;
	location->next = (location->next)->next;
	delete tempLocation;
	m_length--;
	
}

void PurchaseList::RecursiveTraversal()
{
	RecursiveTraversal(m_purchaseData);
}

void PurchaseList::RecursiveTraversal(PurchaseListNode *temp)
{
	if (temp != NULL)
	{
		RecursiveTraversal(temp->next);
		std::cout << temp->data << std::endl;
	}
}





//****************************************************
// Function: Operator<< Overload
//
// Purpose: Print values to the given ostream
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
std::ostream& operator<<(std::ostream &out, const PurchaseList &rhs)
{
	PurchaseListNode *current = rhs.m_purchaseData;
	while (current != NULL)
	{
		out << current->data << std::endl;
		current = current->next;
	}

	return out;
}


//****************************************************
// Function: Operator>> Overload
//
// Purpose: Loads values in from the given istream 
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
std::istream& operator>>(std::istream &in, PurchaseList &rhs)
{
	// I had a bit of trouble getting this to work in a loop
	// so I did it this way

	//***CORRECTION*** set a loop to search until eof to fix this method

	PurchaseListNode *last, *newNode; 

	newNode = new PurchaseListNode;
	in >> newNode->data;
	//This will be the end of the list so it must point to NULL
	newNode->next = NULL;
	last = newNode;
	rhs.m_length++;

	newNode = new PurchaseListNode;
	in >> newNode->data;
	newNode->next = last;
	last = newNode;
	rhs.m_purchaseData = last;
	rhs.m_length++;

	newNode = new PurchaseListNode;
	in >> newNode->data;
	newNode->next = last;
	rhs.m_purchaseData = newNode;
	rhs.m_length++;
	

	return in;
}
