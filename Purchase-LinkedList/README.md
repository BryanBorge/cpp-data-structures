Part 1 – Create the PurchaseList Class
PurchaseList Class Specifications 
1.	Use a linked-list implementation for the PurchaseList class. 
2.	Create a PurchaseListNode struct to use in your implementation. This class definition should be defined as private inside the PurchaseList class. 
3.	Implement the following constructors:
a.	PurchaseList()
Default constructor. Creates an empty list.
b.	PurchaseList(const PurchaseList& otherList)
Creates a list that is a DEEP COPY of otherList.
4.	Implement a destructor that performs the necessary cleanup.
a.	~PurchaseList()
Clears the list and releases dynamically allocated memory.
5.	Add a member overload of the assignment operator with the following function prototype:
PurchaseList & operator=(PurchaseList& rhs)
This method should make a deep copy of the list parameter. Any data in the current instance should be removed before adding the new elements.
6.	Implement the following methods:
a.	void Clear()  
Clears the current list. Remember, when items are removed you MUST release memory.
b.	int Length() const
Returns the number of items in the current list. 
**Important: The runtime of this operation MUST be coded such that it is O(1). **
c.	void Add(const Purchase p)
Adds a Purchase to the list.
d.	void Add(const PurchaseList& otherList)
Adds all elements from otherList on to the current list (appends). Any data that exists in this instance before this function call should still be in the list after the function call completes. It does not matter where you add the elements. The otherList object should not change after this method is run. This should perform a DEEP COPY of the elements from the other list.
Here is sample call (assume a and b are PurchaseList type objects):
a.Add(b);  // All elements of b will be added to a
e.	bool FindByItemName(std::string itemName, Purchase &result) const
Finds the Purchase with the given item name. If the Purchase is found the result parameter should be populated with data from the target Purchase. If found the function return value should be true otherwise return false.
f.	void Delete(std::string itemName)
Deletes the Purchase that matches the passed in item name. Remember, when items are removed you MUST release memory.
g.	Add a non-member operator<< overload. Prints the values of all elements of the list on the given ostream. Here is the method signature:
std::ostream &operator<<(std::ostream& os, PurchaseList& rhs);
Here is a sample use:
	   PurchaseList pl;

	   // Add Purchase data to pl here…
	
	   std::string filename;
   std::ofstream outfile(filename);
	   outfile << pl;

h.	Add a non-member operator>> overload. Loads the values of all elements of the list from the given istream. Here is the method signature:
std::istream &operator>>(std::istream& is, PurchaseList& rhs);

Here is sample code that uses this overload:
	   PurchaseList pl;
   std::string filename("PurchaseData.txt");
	   std::ifstream infile(filename);
	   infile >> pl;

Hint: You might want to use the >> overload on the Purchase class to make it easier to write this function.

IMPORTANT: You can assume that one word strings are being used for title and rating in the input file in order to make it a little easier to code. This is important because if you did not make that assumption you could not use the >> operator to read in the string values. The >> operator only reads up until the first whitespace it encounters.

7.	Big-O Runtime Costs. 
For each PurchaseList method you must include method header comments as detailed in the “Commenting Guidelines” document on Blackboard. Each method header comment must include the Big-O runtime cost of that particular method. You will lose points if you leave out any of the big-O runtime costs from the method header comments or if they are incorrect.

Part 2 – Main Function
The console application should have a main function. In main you should create instances of the PurchaseList class and demonstrate that ALL functions work properly. You can write unit testing code if you want but you are not required to.

Purchase File Format
ItemName
Quantity
ItemPrice
ItemName
Quantity
ItemPrice
…
ItemName
Quantity
ItemPrice

Sample Purchase File (there is no descriptive text, just the data, leave spaces out of the title to make it easier to read in)
Headset
59.99
10
Cable
74.59
20
Keyboard
5
29.99
