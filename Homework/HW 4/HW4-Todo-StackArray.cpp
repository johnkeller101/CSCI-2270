#include <iostream>
#include "HW4-Todo-StackArray.hpp"

using namespace std;

TodoStackArray::TodoStackArray(){
	stackTop = -1;
}

bool TodoStackArray::isEmpty(){
	if(stackTop == -1){
		return true;
	} else {
		return false;
	}
}

bool TodoStackArray::isFull(){
	if(stackTop == MAX_STACK_SIZE - 1){
		return true;
	} else {
		return false;
	}
}

void TodoStackArray::push(std::string todoItem){
	// Add item to the end of the array...
	if(stackTop == MAX_STACK_SIZE-1){
		// array is full, so we cannot add another item
		cout << "Stack full, cannot add new todo item." << endl;
		return;
	} else {
		// let's add items to the array of TodoItems
		TodoItem* temp = new TodoItem;
		temp->todo = todoItem;
		stack[stackTop+1] = temp;
		// cout << "added '" << todoItem << "' to array" << endl;
		stackTop++;
	}
	// stack[stackTop++] = todoItem;
}

void TodoStackArray::pop(){
	if(stackTop < 0){
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	} else {
		// create new array to replace stack[]

		stack[stackTop-1] = NULL;

		// lower number of items in array
		stackTop--;
	}
}

TodoItem* TodoStackArray::peek(){
	if(!isEmpty()){
		return stack[stackTop];
	} else {
		cout << "Stack empty, cannot peek." << endl;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	TodoStackArray *test = new TodoStackArray;
	test->push("todo number one");
	test->push("todo number two");
	cout << test->peek() << endl;
	test->pop();
	cout << test->peek() << endl;
	return 0;
}