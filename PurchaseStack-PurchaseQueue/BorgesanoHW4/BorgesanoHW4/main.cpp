#include "Purchase.h"
#include "PurchaseQueue.h"
#include "PurchaseStack.h"
using namespace std;
int main()
{

	Purchase p1("Hat", 1, 10);
	Purchase p2("Shoes", 1, 20);
	Purchase p3("Shirt", 1, 15);
	
	cout << "-QUEUE TESTS-" << endl;
	cout << "-------------" << endl;

	PurchaseQueue startQueue;

	startQueue.Enqueue(p1);
	startQueue.Enqueue(p2);
	startQueue.Enqueue(p3);

	cout << "-Enqueue Test: starting queue-\n" << startQueue;
	cout << "Size: " << startQueue.Size() << endl << endl;


	PurchaseQueue copyQueue(startQueue);
	cout << "-Copy Constructor/Operator= Overload test-\n" << copyQueue << endl;
	cout << "Size: " << copyQueue.Size() << endl << endl;
	
	Purchase dq;
	bool result;
	result = startQueue.Dequeue(dq);

	cout << "-Dequeue Test: starting queue-\n" << startQueue << endl;
	cout << "Size: " << startQueue.Size() << endl << endl;
	cout << "-Dequeue Test: copy queue remains after starting queue dequeue-\n" << copyQueue << endl;
	cout << "Size: " << copyQueue.Size() << endl << endl;

	//Enqueue - full queue test
	PurchaseQueue fullQueue;
	cout << "-Enqueue on full queue test-" << endl;
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	fullQueue.Enqueue(p1);
	cout << "Size: " << fullQueue.Size() << endl << endl;

	//Dequeue - empty list test
	cout << "\n-Dequeue on empty queue test-\n";
	PurchaseQueue emptyQueue;
	Purchase emptyDQ;
	result = emptyQueue.Dequeue(emptyDQ);
	cout << "Size: " << emptyQueue.Size() << endl << endl;

	

	cout << "-STACK TESTS-" << endl;
	cout << "-------------" << endl;
	PurchaseStack startStack;

	startStack.Push(p1);
	startStack.Push(p2);
	startStack.Push(p3);

	cout << "-Stack push test: startStack-\n" << startStack << endl;
	cout << "Size: " << startStack.Size() << endl << endl;


	PurchaseStack copyStack(startStack);
	cout << "-Copy Constructor/Operator= Test: copyStack-\n" << startStack << endl;
	cout << "Size: " << copyStack.Size() << endl << endl;
	

	result =  startStack.Pop();
	if (result == false)
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		cout << "-Pop test: start stack-\n" << startStack << endl;
		cout << "Size: " << startStack.Size() << endl;

		cout << "-Pop test: copy stack remains after start stack is popped-\n" << copyStack << endl;
		cout << "Size: " << copyStack.Size() << endl;
	}

	// Push - full stack test
	PurchaseStack fullStack;
	cout << "\n-Push on full stack test-" << endl;
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	fullStack.Push(p1);
	cout << "Size: " << fullStack.Size() << endl;

	// Pop - empty stack test
	PurchaseStack emptyStack;
	cout << "\n-Pop on empty stack test-" << endl;
	emptyStack.Pop();
	cout << "Size: " << emptyStack.Size() << endl;
	
	
	Purchase returnTop;
	startStack.Top(returnTop);
	cout << "\n-Top test-" << endl;
	cout << returnTop << endl;

	cout << "-Max Storage Test-" << endl;
	cout << "Max storage: " << startStack.MaxStorage();
	


	return 0;
}