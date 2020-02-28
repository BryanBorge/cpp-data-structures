//****************************************************
// File: PurchaseCollection.h
//
// Purpose:  Class definition for PurchaseCollection 
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
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <istream>

class PurchaseCollection
{

private:
	int arraySize;
	Purchase *m_Collection = NULL;
public:
	PurchaseCollection();
	PurchaseCollection(int size);
	PurchaseCollection(const PurchaseCollection &rhs);
	const PurchaseCollection& operator=(const PurchaseCollection& rhs);
	void Resize(int newSize);
	friend std::ostream& operator<<(std::ostream &out, const PurchaseCollection &rhs);
	void Set(int index, Purchase p);
	Purchase Get(int index);
	int ItemPriceCount(double lowerBound, double upperBound);
	Purchase MostExpensivePurchase();
	bool FindByItemName(std::string itemName, Purchase &p);
	double TotalCost();
	int Size();
	PurchaseCollection *Clone();
	void Initialize();
	std::string GetAuthor();
	~PurchaseCollection();
};

