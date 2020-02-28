//****************************************************
// File: Purchase.h
//
// Purpose:  Class definiton for Purchase 
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
//       All methods updated to work accordingly 
//
// Name: Bryan Borgesano
// Date: 12/08/18
// Desc: Added operator< and operator> overloads
//              
//****************************************************

#ifndef PURCHASE_H
#define PURCHASE_H
#include <string>
#include <iostream>
class Purchase
{
private:
	std::string *m_itemName;
	int *m_quantity;
	double *m_itemPrice;

public:
	Purchase();
	Purchase(std::string n, int q, double p);
	Purchase(const Purchase &rhs);
	const Purchase& operator=(const Purchase& rhs);
	bool operator== (const Purchase &rhs);
	friend bool operator< (const Purchase &lhs,const Purchase &rhs);
	friend bool operator> (const Purchase &lhs, const Purchase &rhs);
	friend std::ostream& operator<<(std::ostream &out, const Purchase& rhs);
	friend std::istream& operator>>(std::istream &in, const Purchase &rhs);
	double Cost();
	void SetItemName(std::string n);
	void SetQuantity(int q);
	void SetItemPrice(double p);
	std::string GetItemName();
	int GetQuantity();
	double GetItemPrice();
	~Purchase();
};
#endif