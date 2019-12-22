#ifndef SORTEDARRAY_H
#define  SORTEDARRAY_H

#include <iostream>
#include <iomanip>
#include <string>

enum exception_type { INVALID_ARGUMENT, MEMORY_ALLOCATION_FAILURE, EMPTY_ENTRY };
const unsigned int ARRAY_INITIALIZER = INT_MAX;

//class SortedArray;
class CustomInt;

class SortedArray
{
public:
	explicit SortedArray(int size_ = 10);  // works as both default and integer constructor 
	SortedArray(const SortedArray& array_to_copy);  // Copy constructor 
	SortedArray(SortedArray&& array_to_move);  // Move constructor 

	void setat(int index, int value);
	unsigned int getat(int index) const;

	// Overloaded Operators
	// Assignment Operator
	const SortedArray& operator= (const SortedArray& right_arr);    // Copy Semantics 
	const SortedArray& operator= (SortedArray&& right_arr);    // Move Semantics 

															  
	bool operator== (const SortedArray& right_arr) const;   // Equality Operator

	// Index Operator
	CustomInt& operator[](int index);
	unsigned int operator[](int index) const;

	~SortedArray();

private:
	int size;
	unsigned int* arr;
	bool* is_valid_element;  // to indicate if a specific index contains a valid entry or not 
	CustomInt* index_arr;  // this will be an array of indices, will be used inside overloading of [] operator 

	void debug_print(std::string operation_name) const;
	void bubbleSort();

	friend std::ostream& operator<<(std::ostream& output, const SortedArray& out_arr);
};

class CustomInt
{
public:
	// inline functions 

	// Integer and Default Constructor 
	CustomInt(int index = 0, SortedArray* arr_obj = nullptr) : my_int(index), my_sorted_arr(arr_obj)
	{
	}

	// Copy Constructor 
	CustomInt(const CustomInt& obj_to_copy)
	{
		my_int = obj_to_copy.my_int;
		my_sorted_arr = obj_to_copy.my_sorted_arr;

	}
	// Move Constructor
	CustomInt(CustomInt&& obj_to_move)
	{
		my_int = obj_to_move.my_int;
		my_sorted_arr = obj_to_move.my_sorted_arr;

		obj_to_move.my_sorted_arr = nullptr;
		obj_to_move.my_int = 0;
	}

	~CustomInt()
	{
	}

	// Overloading the assignment operator to int 
	const CustomInt& operator=(int value)
	{
		my_sorted_arr->setat(my_int, value);
		return *this;
	}

	// Move assignment operator to CustomInt object
	const CustomInt& operator=(CustomInt&& right_obj)
	{
		my_int = right_obj.my_int;
		my_sorted_arr = right_obj.my_sorted_arr;
		return *this;
	}

	// Copy assignment operator to CustomInt object
	const CustomInt& operator=(const CustomInt& right_obj)
	{
		my_int = right_obj.my_int;
		my_sorted_arr = right_obj.my_sorted_arr;
		return *this;
	}

	// Overloading unsigned int type converter 
	operator unsigned int()
	{
		unsigned int temp = my_sorted_arr->getat(my_int);
		return temp;
	}

	friend inline  std::ostream& operator<<(std::ostream& output, const CustomInt& out_element)
	{
		unsigned int temp = out_element.my_sorted_arr->getat(out_element.my_int);
		output << temp;
		return output;
	}



private:
	int my_int;
	SortedArray* my_sorted_arr;
};



#endif // !SORTEDARRAY_H
