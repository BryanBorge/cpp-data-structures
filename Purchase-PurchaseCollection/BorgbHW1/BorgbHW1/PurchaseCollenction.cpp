//****************************************************
// File: Purchase.cpp
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
// Function: Purchase Collection default constructor
//
// Purpose: Initialize member variables to default values by
//          calling the Initialize menthod
//
// Update Information
// ------------------
//
//
//****************************************************
PurchaseCollection::PurchaseCollection()
{
	Initialize();
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

	for(int i = 1; i < arraySize; i++) 
	{
		cost = m_Collection[i].Cost();
		if(cost > mostExp)
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
//
//****************************************************
int PurchaseCollection::Size()
{
	return arraySize;
}

//****************************************************
// Function: Initialize
//
// Purpose: Initialize member variables to default values
//
// Update Information
// ------------------
//
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
//
//****************************************************
std::string PurchaseCollection::GetAuthor()
{
	return "\nBryan Borgesano\n";
}