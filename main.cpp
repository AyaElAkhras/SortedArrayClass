#include <iostream>
#include "SortedArray.h"
using namespace std;

int main()
{
	// experiment 10
	SortedArray arr_1(7);

	for (int i = 0; i < 7; i++)
		arr_1.setat(i, 7 - i);

	unsigned int temp = arr_1[3];
	unsigned int temp2 = arr_1.getat(2); 
	cout << "Elements of arr_1 are " << endl;
	cout << arr_1 << endl; 

	cout << "arr_1[3] = " << temp<< endl;
	cout << "arr_1[2] = " << temp2 << endl;

	/*
	// experiment 9
	// Another experiment for []
	SortedArray arr_1(7);
	SortedArray arr_2(5);
	
	for (int i = 0; i < 7; i++)
		arr_1.setat(i, 7 - i);

	arr_2[0] = arr_1[1];
	cout << arr_1[1] << endl; 
	cout << arr_2[0] << endl; 
	*/

	/*
	// experiment 8
	// Testing the assignment operator 
	SortedArray arr_1(7);

	for (int i = 0; i < 7; i++)
		arr_1.setat(i, 7-i);

	SortedArray arr_2(5);
	arr_2[3] = 3;
	arr_2[2] = 1; 

	arr_1 = arr_2; 

	cout << "Elements of arr_2 are: " << endl; 
	cout << arr_2 << endl; 

	cout << "Elements of arr_1 are: " << endl;
	cout << arr_1 << endl;
	*/


	/*
	// experiment 7 
	// Testing equality operator 
	SortedArray arr_1(7);
	SortedArray arr_2(5);
	
	for (int i = 0; i < 7; i++)
		arr_1[i] = i;

	for (int i = 0; i < 5; i++)
		arr_2[i] = 2+i;

	if (arr_1 == arr_2)
		cout << "The 2 arrays are equal to eachother " << endl;

	else
		cout << "The 2 arrays aren't equal to eachother " << endl; 

	*/
	
	/*
	// experiment 6
	// Testing output stream operator and square operator
	SortedArray arr_1(5);

	for (int i = 0; i < 5; i++)
		arr_1[i] = 4-i; 
	
	cout << arr_1 << endl; 
	*/


	/*
	// experiment 5
	// Error reporting to client if he attempts to insert a negative element to the array 
	try {
		SortedArray arr_1(20);
		arr_1[5] = -8;
	}

	catch (exception_type ex)
	{
		switch (ex)
		{
		case INVALID_ARGUMENT:
			cout << "Can't insert a negative entry inside the array!!" << endl;
			break;

		case MEMORY_ALLOCATION_FAILURE:
			cout << "Failed to allocate memory!!" << endl;
			break;

		case EMPTY_ENTRY:
			cout << "This entry isn't yet set, so is invalid! Can't retrieve an invalid entry!!" << endl;
			break;
		}
	}
	*/


	/*
	// experiment 4
	// Error Reporting for accessing element that was set but because of sorting it moved 
	try {
		SortedArray arr_1(20);
		arr_1[5] = 9;
		cout << "To maintain sorting the value is moved to the beginning of the array : " << endl << arr_1[0] << endl; 
		unsigned int temp = arr_1[5];
	}

	catch (exception_type ex)
	{
		switch (ex)
		{
		case INVALID_ARGUMENT:
			cout << "The chosen index is out of bounds!!" << endl;
			break;

		case MEMORY_ALLOCATION_FAILURE:
			cout << "Failed to allocate memory!!" << endl;
			break;

		case EMPTY_ENTRY:
			cout << "This entry isn't yet set, so is invalid! Can't retrieve an invalid entry!!" << endl;
			break;
		}
	}
	*/

	/*
	// experiment 2 and 3
	// Error Reporting for accessing elements at -ve index 
	try {
		SortedArray arr_1(20);
		unsigned int temp = arr_1[20];
	}

	catch (exception_type ex)
	{
		switch (ex)
		{
		case INVALID_ARGUMENT:
			cout << "The chosen index is out of bounds!!" << endl;
			break;

		case MEMORY_ALLOCATION_FAILURE:
			cout << "Failed to allocate memory!!" << endl;
			break;

		case EMPTY_ENTRY:
			cout << "This entry isn't yet set, so is invalid! Can't retrieve an invalid entry!!" << endl;
			break;
		}
	}
	*/

	/*
	// experiment 1 
	// Error Reporting for arrays with -ve sizes
	try {
		SortedArray arr_1(-5);
	}

	catch (exception_type ex)
	{
		switch (ex)
		{
		case INVALID_ARGUMENT:
			cout << "The chosen index is out of bounds!!" << endl;
			break;

		case MEMORY_ALLOCATION_FAILURE:
			cout << "Failed to allocate memory!!" << endl;
			break;

		case EMPTY_ENTRY:
			cout << "This entry isn't yet set, so is invalid! Can't retrieve an invalid entry!!" << endl;
			break;
		}
	}
	*/
	system("pause");
	return 0;
}

