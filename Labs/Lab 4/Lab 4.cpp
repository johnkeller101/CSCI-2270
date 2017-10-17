#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool extra_logs = true;

void selectSort(int arr[], int length){
	int index_min_val, temp;

	// Outer loop tracks the sorted portion of the list
	for (int i = 0; i < length-1; i++){
		index_min_val = i;
		for (int j = 0; j < length; j++){
			// The inner section selects the 
			if (arr[j]<arr[index_min_val]){
				index_min_val = j;
			}			
		}
		if (index_min_val != i){
			temp = arr[i];
			arr[i] = arr[index_min_val];
			arr[index_min_val] = temp;
		}
	}
}

void insertion_sort(int arr[], int length){
	int j, temp, step_count = 0;
	// outer loop tracks the sorted portion of the list
	for (int i = 0; i < length; i++) {
		j = i;
		// move elements over until find the position for next element
		while(j>0 && arr[j] < arr[j-1]){
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			
			if (extra_logs){
				cout << step_count+1 << ": ";
				for (int i=0; i<length; i++){
					if(i==0){cout << arr[i];} else {cout << "," << arr[i];}
				}
				cout << endl;
			}
			
			step_count++;
			j--;
		}
	}
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int length){
	int swap_count = 0;
	for (int i = 0; i < length-1; i++){
		for (int j = 0; j < length-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap_count++;
				swap(&arr[j], &arr[j+1]);
				if (extra_logs){
					cout << "swapping " << arr[j] << " for " << arr[j+1] << endl;
				}
			}
		}
	}
	if (extra_logs){
		cout << "swap count = " << swap_count << endl;
	}
	
}

void shellSort(int arr[], int length){
	// reduce gap by half each iteration
	for(int gap = length/2; gap > 0; gap /= 2){
		// Do a gapped insertion sort for this gap size.
		for (int i = gap; i < length; i++){
			int temp = arr[i];
			int j;            
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void printlist(int arr[], int size) {
	for (int i=0; i<size; i++){
		if(i==0){
			cout << arr[i];
		} else {
			cout << "," << arr[i];
		}
		
	}
	cout << endl;
}

int main(int argc, char const *argv[]){
	int test_arr[] = {3, 9, 5, 2, 1, 4, 8, 7};
	insertion_sort(test_arr, 8);
	// printlist(test_arr, 5);

	// int arr[] = {9, 4, 7, 2, 8, 3, 5 };
	// int arr2[] = {9, 4, 7, 2, 8, 3, 5 };
	// int arr3[] = {9, 4, 7, 2, 8, 3, 5 };
	// int arr4[] = {9, 4, 7, 2, 8, 3, 5 };
	// int arr5[] = {9, 4, 7, 2, 8, 3, 5 };
	// selectSort(arr, 7);
	// printlist(arr, 7);
	// insertion_sort(arr2, 7);
	// printlist(arr2, 7);
	// bubbleSort(arr3, 7);
	// printlist(arr3, 7);
	// shellSort(arr4, 7);
	// printlist(arr4, 7);

	// int n = 10000; int rand_arr[n], rand_arr2[n], rand_arr3[n],rand_arr4[n];
	// srand((unsigned)time(NULL));
	// for (int i=0; i<n; i++) {
	// 	rand_arr[i]=rand()%32767;    //make the range of random number between 0 to 32767
	// 	rand_arr2[i] = rand_arr[i];
	// 	rand_arr3[i] = rand_arr[i];
	// 	rand_arr4[i] = rand_arr[i];
	// 	// cout << rand_arr[i] << '\t';
	// }

	// clock_t start, finish;
	// double duration;
	// start = clock();        // start 
	// selectSort(rand_arr,n);
	// finish = clock();       // clock ends
	// duration = (double)(finish-start)/CLOCKS_PER_SEC;
	// cout << "selection sort time:" << endl;
	// cout << duration << " seconds " << endl;

	// start = clock();        // start 
	// insertion_sort(rand_arr2,n);
	// finish = clock();       // clock ends
	// duration = (double)(finish-start)/CLOCKS_PER_SEC;
	// cout << "insertion sort time:" << endl;
	// cout << duration << " seconds " << endl;

	// start = clock();        // start 
	// bubbleSort(rand_arr3,n);
	// finish = clock();       // clock ends
	// duration = (double)(finish-start)/CLOCKS_PER_SEC;
	// cout << "bubble sort time:" << endl;
	// cout << duration << " seconds " << endl;

	// start = clock();        // start 
	// shellSort(rand_arr4,n);
	// finish = clock();       // clock ends
	// duration = (double)(finish-start)/CLOCKS_PER_SEC;
	// cout << "shell sort time:" << endl;
	// cout << duration << " seconds " << endl;

	return 0;
}