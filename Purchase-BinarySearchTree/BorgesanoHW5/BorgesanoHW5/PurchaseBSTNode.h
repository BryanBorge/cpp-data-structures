#ifndef PURCHASEBSTNODE_H
#define PURCHASEBSTNODE_H
#include "Purchase.h"
struct PurchaseBSTNode
{
	Purchase data;
	PurchaseBSTNode *left;
	PurchaseBSTNode *right;
};
#endif // !PURCHASEBSTNODE_H