#include <iostream>
#include "HW4-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray(){
	queueFront = -1;
	queueEnd = -1;
}

bool TodoQueueArray::isEmpty(){
	// Returns true if the list has NO items in it
	// Returns false if the list has >0 items in it
	if(queueFront == -1 && queueEnd == -1){
		return true;
	} else {
		return false;
	}
}

bool TodoQueueArray::isFull(){
	if(queueEnd == MAX_QUEUE_SIZE - 1){
		return true;
	} else {
		return false;
	}
}

void TodoQueueArray::enqueue(string todoItem){
	// Adds item to END of array
	
	// first, we need to test and make sure the array is not full
	if(isFull()){
		cout << "Queue full, cannot add new todo item." << endl;
		return;
	}

	// now, we need to test if the array is empty
	if(isEmpty()){
		queueEnd = 0;
		queueFront = 0;
	} else {
		queueEnd++;
	}

	TodoItem* temp = new TodoItem;
	temp->todo = todoItem;
	queue[queueEnd] = temp;
}

void TodoQueueArray::dequeue(){
	// Removes item from FRONT of array
	if(isEmpty()){
		cout << "Queue empty, cannot dequeue an item." << endl;
	} else if(queueFront == queueEnd){
		// only one element in the array, so removing it would make the array empty
		queueFront = -1;
		queueEnd = -1;
	} else {
		// now we need to shift all elements in the array back by one
		for(int i=1; i<=queueEnd; i++){
			queue[i-1] = queue[i];
			if(i == queueEnd){
				TodoItem* temp = new TodoItem;
				queue[i] = temp;
			}
		}
		queueEnd--;
	}
}

TodoItem* TodoQueueArray::peek(){
	// If the stack or queue is empty when you try to pop or peek it, display an error message:
	// Stack empty, cannot peek
	if (isEmpty()){
		cout << "Queue empty, cannot peek" << endl;
		return NULL;
	} else {
		return queue[queueFront];
	}
}



// BELOW IS TEST STUFF, DO NOT SUBMIT TO MOODLE


void TodoQueueArray::printQueue(){
	for(int i=queueFront; i<=queueEnd;i++){
		cout << i << ": " << queue[i]->todo << endl;
		// if(i != queueEnd){ cout << ", ";}
	} 
	cout << endl;
}


int main(int argc, char const *argv[])
{
	TodoQueueArray* test = new TodoQueueArray;

	test->enqueue("100");
	test->enqueue("2");
	test->enqueue("4");
	test->enqueue("7");
	test->dequeue();
	test->enqueue("31");

	test->printQueue();
	return 0;
}