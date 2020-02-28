Part 1 –Update Purchase and PurchaseCollection Classes

Purchase Class Updates
The Purchase class should implement all the specifications from the first assignment plus the updates and features listed below.

1.	Change all member variables to pointers. You will need to update code in any functions that use these member variables. Do NOT change any function signatures for this class. All functions should operate the same as before from the user of the classes’ perspective. For example, assume the get/set functions for item name have the following signatures:

std::string ItemName();
void SetItemName(std::string itemName);

These signatures should remain exactly the same. The same goes for any other functions that use these member variables. Only the internal implementation of the functions will change to accommodate the use of pointers.

2.	Update the constructors. The constructors should allocate memory for the pointer member variables.
3.	Add a destructor. The destructor should deallocate memory for the pointer member variables.
4.	Update operator= and copy constructor. The operator= and copy constructor should be updated to perform deep copies.
5.	Update operator<<. Make sure it prints out the values and not the addresses.
6.	Add a non-member operator>> overload. The >> operator is used for input. Reads the values of all member variables from the given istream. 
IMPORTANT: You can assume that one word strings are being used for strings in order to make it a little easier to code. This is important because if you did not make that assumption you could not use the >> operator to read in the string values. The >> operator only reads up until the first whitespace it encounters.

PurchaseCollection Class Updates
The PurchaseCollection class should implement all the specifications from the first assignment plus the updates and features listed below.

1.	Dynamic array. Change the internal implementation of the array so that the array is dynamically allocated.
2.	Add a size member variable to the class. This member variable should ALWAYS contain the number of elements in the array (size of the array). Some functions may cause the size of the array to change so make sure that this member variable is updated to reflect the new size.
3.	Update all the necessary code in the class so that it is usable with a dynamic array. One example of this is to change the ending condition of loops that visit all elements of the array. The ending limit should not be hard coded. They should use the new size variable as the ending condition.
4.	Add a one parameter constructor that takes a size. This constructor should dynamically allocate an array of the given size. It should also set the size member variable to reflect the size.
5.	Add a copy constructor. This function should make a deep copy of the passed in instance.
6.	Add a destructor. This function should perform any necessary cleanup.
7.	Add a member overload of operator= (assignment operator). This method should perform a deep copy of the passed in instance. After this function ends the size of the current instance’s array should be the same as the other instance’s array and all the data from the other instance should be copied into the current instance’s array.
Hint: C++ arrays have a fixed size. You may need to delete and then reallocate memory for the current instance’s array in order to make the current instance’s array the same size as the other instance’s array. Be careful for memory leaks.
8.	Add a non-member operator<< overload. Prints the values of all elements of the array on the given ostream. 
9.	Add a Resize function. Here is the function signature:
void Resize(int newSize);
This function should create a new array that has the passed in size. You MUST retain any values that were previously in the array. The new array size can be larger or smaller. If the new array size is SMALLER just retain as many elements from the previous array that can fit.
Hint: C++ arrays have a fixed size. You may need to delete and then reallocate memory. Be careful for memory leaks.
10.	Add a function named Clone with the following signature:
PurchaseCollection *Clone();
This method should allocate a new dynamic instance of PurchaseCollection that is a deep copy of the current instance. This method should return a pointer to the new instance.
Part 2 – Main Function
In main you should create instances of the updated PurchaseCollection class and demonstrate that ALL functions work properly. You can write unit testing code if you want but you are not required to. Make sure you call ALL functions.
