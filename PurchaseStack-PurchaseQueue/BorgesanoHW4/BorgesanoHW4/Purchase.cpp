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
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: All member variables changed to pointers.
//       All methods updated to work accordingly.
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
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Allocate memory for pointer member variables
// 
//****************************************************
Purchase::Purchase()
{
	m_itemName = new std::string;
	m_quantity = new int;
	m_itemPrice = new double;

	*m_itemName = "No Name";
	*m_quantity = 0;
	*m_itemPrice = 0.0;
}

//****************************************************
// Function: Purchase constructor with parameters 
//
// Purpose: Assign parameter values to member variables
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Allocate memory for pointer member variables
// 
//****************************************************
Purchase::Purchase(std::string name, int quantity, double price)
{

	m_itemName = new std::string;
	m_quantity = new int;
	m_itemPrice = new double;

	*m_itemName = name;
	*m_quantity = quantity;
	*m_itemPrice = price;
}

//****************************************************
// Function: Purchase Copy Constructor
//
// Purpose: Perform deep copy of Purchase objects
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Allocate memory for pointer member variables
// 
//****************************************************
Purchase::Purchase(const Purchase &rhs)
{
	m_itemName = new std::string;
	m_quantity = new int;
	m_itemPrice = new double;

	*m_itemName = *rhs.m_itemName;
	*m_quantity = *rhs.m_quantity;
	*m_itemPrice = *rhs.m_itemPrice;
}


//****************************************************
// Function: Purchase operator= overload
//
// Purpose: Overload assignment operator to allow all member variables
//          to be copied in one statement
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Allocate memory to perform deep copy.
//       Dereferenced LHS and RHS to properly copy values 
// 
//****************************************************
const Purchase& Purchase::operator=(const Purchase& rhs)
{
	*m_itemName = *rhs.m_itemName;
	*m_quantity = *rhs.m_quantity;
	*m_itemPrice = *rhs.m_itemPrice;
	return *this;
}

bool Purchase::operator==(const Purchase & rhs)
{
	if (*m_itemName == *rhs.m_itemName)
		return true;
	else
		return false;
}


//****************************************************
// Function: Purchase operator<< overload
//
// Purpose: Overload extraction operator to allow output
//          of all member variables in one statement 
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereferenced RHS to properly output values
// 
//****************************************************
std::ostream& operator<<(std::ostream &out, const Purchase& rhs)
{
	out << *rhs.m_itemName << std::endl;
	out << *rhs.m_itemPrice << std::endl;
	out << *rhs.m_quantity << std::endl;

	return out;
}

//****************************************************
// Function: Purchase operator>> overload
//
// Purpose: Overload insertion operator to allow input
//          of all member variables from the given istream
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereferenced RHS to properly input values
// 
//****************************************************
std::istream& operator>>(std::istream &in, const Purchase &rhs)
{
	in >> *rhs.m_itemName;
	in >> *rhs.m_itemPrice;
	in >> *rhs.m_quantity;

	return in;
}

//****************************************************
// Function: Cost
//
// Purpose: Return the cost(price*quantity) for the purchase 
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereferenced pointer member variables 
// 
//****************************************************
double Purchase::Cost()
{
	return (*m_itemPrice) * (*m_quantity);
}


//****************************************************
// Function: SetName
//
// Purpose: Sets name member varible to parameter value
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference itemName to store value correctly
//
//****************************************************
void Purchase::SetItemName(std::string name)
{
	*m_itemName = name;
}

//****************************************************
// Function: SetQuantity
//
// Purpose: Sets quantity member variable to parameter value
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference quantity to store value correctly
//
//****************************************************
void Purchase::SetQuantity(int quantity)
{
	*m_quantity = quantity;
}


//****************************************************
// Function: SetItemPrice
//
// Purpose: Sets itemPrice member variable to parameter value
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference itemPrice to store value correctly
//
//****************************************************
void Purchase::SetItemPrice(double price)
{
	*m_itemPrice = price;
}


//****************************************************
// Function: GetItemName
//
// Purpose: Return item name
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference itemName to return correct value
// 
//****************************************************
std::string Purchase::GetItemName()
{
	return *m_itemName;
}


//****************************************************
// Function: GetQuantity
//
// Purpose: Return quantity
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference quantity to return correct value
// 
//****************************************************
int Purchase::GetQuantity()
{
	return *m_quantity;
}


//****************************************************
// Function: GetItemPrice
//
// Purpose: Return item price
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Dereference itemPrice to return correct value
// 
//****************************************************
double Purchase::GetItemPrice()
{
	return *m_itemPrice;
}

//****************************************************
// Function: Purchase Destructor
//
// Purpose: Deallocates pointer member variables and sets 
//          them to NULL
//
// Update Information
// ------------------
// Name: Bryan Borgesano
// Date: 9/25/18
// Desc: Added destructor for pointer member variables
//****************************************************
Purchase::~Purchase()
{
	delete m_itemName;
	m_itemName = NULL;

	delete m_itemPrice;
	m_itemPrice = NULL;

	delete m_quantity;
	m_quantity = NULL;
}
