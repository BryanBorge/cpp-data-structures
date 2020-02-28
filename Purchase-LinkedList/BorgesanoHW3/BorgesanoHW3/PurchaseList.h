//****************************************************
// File: PurchaseList.h
//
// Purpose:  Class definiton for PurchaseList
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//              
//****************************************************

#include "Purchase.h"
#include "PurchaseListNode.h"

class PurchaseList
{
private: 
	int m_length;
	PurchaseListNode *m_purchaseData;

public:
	PurchaseList();
	PurchaseList(PurchaseList& otherList); 
	~PurchaseList();
	PurchaseList& operator=(PurchaseList &rhs);
	void Clear();
	int Length(); 
	void Add(const Purchase p); 
	void Add(const PurchaseList& otherList); 
	bool FindByItemName(std::string itemName, Purchase &result) const; 
	void Delete(std::string itemName); 

	void RecursiveTraversal(PurchaseListNode *temp);  //added for practice 11-24-18
	void RecursiveTraversal(); //helper funtion calls recursive function

	friend std::ostream& operator<<(std::ostream &out, const PurchaseList &rhs);
	friend std::istream& operator>>(std::istream &in, PurchaseList &rhs);

};