//****************************************************
// File: PurchaseStack.h
//
// Purpose:  Class definiton for a Stack ADT of Purchases
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************

#ifndef PURCHASESTACK_H
#define PRUCHASESTACK_H
#include "Purchase.h"
class PurchaseStack {
private:
	int top;
	int MAX_SIZE = 10;
	int size;
	Purchase *data;
	
public:
	PurchaseStack();
	PurchaseStack(int max);
	PurchaseStack(PurchaseStack& rhs);
	void Clear();
	int Size();
	int MaxStorage();
	bool Push(Purchase p);
	bool Pop();
	bool Top(Purchase& returnedPurchase);
	PurchaseStack& operator=(PurchaseStack& rhs);
	friend std::ostream& operator<<(std::ostream& out, PurchaseStack& rhs);
	~PurchaseStack();
};

#endif // !PURCHASESTACK_H