//****************************************************
// File: PurchaseQueue.h
//
// Purpose:  Class definiton for a Queue ADT of Purchases
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************

#ifndef PURCHASEQUEUE_H
#define PURCHASEQUEUE_H
#include "PurchaseQueueNode.h"
class PurchaseQueue
{
private:
	PurchaseQueueNode *front;
	PurchaseQueueNode *rear;
	int MAX_SIZE = 10;
	int size;

public:
	PurchaseQueue(); 
	PurchaseQueue(const PurchaseQueue& rhs); 
	void Clear(); 
	int Size(); 
	void Enqueue(Purchase p);
	bool Dequeue(Purchase& returnedPurchase);
	PurchaseQueue& operator=(const PurchaseQueue& rhs); 
	friend std::ostream& operator<<(std::ostream &out, const PurchaseQueue &rhs); 
	~PurchaseQueue();
};
#endif // !PURCHASEQUEUE_H