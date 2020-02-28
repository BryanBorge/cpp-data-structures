#include <iostream>
#include "PurchaseCollection.h"
using namespace std;

int main()
{
	Purchase p1("soda", 1, 1.00);
	Purchase p2("chips", 2, 3.00);
	Purchase p3;
	p3 = p1;
	Purchase p4(p2);

	PurchaseCollection collection(4);

	collection.Set(0, p1);
	collection.Set(1, p2);
	collection.Set(2, p3);
	collection.Set(3, p4);

	cout << "- Original Array - \n";
	cout << "------------------" << endl;
	cout << collection;


	//Get methods test
	cout << "\n- PurchaseCollection::Get Method - \n";
	cout << "----------------------------------" << endl;
	for (int i = 0; i < collection.Size(); i++)
	{
		cout << collection.Get(i) << endl;
	}


	//Total cost test
	int totalCost = 14;
	if (collection.TotalCost() == totalCost)
	{
		cout << "Collection::TotalCost - PASS" << endl;
		cout << "----------------------------" << endl;
	}
	else
	{
		cout << "Collection::TotalCost - FAIL" << endl;
		cout << "----------------------------" << endl;
	}

	//Resize bigger test
	collection.Resize(8);
	cout << "\n- Resize Bigger - \n";
	cout << "-------------------" << endl;
	cout << collection;

	//Resize smaller test
	collection.Resize(2);
	cout << "\n- Resize Smaller - \n";
	cout << "-------------------" << endl;
	cout << collection;

	//Test clone function
	PurchaseCollection *clone = collection.Clone();
	PurchaseCollection copyCollection(collection);

	cout << "\n- PurchaseCollection::Copy Constructor - \n";
	cout << "---------------------------------------------" << endl;
	cout << copyCollection;

	cout << "\n- PurchaseCollection::Clone- \n";
	cout << "----------------------------------" << endl;
	cout << *clone;

	//Test operator= with different size arrays
    PurchaseCollection bigCollection(10);
	PurchaseCollection smallCollection(2);
	bigCollection.Set(0, p1);
	bigCollection.Set(1, p2);
	bigCollection.Set(2, p3);
	bigCollection.Set(3, p4);

	cout << "- Operator= small array->large array -" << "\n--------------------------------------\n" << endl;
	smallCollection = bigCollection;
	cout << smallCollection;

	smallCollection.Resize(2);

	cout << "- Operator= large array->small array -" << "\n--------------------------------------\n" << endl;
	bigCollection = smallCollection;
	cout << bigCollection;


	return 0;
}