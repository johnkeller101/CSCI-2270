#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList(){
	stackHead = NULL;
}

TodoStackLinkedList::~TodoStackLinkedList(){
	while(stackHead!=NULL){
		TodoItem* next = stackHead->next;
		delete stackHead;
		stackHead = next;
	}
}

bool TodoStackLinkedList::isEmpty(){
	return stackHead == NULL;
}

void TodoStackLinkedList::push(std::string todoItem){
	TodoItem* temp = new TodoItem;
	temp->todo = todoItem;
	temp->next = stackHead;
	stackHead = temp;
}

void TodoStackLinkedList::pop(){
	if(isEmpty()){
		cout << "Stack empty, cannot pop an item." << endl;
	} else {
		stackHead = stackHead->next;
	}
}

TodoItem* TodoStackLinkedList::peek(){
	if(isEmpty()){
		cout << "Stack empty, cannot peek." << endl;
		return NULL;
	} else {
		return stackHead;
	}
}