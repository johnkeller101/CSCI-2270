// ==========================================
// Created: August 23, 2016 // @author
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


void insertion_sort (int arr[], int length);

int main(int argc, char const *argv[])
{
	int test[5] = {7,1,6,4,3};

	insertion_sort(test, 5);

	return 0;
}

void insertion_sort (int arr[], int length){
	 int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		cout << arr[i] << endl;

		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
		}

		cout << arr[j];
	}
}