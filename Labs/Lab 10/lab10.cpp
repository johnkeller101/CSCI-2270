#include <iostream>
#define SIZE 8

using namespace std;

void push(int heap[], int addValue, int &sentinel);
void pop(int heap[], int &sentinel);
void reheap_up(int heap[], int idx);
void reheap_down(int heap[], int sentinel);
void printHeap(int heap[], int sentinel);
void swap(int heap[], int idx_1, int idx_2);


int main(int argc, char const *argv[])
{
	int heap[SIZE] = {};
	int sentinel = 1;

	int array[8] = {5,0,-12,80,36,-4,-12,22222};

	for(int i=0;i<8;i++){
		// cout << "adding " << array[i] << " to heap" << endl;
		push(heap, array[i], sentinel);
		// printHeap(heap,sentinel);
	}
	printHeap(heap,sentinel);
	pop(heap, sentinel);
	printHeap(heap,sentinel);

	for(int i=0;i<8;i++){
		pop(heap,sentinel);
	}
	printHeap(heap,sentinel);

	return 0;
}


void push(int heap[], int addValue, int &sentinel){
	// adds addValue into the heap
	int temp = sentinel;

	if(temp == SIZE){
		cout << "heap is full" << endl;
		return;
	}

	// place addValue in first available leaf of heap
	heap[sentinel] = addValue;

	// reheap
	while(temp > 1 && addValue > heap[temp/2]){
		swap(heap, temp, temp/2);
		temp = temp/2;
	}

	sentinel++;
}

void pop(int heap[], int &sentinel){
	// POP from the TOP
	// replace the top element with whatever is in the rightmost element
	// then we reheap from the top?
	if(sentinel == 1){
		cout << "error nothing in heap" << endl;
		return;
	}

	heap[1] = heap[sentinel - 1];

	sentinel--;
	reheap_down(heap, sentinel);
}

void reheap_up(int heap[], int idx){
	// not used
}

void reheap_down(int heap[], int sentinel){
	int hole = 1;
	int child = hole*2;
	int temp = heap[hole];
	int maxChild;

	while(hole*2 < sentinel){
		// case 1: temp has two children
		if(hole*2 + 1 < sentinel){
			maxChild = heap[hole*2] > heap[hole*2+1] ? hole*2 : hole*2+1;
			if(heap[hole] < maxChild){
				swap(heap, hole, maxChild);
			}
			
		}
		// case 2: temp has left child
		else {
			if(heap[hole] < heap[hole*2]){
				swap(heap, hole, hole*2);
			}
			return;
		}
		hole = maxChild;
	}

}

void printHeap(int heap[], int sentinel){
	int i;
	if(sentinel == 1){
		// nothing is in the array
		cout << "Heap empty, nothing to print" << endl;
		return;
	} 
	for(int i=1; i<sentinel;i++){
		cout << heap[i] << ",";
	}
	cout << endl;
}
// swaps heap[idx_1] with heap[idx_2]
void swap(int heap[], int idx_1, int idx_2){
	int temp = heap[idx_1];
	heap[idx_1] = heap[idx_2];
	heap[idx_2] = temp;
}