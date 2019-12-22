#include "SortedArray.h"

// Integer and default constructor
SortedArray::SortedArray(int size_) : size(size_ > 0 ? size_ : throw INVALID_ARGUMENT), arr(new unsigned int[size]), is_valid_element(new bool [size])
{
	debug_print("SortedArray::SortedArray(int)");
	if (arr == nullptr || is_valid_element == nullptr)
		throw MEMORY_ALLOCATION_FAILURE;

	index_arr = new CustomInt[size];

	if (index_arr == nullptr)
		throw MEMORY_ALLOCATION_FAILURE;


	for (int i = 0; i < size; i++)
	{
		arr[i] = ARRAY_INITIALIZER;  
		index_arr[i] = CustomInt(i, this);
		is_valid_element[i] = false; 
	}


}

// Copy Constructor 
SortedArray::SortedArray(const SortedArray& array_to_copy) : size(array_to_copy.size), arr(new unsigned int[size]), is_valid_element(new bool[size])
{
	debug_print("SortedArray::SortedArray(const SortedArray&)");
	if (arr == nullptr || is_valid_element == nullptr)
		throw MEMORY_ALLOCATION_FAILURE;

	index_arr = new CustomInt[size];
	if (index_arr == nullptr)
		throw MEMORY_ALLOCATION_FAILURE;

	for (int i = 0; i < size; i++)
	{
		arr[i] = array_to_copy.arr[i];
		index_arr[i] = array_to_copy.index_arr[i];
		is_valid_element[i] = array_to_copy.is_valid_element[i]; 
	}
}

// Move Constructor
SortedArray::SortedArray(SortedArray&& array_to_move) : size(array_to_move.size), arr(array_to_move.arr),
index_arr(array_to_move.index_arr), is_valid_element(array_to_move.is_valid_element)
{
	debug_print("SortedArray::SortedArray(SortedArray&&)");
	array_to_move.arr = nullptr;
	array_to_move.index_arr = nullptr;
	array_to_move.is_valid_element = nullptr; 
	array_to_move.size = 0;
}

unsigned int SortedArray::getat(int index) const
{
	debug_print("unsigned int SortedArray::getat(int)");
	// check that the index is within the range of the array or else throw an exception 
	if (index < 0 || index >= size)
		throw INVALID_ARGUMENT;

	if (is_valid_element[index] == false)  // this array entry is empty, thus can't be retrieved 
		throw EMPTY_ENTRY;

	return arr[index];
}

void SortedArray::setat(int index, int value)
{
	debug_print("void SortedArray::setat(int, int)");
	if (value < 0 || value >= INT_MAX)
		throw INVALID_ARGUMENT;

	if (index < 0 || index >= size)
		throw INVALID_ARGUMENT;

	arr[index] = value;
	is_valid_element[index] = true; // the index is set so became valid
	bubbleSort(); // to maintain the property of sorted Array elements 
}

// Overloaded Operators Definitions 

// Assignment Operator Copy Semantics
const SortedArray& SortedArray::operator= (const SortedArray& right_arr)
{
	debug_print("const SortedArray& SortedArray::operator= ((const SortedArray&)");
	// to avoid self-assignment
	if (&right_arr != this)  // check if the passed array is pointing to my current array object
	{
		if (size != right_arr.size)  // free the old memory and allocate new memory with the new proper size 
		{
			delete[] arr; // free the old memory
			delete[] index_arr;
			delete[] is_valid_element; 
			size = right_arr.size;

			// allocate new memories with the new size 
			arr = new unsigned int[size];
			index_arr = new CustomInt[size];
			is_valid_element = new bool[size];

			if (arr == nullptr || index_arr == nullptr)
				throw MEMORY_ALLOCATION_FAILURE;
		}

		for (int i = 0; i < size; i++)
		{
			arr[i] = right_arr.arr[i];
			index_arr[i] = right_arr.index_arr[i];
			is_valid_element[i] = right_arr.is_valid_element[i]; 
		}
	}

	return *this;   // to allow for cascaded assignment 
}

// Assignment Operator Move Semantics
const SortedArray& SortedArray::operator= (SortedArray&& right_arr)
{
	debug_print("const SortedArray& SortedArray::operator= ((SortedArray&&)");
	// to avoid self-assignment
	if (&right_arr != this)  // check if the passed array is pointing to my current array object
	{
		delete[] arr;
		delete[] index_arr;
		delete[] is_valid_element; 

		arr = right_arr.arr;
		index_arr = right_arr.index_arr;
		is_valid_element = right_arr.is_valid_element;
		size = right_arr.size;

		right_arr.arr = nullptr;
		right_arr.index_arr = nullptr;
		right_arr.is_valid_element = nullptr; 
		right_arr.size = 0;
	}

	return *this;   // to allow for cascaded assignment 
}

// Equality Operator
bool SortedArray::operator== (const SortedArray& right_arr) const
{
	debug_print("bool SortedArray::operator== (const SortedArray&)");
	if (size != right_arr.size)   // sizes aren't compatible, so blindly return false 
		return false;

	// in case sizes are compatible , do element-wise check
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != right_arr.arr[i] || is_valid_element[i] != right_arr.is_valid_element[i] )
			return false;
	}

	return true;
}

// Index Operators
CustomInt&  SortedArray::operator[] (int index)   // sets the value of the element 
{
	debug_print("CustomInt&  SortedArray::operator[] (int)");
	if (index < 0 || index >= size)
		throw INVALID_ARGUMENT;

	return index_arr[index];
}

unsigned int SortedArray::operator[](int index) const
{
	debug_print("unsigned int SortedArray::operator[](int) const");
	if (index < 0 || index >= size)
		throw INVALID_ARGUMENT;

	if (is_valid_element[index] == false)  // this array entry is empty, thus can't be retrieved 
		throw EMPTY_ENTRY;

	return arr[index];
}

// Destructor
SortedArray::~SortedArray()
{
	debug_print("SortedArray::~SortedArray()");
	if (arr != nullptr)
		delete[] arr;

	if (index_arr != nullptr)
		delete[] index_arr;

	if (is_valid_element != nullptr)
		delete[] is_valid_element; 
}

// Output stream global function definition
std::ostream& operator<<(std::ostream& output, const SortedArray& out_arr)
{
	for (int i = 0; i < out_arr.size; i++)
	{
		output << std::setw(12) << out_arr.arr[i];
		if ((i + 1) % 4 == 0)   // to have 4 elements per row 
			output << std::endl;
	}
	return output;
}


// Private Functions Definitions
void SortedArray::debug_print(std::string operation_name) const
{
	std::cout << operation_name << "  size==" << size << "  arr==" << arr << std::endl;
}

void SortedArray::bubbleSort()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				unsigned int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				bool temp_flag = is_valid_element[j];
				is_valid_element[j] = is_valid_element[j+1];
				is_valid_element[j+1] = temp_flag;
			}
		
		}
}


