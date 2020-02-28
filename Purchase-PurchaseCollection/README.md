Part 1 – Create a Purchase Class
Write a class named Purchase.
Purchase Class Specifications
1.	Include member variables for itemName (string), quantity (double), itemPrice (double).
2.	Write a default constructor.
3.	Write a constructor that takes values for all member variables as parameters.
4.	Write a copy constructor.	
5.	Implement Get/Set methods for all member variables.
6.	Implement the Cost function. This function should multiply the itemPrice by the quantity and return that value. Use the following function header: double Cost().
7.	Add a member overload for the assignment operator.
8.	Add a non-member operator<< overload. Prints the values of all member variables on the given ostream. 

Part 2 – Create a PurchaseCollection Class
Write a class that will store a collection of Purchase. This class will be used to keep track of data for multiple Purchase class instances. You MUST implement ALL of the specifications below.

PurchaseCollection Class Specifications
1.	Create a private member variable that is an array of Purchase. The size of the array can be whatever you want it to be.
2.	Your class must implement all of the following functions (use the given function prototypes):
a.	void Set(int index, Purchase p) – Sets the value at the given index to the given Purchase instance. You should test the index to make sure that it is valid. If the index is not valid then do not set the value.
b.	Purchase Get(int index) – Return the Purchase located at the given index in the array.
c.	int ItemPriceCount(double lowerBound, double upperBound) – Returns the count of the number of Purchases that fall within the given range for the price. For example, assume the following number of Purchase item prices: 10, 20, 15, 25, 30, 40
If lowerBound is 20 and upperBound is 30 then the returned value should be 3. Any values that fall on the boundaries should be included in the count. In this example we are getting a count of the number of purchases that have an item price between $20 and $30. Remember, this function is using price (not cost).
d.	Purchase MostExpensivePurchase() – Returns the Purchase in the collection that has the highest cost (not itemprice).
e.	bool FindByItemName(string itemName, Purchase &p) – Returns true if the Purchase with the given name is in the array and false otherwise. If the Purchase is in the array you should copy it into the Purchase reference parameter.
f.	double TotalCost() – Returns the sum of the cost (not item price) of Purchase instances in the collection.
g.	int Size() – Returns the size of the array.
h.	void Initialize() – Initializes all of the elements of the array to reasonable default values.
i.	string GetAuthor() – Returns your name. Just hard code your name into the function.
3.	Create a default constructor that will initialize all elements of the array to default values.

Part 4 – Main Function
Main should create instances of Purchase and PurchaseCollection and contain an automated unit test for both of them.
Automated Test
Use the Automated Testing slides on Blackboard as a guide when coding this section. 

Create an automated unit test in main. You need to write code to automatically test that both classes work properly. The automated test should contain code to unit test the following functions:
•	All Purchase get/set functions.
•	PurchaseCollection Get.
•	PurchaseCollection Set.
•	PurchaseCollection ItemPriceCount.
•	PurchaseCollection MostExpensivePurchase.
•	PurchaseCollection FindByItemName.
•	PurchaseCollection TotalCost.
