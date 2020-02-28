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
//
//              
//****************************************************


#include <string>
#include <iostream>


class Purchase
{
private:
	std::string m_itemName;
	int m_quantity;
	double m_itemPrice;

public:
	Purchase();
	Purchase(std::string n, int q, double p);
	Purchase(const Purchase &rhs); 
	const Purchase& operator=(const Purchase& rhs);
	friend std::ostream& operator<<(std::ostream &out, const Purchase& rhs);
	double Cost();
	void SetItemName(std::string n);
	void SetQuantity(int q);
	void SetItemPrice(double p);
	std::string GetItemName();
	int GetQuantity();
	double GetItemPrice();

};