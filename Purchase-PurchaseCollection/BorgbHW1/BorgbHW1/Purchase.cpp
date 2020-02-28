//****************************************************
// File: Purchase.cpp
//
// Purpose:  Source file for Purchase class
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
#include "Purchase.h"


//****************************************************
// Function: Purchase default constructor
//
// Purpose: Initialize member variables to default values
//
// Update Information
// ------------------
//
//
//****************************************************
Purchase::Purchase()
{
	m_itemName = "No Name";
	m_quantity = 0;
	m_itemPrice = 0.0;
}

//****************************************************
// Function: Purchase constructor with parameters 
//
// Purpose: Assign parameter values to member variables
//
// Update Information
// ------------------
//
//
//****************************************************
Purchase::Purchase(std::string name, int quantity, double price)
{
	m_itemName = name;
	m_quantity = quantity;
	m_itemPrice = price;
}

//****************************************************
// Function: Purchase Copy Constructor
//
// Purpose: Perform shallow copy of Purchase objects
//
// Update Information
// ------------------
//
//
//****************************************************
Purchase::Purchase(const Purchase &rhs)
{
	m_itemName = rhs.m_itemName;
	m_quantity = rhs.m_quantity;
	m_itemPrice = rhs.m_itemPrice;
}


//****************************************************
// Function: Purchase operator= overload
//
// Purpose: Overload assignment operator to allow all member variables
//          to be copied in one statement
//
// Update Information
// ------------------
//
//
//****************************************************
const Purchase& Purchase::operator=(const Purchase& rhs)
{
	m_itemName = rhs.m_itemName;
	m_quantity = rhs.m_quantity;
	m_itemPrice = rhs.m_itemPrice;
	return *this;
}


//****************************************************
// Function: Purchase operator<< overload
//
// Purpose: Overload extraction operator to allow output
//          of all member variables in one statement 
//
// Update Information
// ------------------
//
//
//****************************************************
std::ostream& operator<<(std::ostream &out, const Purchase& rhs)
{
	out << rhs.m_itemName << std::endl;
	out << rhs.m_itemPrice << std::endl;
	out << rhs.m_quantity << std::endl;
	
	return out;
}

//****************************************************
// Function: Cost
//
// Purpose: Return the cost(price*quantity) for the purchase 
//
// Update Information
// ------------------
//
//
//****************************************************
double Purchase::Cost()
{
	return m_itemPrice * m_quantity;
}


//****************************************************
// Function: SetName
//
// Purpose: Sets name member varible to parameter value
//
// Update Information
// ------------------
//
//
//****************************************************
void Purchase::SetItemName(std::string name)
{
	m_itemName = name;
}

//****************************************************
// Function: SetQuantity
//
// Purpose: Sets quantity member variable to parameter value
//
// Update Information
// ------------------
//
//
//****************************************************
void Purchase::SetQuantity(int quantity)
{
	m_quantity = quantity;
}


//****************************************************
// Function: SetItemPrice
//
// Purpose: Sets itemPrice member variable to parameter value
//
// Update Information
// ------------------
//
//
//****************************************************
void Purchase::SetItemPrice(double price)
{
	m_itemPrice = price;
}



//****************************************************
// Function: GetItemName
//
// Purpose: Return item name
//
// Update Information
// ------------------
//
//
//****************************************************
std::string Purchase::GetItemName()
{
	return m_itemName;
}



//****************************************************
// Function: GetQuantity
//
// Purpose: Return quantity
//
// Update Information
// ------------------
//
//
//****************************************************
int Purchase::GetQuantity()
{
	return m_quantity;
}


//****************************************************
// Function: GetItemPrice
//
// Purpose: Return item price
//
// Update Information
// ------------------
//
//
//****************************************************
double Purchase::GetItemPrice()
{
	return m_itemPrice;
}