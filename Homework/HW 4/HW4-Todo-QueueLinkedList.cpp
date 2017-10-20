#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"

using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList(){
	queueFront = NULL;
	queueEnd = NULL;
}

TodoQueueLinkedList::~TodoQueueLinkedList(){
	while(queueFront!=NULL){
		TodoItem* next = queueFront->next;
		delete queueFront;
		queueFront = next;
	}
}

bool TodoQueueLinkedList::isEmpty(){
	return queueFront == NULL;
}

void TodoQueueLinkedList::enqueue(string todoItem){
	TodoItem* temp = new TodoItem;
	temp->todo = todoItem;
	temp->next = NULL;
	if(isEmpty()){
		queueFront = temp;
		queueEnd = temp;
	} else {
		queueEnd->next = temp;
		queueEnd = temp;
	}
}

void TodoQueueLinkedList::dequeue(){
	if(queueFront == NULL){
		cout << "Queue empty, cannot dequeue an item." << endl;
	} else {
		// returnedElem = queueFront->todo;
		TodoItem* delNode = queueFront;
		queueFront = queueFront->next;
		delete delNode;
		if(isEmpty()){
			queueEnd = NULL;
		}
	}
}

TodoItem* TodoQueueLinkedList::peek(){
	// If the stack or queue is empty when you try to pop or peek it, display an error message:
	// Stack empty, cannot peek
	if (isEmpty()){
		cout << "Stack empty, cannot peek" << endl;
		return NULL;
	} else {
		return queueFront;
	}
}