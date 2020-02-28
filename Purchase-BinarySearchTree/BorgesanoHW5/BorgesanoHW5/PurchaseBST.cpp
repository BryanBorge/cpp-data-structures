//****************************************************
// File: PurchaseBST.cpp
//
// Purpose:  Source file for Purchase Binary Search Tree class
//
// Written By: Bryan Borgesano
//
// Compiler: Visual Studio Community 2017
// 
// Update Information
// ------------------
//
//****************************************************
#include "PurchaseBST.h"

//****************************************************
// Function: Default constructor
//
// Purpose: Set root of BST to NULL
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
PurchaseBST::PurchaseBST()
{
	root = NULL;
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: Calls the assignment operator which calls CopyTree to make 
//          a deep copy of the passed in tree with the same structure
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
PurchaseBST::PurchaseBST(PurchaseBST & rhs)
{
	*this = rhs;
}

//****************************************************
// Function: CopyTree
//
// Purpose: Makes a deep copy of the passed in tree with the same structure
//
//// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::CopyTree(PurchaseBSTNode *&copyTree, PurchaseBSTNode * originalTree)
{
	if (originalTree == NULL)
	{
		copyTree = NULL;
	}
	else
	{
		Add(originalTree->data);
		CopyTree(copyTree->left, originalTree->left);
		CopyTree(copyTree->right, originalTree->right);
	}
}

//****************************************************
// Function: operator= Overload
//
// Purpose: Calls CopyTree() to make a deep copy of the passed in BST
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
PurchaseBST & PurchaseBST::operator=(PurchaseBST& rhs)
{
	this->Clear();
	CopyTree(this->root, rhs.root);
	return *this;
}

//****************************************************
// Function: GetSize
//
// Purpose: Returns the number of elements currently in the BST
//
// Big-O Runtime: O(1)
//
//Update Information
// ------------------
//
//****************************************************
int PurchaseBST::GetSize()
{
	return size;
}

//****************************************************
// Function: Add (public)
//
// Purpose: Calls private helper function to recursively add 
//          an element to the BST
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Add(Purchase p)
{
	size++;
	Add(root, p);
}

//****************************************************
// Function: Add (private)
//
// Purpose: Recursively add an element to the BST
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Add(PurchaseBSTNode *& tree, Purchase p)
{
	if (tree == NULL)
	{
		tree = new PurchaseBSTNode;
		tree->left = NULL;
		tree->right = NULL;
		tree->data = p;
	}
	else if (p < tree->data)
		Add(tree->left, p);
	else
		Add(tree->right, p);
}

//****************************************************
// Function: Preorder(public)
//
// Purpose: Calls private helper function to recursively 
//		    print BST using a post order traversal
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Preorder()
{
	Preorder(root);
}
//****************************************************
// Function: Preorder (private)
//
// Purpose: Recursively prints BST using a post order traversal
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Preorder(PurchaseBSTNode *tree)
{
	if (tree != NULL)
	{
		std::cout << tree->data.GetItemName() << " ";
		Preorder(tree->left);
		Preorder(tree->right);

	}
}

//****************************************************
// Function: Inorder(public)
//
// Purpose: Calls private helper function to recursively 
//		    print BST using an in order traversal
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Inorder()
{
	Inorder(root);
}
//****************************************************
// Function: Inorder (private)
//
// Purpose: Recursively prints BST using an in order traversal
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Inorder(PurchaseBSTNode *tree)
{
	if (tree != NULL)
	{
		Inorder(tree->left);
		std::cout << tree->data.GetItemName() << " ";
		Inorder(tree->right);
	}	
}

//****************************************************
// Function: Post order (public)
//
// Purpose: Calls private helper function to recursively 
//		    print BST using an post order traversal
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Postorder()
{
	Postorder(root);
}

//****************************************************
// Function: Post order (private)
//
// Purpose: Calls private helper function to recursively 
//		    print BST using an in order traversal
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Postorder(PurchaseBSTNode *tree)
{
	if (tree != NULL)
	{
		Postorder(tree->left);
		Postorder(tree->right);
		std::cout << tree->data.GetItemName() << " ";
	}
}

//****************************************************
// Function: PrintTree (private)
//
// Purpose: Recursively prints all the data for each element to the console
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::PrintTree(std::ostream &out,  PurchaseBSTNode *tree)
{
	if (tree != NULL)
	{
		PrintTree(out, tree->left);
		std::cout << tree->data;
		PrintTree(out, tree->right);
	}
}

//****************************************************
// Function: operator<< overload
//
// Purpose: Calls helper function PrintTree to recursively print
//          all elements of the tree to the console
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
std::ostream & operator<<(std::ostream &out,PurchaseBST &rhs)
{
	rhs.PrintTree(out, rhs.root);
	return out;
}

//****************************************************
// Function: GetCost (public)
//
// Purpose: Calls private helper function to recursively 
//          search the BST to calculate the cost of 
//          the given Purchase based on its name
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
bool PurchaseBST::GetCost(std::string itemName, double & cost)
{
	return GetCost(root,itemName,cost);
}

//****************************************************
// Function: GetCost (private)
//
// Purpose: Recursively search BST until item is found then update cost param and 
//			return true, other wise return false.
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
bool PurchaseBST::GetCost(PurchaseBSTNode *tree,std::string itemName, double &cost)
{
	if (tree == NULL)
		return false;
	else if (itemName < tree->data.GetItemName())
		return GetCost(tree->left, itemName, cost);
	else if (itemName > tree->data.GetItemName())
		return GetCost(tree->right, itemName, cost);
	else
	{
		cost = tree->data.Cost();
		return true;
	}
}

//****************************************************
// Function: Clear(public)
//
// Purpose: Calls private helper function to recursively 
//          release all dynamically allocated memory
//
// Big-O Runtime: O(1)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Clear()
{
	size = 0;
	Clear(root);
	root = NULL;
}

//****************************************************
// Function: Clear(private)
//
// Purpose: Recursively releases all dynamically allocated memory
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void PurchaseBST::Clear(PurchaseBSTNode *&tree)
{
	if (tree != NULL)
	{
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}

//****************************************************
// Function: Destructor
//
// Purpose: Calls Clear to recursively release all
//          dynamically allocated memory
//
// Big-O Runtime: O(n)
//
// Update Information
// ------------------
//
//****************************************************
PurchaseBST::~PurchaseBST()
{
	Clear(root);
}


