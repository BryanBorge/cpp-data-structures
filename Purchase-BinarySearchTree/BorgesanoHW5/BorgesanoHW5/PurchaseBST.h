//****************************************************
// File: PurchaseBST.h
//
// Purpose:  Class definiton for Purchase Binary Search Tree
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//              
//****************************************************
#ifndef PURCHASEBST_H
#define PURCHASEBST_H
#include "PurchaseBSTNode.h";

class PurchaseBST
{
private:
	PurchaseBSTNode *root;
	int size;
	void Add(PurchaseBSTNode *&tree, Purchase p); 
	void Clear(PurchaseBSTNode *&tree); 
	bool GetCost(PurchaseBSTNode *tree, std::string itemName, double &cost);  
	void Preorder(PurchaseBSTNode *tree); 
	void Inorder(PurchaseBSTNode *tree); 
	void Postorder(PurchaseBSTNode *tree); 
	void PrintTree(std::ostream &out, PurchaseBSTNode *tree); 
	void CopyTree(PurchaseBSTNode *&copyTree, PurchaseBSTNode *originalTree);

public:
	PurchaseBST(); 
	PurchaseBST(PurchaseBST &rhs); 
	PurchaseBST &operator=(PurchaseBST &rhs);
	friend std::ostream& operator<<(std::ostream &out,PurchaseBST &rhs); 
	void Clear(); 
	int GetSize(); 
	void Add(Purchase p); 
	void Preorder(); 
	void Inorder(); 
	void Postorder(); 
	bool GetCost(std::string itemName, double &cost);
	~PurchaseBST();
};

#endif // !"PURCHASEBST_H