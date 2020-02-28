//****************************************************
// File: PurchaseCollection.cpp
//
// Purpose:  Source file for Purchase Collection class
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
#include "PurchaseCollection.h"

//****************************************************
// Function: Default constructor
//
// Purpose: Allocate memory for m_Collection, call initialize to set member variables
//
// Update Information
// ------------------
// 10/12 - Added memory allocation for dynamic array
//
//****************************************************
PurchaseCollection::PurchaseCollection()
{
	m_Collection = new Purchase;
}

//****************************************************
// Function: Constructor with size param
//
// Purpose: Initialize size member variable with param value
//          use param value to allocate m_Collection dynamic array
//
// Update Information
// ------------------
//
//****************************************************
PurchaseCollection::PurchaseCollection(int size)
{
	arraySize = size;
	m_Collection = new Purchase[arraySize];
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: Copy exisitng(rhs) Purchasecollection into current instance
//
// Update Information
// ------------------
//
//****************************************************
PurchaseCollection::PurchaseCollection(const PurchaseCollection &rhs)
{
	m_Collection = new Purchase[rhs.arraySize];
	arraySize = rhs.arraySize;

	for (int i = 0; i < rhs.arraySize; i++)
	{
		m_Collection[i] = rhs.m_Collection[i];
	}
}

//****************************************************
// Function: Operator= overload
//
// Purpose: Overwrite current instance with values from rhs instance
//
// Update Information
// ------------------
//
//****************************************************
const PurchaseCollection& PurchaseCollection::operator=(const PurchaseCollection& rhs)
{
	this->Resize(rhs.arraySize);

	for (int i = 0; i < rhs.arraySize; i++)
	{
		m_Collection[i] = rhs.m_Collection[i];
	}
	
	return *this;
}

//****************************************************
// Function: Resize
//
// Purpose: Create new array based on newSize param
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseCollection::Resize(int newSize)
{
	Purchase *temp = new Purchase[newSize];

	if (newSize > arraySize)
	{
		for (int i = 0; i < arraySize; i++)
		{
			temp[i] = m_Collection[i];
		}
	}

	if (newSize < arraySize)
	{
		for (int i = 0; i < newSize; i++)
		{
			temp[i] = m_Collection[i];
		}
	}

	arraySize = newSize;
	delete[] m_Collection;
	m_Collection = temp;
}

//****************************************************
// Function: Operator<< overload
//
// Purpose: Output elements of the the given Purchasecollection instance 
//          to the given instance of ostream
//
// Update Information
// ------------------
//
//****************************************************
std::ostream & operator<<(std::ostream & out, const PurchaseCollection & rhs)
{
	for (int i = 0; i < rhs.arraySize; i++)
	{
		out << rhs.m_Collection[i] << std::endl;
	}

	return out;
}

//****************************************************
// Function: Set
//
// Purpose: Sets value at given index to to the given 
//          Purchase instance
//
// Update Information
// ------------------
//
//
//****************************************************
void PurchaseCollection::Set(int index, Purchase p)
{
	if (index > arraySize)
	{
		std::cout << "Index is out of range" << std::endl;
	}
	else
	{
		m_Collection[index].SetItemName(p.GetItemName());
		m_Collection[index].SetItemPrice(p.GetItemPrice());
		m_Collection[index].SetQuantity(p.GetQuantity());
	}
}

//****************************************************
// Function: Get
//
// Purpose: Return the Purchase at the given index
//
// Update Information
// ------------------
//
//
//****************************************************
Purchase PurchaseCollection::Get(int index)
{
	return m_Collection[index];
}

//****************************************************
// Function:ItemPriceCount
//
// Purpose: Find number of item prices that fall between
//          the given threshold
//
// Update Information
// ------------------
//
//
//****************************************************
int PurchaseCollection::ItemPriceCount(double lowerBound, double upperBound)
{
	int count = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (((m_Collection[i].GetItemPrice()) >= lowerBound) && (m_Collection[i].GetItemPrice()) <= upperBound)
		{
			count++;
		}
	}
	return count;
}

//****************************************************
// Function: MostExpensivePurchase
//
// Purpose: Return Purchase instance with the highest item cost(price*quantity)
//
// Update Information
// ------------------
//
//
//****************************************************
Purchase PurchaseCollection::MostExpensivePurchase()
{
	double cost, mostExp;
	int biggestIndex = 0;

	mostExp = m_Collection[0].Cost();

	for (int i = 1; i < arraySize; i++)
	{
		cost = m_Collection[i].Cost();
		if (cost > mostExp)
		{
			mostExp = cost;
			biggestIndex = i;
		}
	}
	return m_Collection[biggestIndex];
}

//****************************************************
// Function: FindItemByName
//
// Purpose: Returns true if Purchase with the give name
//          is in the array and false otherwise. If it is, 
//          copy it into the purchase reference parameter
//
// Update Information
// ------------------
//
//****************************************************
bool PurchaseCollection::FindByItemName(std::string itemName, Purchase &p)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (m_Collection[i].GetItemName() == itemName)
		{
			p = m_Collection[i];
			return true;
		}
	}
	return false;
}

//****************************************************
// Function: TotalCost	
//
// Purpose: Return total cost of all Purchases in the Collection
//
// Update Information
// ------------------
//
//
//****************************************************
double PurchaseCollection::TotalCost()
{
	double totalCost = 0;

	for (int i = 0; i < arraySize; i++)
	{
		totalCost += m_Collection[i].Cost();
	}

	return totalCost;
}

//****************************************************
// Function: Size
//
// Purpose: Return the size of the array
//
// Update Information
// ------------------
//
//****************************************************
int PurchaseCollection::Size()
{
	return arraySize;
}


//****************************************************
// Function: Clone
//
// Purpose: Allocate new dynamic instance of PurchaseCollection that is a deep copy 
//          of the current instance
//
// Update Information
// ------------------
//
//****************************************************
PurchaseCollection* PurchaseCollection::Clone()
{
	//Since operator= is overloaded, cant it be done with one line?  
	//clone = this;
	
	PurchaseCollection *clone = new PurchaseCollection(arraySize);
	clone->arraySize = this->arraySize;

	for (int i = 0; i < arraySize; i++)
	{
		 clone->m_Collection[i].SetItemName(this->m_Collection[i].GetItemName());
		 clone->m_Collection[i].SetItemPrice(this->m_Collection[i].GetItemPrice());
		 clone->m_Collection[i].SetQuantity(this->m_Collection[i].GetQuantity());
	}
	
	return clone;
}

//****************************************************
// Function: Initialize
//
// Purpose: Initialize member variables to default values
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseCollection::Initialize()
{
	for (int i = 0; i < arraySize; i++)
	{
		m_Collection[i].SetItemName("No Name");
		m_Collection[i].SetItemPrice(0.00);
		m_Collection[i].SetQuantity(0);
	}
}

//****************************************************
// Function: GetAuthor
//
// Purpose: Returns my name
//
// Update Information
// ------------------
//
//****************************************************
std::string PurchaseCollection::GetAuthor()
{
	return "\nBryan Borgesano\n";
}


//****************************************************
// Function: Destructor
//
// Purpose: Deallocate memory and set pointer to NULL
//
// Update Information
// ------------------
//
//****************************************************
PurchaseCollection::~PurchaseCollection()
{
	delete [] m_Collection;
	m_Collection = NULL;
}


