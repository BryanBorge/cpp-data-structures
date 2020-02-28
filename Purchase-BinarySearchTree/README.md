Program to Write
Write a binary search tree of Purchase objects (see specifications below). The definition of this class should be added to the Purchase static library you have been using for the previous assignments. 

Make an update to the Purchase class for the less than and greater than operator overloads. 

Create an application that will test the binary search tree. Import the static library into the testing application.

Part 0 – Update the Purchase Class

Purchase Class Update
1.	Add a non-member overload for the less than operator. Here is the function prototype: 
bool operator<(Purchase &lhs, Purchase& rhs)
This function should return true if the VALUE of the lhs item name (this means the data and not the pointer) is less than the rhs item name. Return false otherwise.
2.	Add a non-member overload for the greater than operator. Here is the function prototype: 
bool operator>(Purchase &lhs, Purchase& rhs)
This function should return true if the VALUE of the lhs item name (this means the data and not the pointer) is greater than the rhs item name. Return false otherwise.

Part I – Binary Search Tree

PurchaseBST Class Specifications
The binary search tree should be keyed on the Purchase item name field. USE THE Purchase OPERATOR OVERLOADS TO COMPARE INSTANCES OF Purchase!!!!!!!!!!!! If you made a mistake from previous homework you will need to fix it.

1.	Use a linked implementation for the PurchaseBST class. 
2.	Implement a struct called PurchaseBSTNode. Each node should hold a Purchase and pointers to the left subtree and the right subtree. The PurchaseBSTNode struct should be defined INSIDE the PurchaseBST class.
3.	Implement the following constructors:
a.	PurchaseBST()
Creates an empty binary search tree. 
b.	PurchaseBST(const PurchaseBST& rhs)
Copy constructor. This function should make a deep copy of the passed- in binary search tree. THE STRUCTURE OF THE TREE OF THE COPY SHOULD BE EXACTLY THE SAME AS THE ORIGINAL TREE!!! 
4.	Implement a destructor that performs the necessary cleanup.
a.	~PurchaseBST()
Clears the binary search tree and releases ALL dynamically allocated memory. Remember, when items are removed you MUST release memory.
5.	Implement the following functions:
a.	void Clear()
Clears the binary search tree and releases ALL dynamically allocated memory. Remember, when items are removed you MUST release memory.
Hint: You can create a private helper function overload that takes the root node as a parameter and recursively clears the tree.
b.	int Size()
Returns the number of elements that are currently in the binary search tree.
c.	void Add(Purchase p)
Add a Purchase object to the binary search tree. It should be added to the binary search tree according to the search key (Purchase item name in this case). YOU MUST use the appropriate operator overloads of the Purchase class when implementing this function.
Hint: You can create a private helper function overload that takes the root node as a parameter and recursively adds to the tree.
d.	void Preorder()
Print only the item name of all the Purchase objects in the binary search tree on the console. The output should be done using a preorder traversal of the binary search tree. YOUR SOLUTION MUST USE RECURSION!
Hint: You can create a private helper function overload that takes the root node as a parameter and recursively displays data in preorder fashion.
e.	void Inorder()
Print only the item name of all the Purchase objects stored in the binary search tree on the console. The output should be done using an inorder traversal of the binary search tree. YOUR SOLUTION MUST USE RECURSION!
Hint: You can create a private helper function overload that takes the root node as a parameter and recursively displays data in order.
f.	void Postorder()
Print only the item name of all the Purchase objects stored in the binary search tree on the console. The output should be done using a postorder traversal of the binary search tree. YOUR SOLUTION MUST USE RECURSION!
Hint: You can create a private helper function overload that takes the root node as a parameter and recursively displays data in postorder fashion.
g.	bool GetCost(string itemName, double& cost)
This function should return the cost of the given Purchase item name. If the item name is found return true from the function and return the cost in the cost reference parameter (do NOT print anything in this function, just return the cost through the reference parameter!). You need to search the binary search tree for the given item name then return the cost for that Purchase. If the item name is not found in the tree then just return false.
Hint: You can create a private helper function overload that also takes the root node as a parameter and recursively gets the cost.
h.	PurchaseBST& operator=(PurchaseBST& rhs) This function should make a deep copy of the rhs parameter. Any data in the current instance should be removed before adding the new elements (no memory leaks). THE STRUCTURE OF THE COPY SHOULD BE EXACTLY THE SAME AS THE ORIGINAL!!! 
Hint 1: You can create a private helper function to copy the nodes in a tree recursively.
Hint 2: You can use also use the Add function to help with this.
Hint 3: If you use the above hints (Copy and Add helper functions), think about when you call Copy and Add with respect to each other (preorder, inorder, or postorder).
i.	Non-member operator<< overload
Print the values of ALL elements on the binary search tree on the given ostream. Show ALL of the Purchase object’s data for each node in the binary search tree using an inorder traversal (DO NOT CALL INORDER TO DO THIS). This function is similar to the Inorder function except that you show ALL the data that is stored at each node. The easiest way to do this is to call the Purchase operator<< overload when you visit each node.
Hint: You can create a private helper function to call from this function.

6.	Big-O Runtime Costs. 
For each PurchaseBST function you must include function header comments as detailed in the “Commenting Guidelines” document on Blackboard. Each function header comment should include the Big-O runtime cost of that particular function.

Note: If the Big-O runtime cost is incorrect I will take off points.

Part III – Main Testing Code
Create a C++ console application that imports and uses the static library solution that you created. The console application should have a main function. In main you should create instances of the PurchaseBST and demonstrate that ALL functions work properly. You can write unit testing code if you want but you are not required to.
