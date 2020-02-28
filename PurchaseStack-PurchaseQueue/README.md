Program to Write
Write a Stack of Purchase objects and a Queue of Purchase objects (see specifications below). Add these new classes to the Purchase static library. Update the Purchase class so that it has an implementation of the equality operator overload. Create an application that will test both the Stack class and the Queue class. 

Part 0 – Update the Purchase Class

Purchase Class Update
1.	Add a non-member overload for the equality operator. Here is the function prototype: 
bool operator==(Purchase &lhs, Purchase& rhs)
This method should return true if the VALUES (this means the data and not the pointers) of the name members are equal and false otherwise.

Part I – PurchaseStack

PurchaseStack Class Specifications
1.	Create an ARRAY-BASED implementation for the PurchaseStack class. You should use a dynamic array to hold the stack’s data.
2.	Implement the following constructors:
a.	PurchaseStack()
Creates an empty stack. The stack maximum storage should be 10. 
b.	PurchaseStack(int max)
Creates an empty stack. The stack maximum should be set to the passed in value.
c.	PurchaseStack(const PurchaseStack& rhs)
Copy constructor. Makes a deep copy of the passed in value. The max size for the current instance should also be changed to match the passed in value.
3.	Implement the following methods:
a.	~PurchaseStack()
Releases dynamic memory.
b.	void Clear()
Clears the stack.
c.	int Size()
Returns the number of elements that are currently on the stack. The “logical” size of the stack.
d.	int MaxStorage()
Returns the maximum number of elements the stack can hold. This is the actual number of elements the stack can possibly hold (not the “logical” size).
e.	bool Push(Purchase p)
Adds the given Purchase object to the top of the stack. If successful return true otherwise return false. This method should return false if there is a stack overflow.
f.	bool Pop()
Removes the top element of the stack. If successful return true otherwise return false. This method should return false if there is a stack underflow.
g.	bool Top(Purchase &returnedPurchase)
Gets the top element of the stack without removing it. The parameter returnedPurchase should contain a copy of the top element of the stack after Top completes. It should return true if successful and false otherwise. It the stack is empty it should return false. In the following example x should contain a copy of the top element of the stack when Top() completes (assume x is an Purchase object and s is an PurchaseStack object):
PurchaseStack s;
Purchase x;
// Other code to load the stack here…
s.Top(x);  // x contains a copy of the top element when Top ends.
h.	PurchaseStack & operator=(PurchaseStack& rhs) This method should make a deep copy of the PurchaseStack parameter. Any data in the current instance should be removed before adding the new elements.
i.	Non-member operator<< overload
Prints the values of all elements on the stack to the given ostream.
4.	Big-O Runtime Costs. 
For each PurchaseStack method you must include method header comments as detailed in the “Commenting Guidelines” document on Blackboard. Each method header comment should include the Big-O runtime cost of that particular method.

Part II – PurchaseQueue

PurchaseQueue Class Specifications
1.	Use a LINKED-LIST implementation for the PurchaseQueue class.
2.	Implement the following constructors:
a.	PurchaseQueue()
Creates an empty queue.
b.	PurchaseQueue(const PurchaseQueue& rhs)
Copy constructor.
3.	Implement a destructor that performs the necessary cleanup.
a.	~PurchaseQueue()
Clears the queue and releases dynamically allocated memory.
4.	Implement the following methods:
a.	void Clear()
Clears the current queue. Remember, when items are removed you MUST release memory.
b.	int Size()
Returns the number of elements in the queue. MUST HAVE A RUNTIME OF O(1).
c.	void Enqueue(Purchase p)
Adds an Purchase object to the end of the queue.
d.	bool Dequeue(Purchase& returnedPurchase)
Removes and returns the first element of the queue. If the operation is successful (queue not empty) return true otherwise return false. 

In the following example a should contain the element that was removed from the queue (assume a is a Purchase object and q is a PurchaseQueue object):
Purchase  a;
bool result;
result = q.Dequeue(a);  // a contains removed element when Dequeue ends.
e.	PurchaseQueue & operator=(const PurchaseQueue& rhs) This method should make a deep copy of the PurchaseQueue parameter. Any data in the current instance should be removed before adding the new elements.
f.	Non-member operator<< overload
Prints the values of all elements of the queue on the given ostream.
5.	Big-O Runtime Costs. 
For each PurchaseQueue method you must include method header comments as detailed in the “Commenting Guidelines” document on Blackboard. Each method header comment should include the Big-O runtime cost of that particular method.


Part III – Main Testing Code
Create a C++ console application that imports and uses the static library solution that you created. The console application should have a main function. In main you should create instances of the PurchaseStack and PurchaseQueue classes and demonstrate that ALL functions work properly. You can write unit testing code if you want but you are not required to.
