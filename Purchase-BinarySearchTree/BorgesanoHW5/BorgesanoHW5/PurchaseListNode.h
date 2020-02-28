//****************************************************
// File: PurchaseListNode.h
//
// Purpose: struct definition for PurchaseListNode
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************

#ifndef PURCHASELISTNODE_H
#define PURCHASELISTNODE_H
#include "Purchase.h"
struct PurchaseListNode 
{
	Purchase data;
	PurchaseListNode *next;
};
#endif // !PURCHASELISTNODE_H