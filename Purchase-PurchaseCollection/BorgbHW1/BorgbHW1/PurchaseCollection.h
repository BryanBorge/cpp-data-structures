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
	const static int arraySize = 5;
	Purchase m_Collection[arraySize];

public:
	PurchaseCollection();
	void Set(int index, Purchase p);
	Purchase Get(int index);
	int ItemPriceCount(double lowerBound, double upperBound);
	Purchase MostExpensivePurchase();
	bool FindByItemName(std::string itemName, Purchase &p);
	double TotalCost();
	int Size();
	void Initialize();
	std::string GetAuthor();
};
