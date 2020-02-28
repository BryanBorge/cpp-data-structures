#include "PurchaseList.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//Homework Tests
	
	//operator>> overload & operator<< test
	PurchaseList inList;
	
	string inFileName, outFileName;
	cout << "Enter input file: ";
	cin >> inFileName;
	ifstream inFile(inFileName);

	cout << "Enter output file: ";
	cin >> outFileName;
	ofstream outFile(outFileName);

	inFile >> inList;
	
	cout << "\nOperator>> &  Operator<< Overload Test" << endl;
	cout << "------------------------" << endl;
	cout << inList;
	outFile << inList;
	cout << "length: " << inList.Length() << endl << endl;

	//Copy constructor test
	PurchaseList copyList(inList);
	cout << "Copy Constructor Test" << endl;
	cout << "---------------------" << endl;
	cout << copyList;
	cout << "Length: " << copyList.Length() << endl << endl;

	//Add Purchase Test
	Purchase hatPurchase ("Hat", 1, 10);
	copyList.Add(hatPurchase);
	cout << "Add Purchase Instance Test" << endl;
	cout << "--------------------------" << endl;
	cout << copyList;
	cout << "Length: " << copyList.Length() << endl << endl;

	//Add PurchaseList Test
	Purchase p1("Watch", 1, 100);
	Purchase p2("Shoes", 1, 50);
	Purchase p3("Jacket", 1, 75);
	PurchaseList fancyList;
	fancyList.Add(p1);
	fancyList.Add(p2);
	fancyList.Add(p3);
	copyList.Add(fancyList);
	cout << "Add PurchaseList Test" << endl;
	cout << "---------------------" << endl;
	fancyList.Clear();//clearing this list does not cause a memory leak
	cout << copyList;
	cout << "Length: " << copyList.Length() << endl << endl;
 

	//FindItem and Delete test
	cout << "FindItemByName and Delete Test" << endl;
	cout << "------------------------------" << endl;
	Purchase test;
	bool containsItem;
	containsItem = copyList.FindByItemName("Hat",test);
	if (containsItem)
	{
		cout << containsItem << endl << test << endl;
	}
	else
	{
		cout << containsItem << "Item Not Found" << endl;
	}

	copyList.Delete("Hat");
	containsItem = copyList.FindByItemName("Hat", test);
	if (containsItem)
	{
		cout << containsItem << endl << test << endl;
	}
	else
	{
		cout << containsItem << " Item Not Found" << endl;
	}

	//operator= overload test
	cout << "\nOperator= Overload Test" << endl;
	cout << "------------------------------" << endl;
	PurchaseList overloadList = copyList;
	copyList.Clear(); //clearing this list does not cause a memory leak
	cout << overloadList;
	cout << "Length: " << overloadList.Length() << endl << endl;

	inFile.close();
	outFile.close();
	

	//Corrections Test
	/*
	PurchaseList thisOne;

	Purchase p1("Hat", 1, 10);
	Purchase p2("Shoes", 1, 20);
	Purchase p3("Shirt", 1, 15);
	thisOne.Add(p1);
	thisOne.Add(p2);
	thisOne.Add(p3);
	 

	thisOne.RecursiveTraversal();

	PurchaseList thatOne;
	Purchase g1("Watch", 1, 50);
	Purchase g2("Paint", 2, 50);
	Purchase g3("Pants", 3, 50);
	thatOne.Add(g1);
	thatOne.Add(g2);
	thatOne.Add(g3);

	thatOne.RecursiveTraversal();

	thisOne.Add(thatOne);
//	cout << "-BEFORE CLEAR-" << endl;
	//cout << thisOne;
	thatOne.Clear();
	//cout << "-AFTER CLEAR-" << endl;
//	cout << thisOne;
	
	PurchaseList empty2;
	PurchaseList empty(empty2);
	
	
	
	//PurchaseList OK;
	//PurchaseList k;
	//k = OK;
	
	*/
	return 0;
}