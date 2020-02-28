//****************************************************
// File: Main.cpp
//
// Purpose:  Main program code to test PurchaseBST class
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
#include "Purchase.h"
#include <iostream>
using namespace std;

int main()
{
	
	Purchase p1("Hat", 1, 10);
	Purchase p2("Shoes", 1, 20);
	Purchase p3("Shirt", 2, 15);
	Purchase p4("Pants", 3, 10);
	Purchase p5("Apple", 1, 55);
	Purchase p6("Bananna", 1, 15);
	Purchase p7("Dessert", 1, 11);
	Purchase p8("Zebra", 3, 20);
	Purchase p9("Washer", 3, 15);
	double cost = 0;

	PurchaseBST startTree;
	startTree.Add(p1);
	startTree.Add(p2);
	startTree.Add(p3);
	startTree.Add(p4);
	startTree.Add(p5);
	startTree.Add(p6);
	startTree.Add(p7);
	startTree.Add(p8);
	startTree.Add(p9);

	//*****************
	//Start Tree tests
	//*****************
	cout << "------------------" << endl;
	cout << "-Start Tree Tests-" << endl;
	cout << "------------------" << endl;
	cout << "Start tree size: " << startTree.GetSize() << endl;
	
	cout << "Start tree in order: ";
	startTree.Inorder();
	cout << "\n";
	
	cout << "Start tree post order: ";
	startTree.Postorder();
	cout << "\n";

	cout << "Start tree pre order: ";
	startTree.Preorder();
	cout << "\n";

	cout << startTree << endl;

	if (startTree.GetCost("Pants", cost))
		cout << "Pants cost $" << cost << endl;
	else
		cout << "Pants are not in the tree" << endl;

	if (startTree.GetCost("Car", cost))
		cout << "Car cost $" << cost << endl;
	else
		cout << "Car is not in the tree\n" << endl;


	//****************
	//Copy Tree tests
	//****************
	cout << "-----------------" << endl;
	cout << "-Copy Tree Tests-" << endl;
	cout << "-----------------" << endl;

	PurchaseBST copyTree(startTree);
	
	startTree.Clear();
	
	cout << "Copy tree size: " << copyTree.GetSize() << endl;

	cout << "Copy tree in order: ";
	copyTree.Inorder();
	cout << "\n";

	cout << "Copy tree post order: ";
	copyTree.Postorder();
	cout << "\n";

	cout << "Copy tree pre order: ";
	copyTree.Preorder();
	cout << "\n";

	cout << copyTree << endl;

	if (copyTree.GetCost("Zebra", cost))
		cout << "A zebra cost $" << cost << endl;
	else
		cout << "Zebra is not in the tree" << endl;

	if (copyTree.GetCost("Marker", cost))
		cout << "Marker cost $" << cost << endl;
	else
		cout << "Marker is not in the tree" << endl;
	
	
	return 0;
}