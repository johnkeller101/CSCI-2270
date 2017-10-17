#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
}

void clear(int_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(int_array& arr)
{
//    Switched order of lines
	arr.count = 0;
    delete [] arr.data;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	unsigned int i;
//	Removed the semicolon
	for (i = 0; i < arr.count; ++i)
	{
		if (arr.data[i] == target) return true;
//        Remove return false line
	}
	return false;
}

void resize(int_array& arr)
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	
	arr.data = new_data;
	delete [] arr.data;
	
}

void add(int_array& arr, const int& payload)
{
	
	if ((arr.count == arr.capacity))
		resize(arr);
	
//	Changed the order of ++
	arr.data[arr.count++] = payload;
	
}

bool remove(int_array& arr, const int& target)
{
	unsigned int i = 0; 
	
//	Changed to double equals sign
	if (arr.count == 0)
	
		return false;
		
	while (i < arr.count && arr.data[i] != target)  i++;
	
//	Removed semicolon
	if (i == arr.count)
	
		return false;
//	changed arr.count to arr.count-1
	arr.data[i] = arr.data[arr.count-1];
	
	arr.count--;
	return true;
}

