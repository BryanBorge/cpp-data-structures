//****************************************************
// File: Main.cpp
//
// Purpose: Contians main program code to test Purchase
//          and Purchase Collection class
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
#include "PurchaseCollection.h"
#include <iostream>
using namespace std;

int main()
{
	int testQuantity = 5;
	double testPrice = 10.00;
	string testName = "test";

	Purchase purchaseTest;
	purchaseTest.SetItemName(testName);
	purchaseTest.SetItemPrice(testPrice);
	purchaseTest.SetQuantity(testQuantity);

	cout << "Purchase Get/Set Test" << endl;
	cout << "---------------------" << endl;
	if (purchaseTest.GetItemName() == testName)
	{
		cout << "Purchase Get/Set item name: PASS" << endl;
	}
	else
	{
		cout << "Purchase Get/Set item name: FAIL" << endl;
	}

	if (purchaseTest.GetItemPrice() == testPrice)
	{
		cout << "Purchase Get/Set item price: PASS" << endl;
	}
	else
	{
		cout << "Purchase Get/Set item price: FAIL" << endl;
	}

	if (purchaseTest.GetQuantity() == testQuantity)
	{
		cout << "Purchase Get/Set quantity: PASS" << endl;
	}
	else
	{
		cout << "Purchase Get/Set quantity: FAIL" << endl;
	}

	cout << "\nPurchase Collention Test" << endl;
	cout << "------------------------" << endl;

	PurchaseCollection Collection;
	Purchase p1("keyboard", 1, 20.00);
	Purchase p2("mouse", 1, 10.00);
	Purchase p3("monitor", 2, 100.00);
	Purchase p4("headphones", 1, 50.00);
	Purchase p5("usb", 1, 5.00);

	Collection.Set(0, p1);
	Collection.Set(1, p2);
	Collection.Set(2, p3);
	Collection.Set(3, p4);
	Collection.Set(4, p5);

	int priceCountTest = 3;
	Collection.ItemPriceCount(5, 20) == priceCountTest ? cout << "Item price count: PASS" << endl : cout << "Item price count: FAIL" << endl;

	Purchase mostExpensiveTest = Collection.MostExpensivePurchase();
	mostExpensiveTest.GetItemName() == "monitor" ? cout << "Most expensive purchase: PASS" << endl : cout << "Most expensive purchase: FAIL" << endl;

	Collection.FindByItemName("headphones", p4) ? cout << "Find Item by name: PASS" << endl : cout << "Find item by name: FAIL" << endl;
	Collection.FindByItemName("usb", p5) ? cout << "Find Item by name: PASS" << endl : cout << "Find item by name: FAIL" << endl;
	Collection.FindByItemName("speakers", p1) ? cout << "Find Item by name: PASS" << endl : cout << "Find item by name: FAIL (intentionally)" << endl;

	int totalCostTest = 285;
	Collection.TotalCost() == totalCostTest ? cout << "Total cost: PASS" << endl : cout << "Total cost: FAIL" << endl;
	
	return 0;

}