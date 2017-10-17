// Lab 6

#include <iostream>


using namespace std;

struct node {
	int data;
	node* next;
};


class StackLL {
public:
	StackLL();		//constructor
	StackLL(int);	//overloaded constructor
	~StackLL();		//destructor
	void push(int);
	void pop(int&);
	int peek();
	bool isEmpty();
	void printStack();
private:
	node *top;
	int count;
};

StackLL::StackLL(){
	top = NULL;
	count = 0;
}

StackLL::StackLL(int elem){
	count = 1;
	top = new node;
	top->data = elem;
	top->next = NULL;
}

StackLL::~StackLL(){
	while(top!=NULL){
		node* nextPtr = top->next;
		delete top;
		top = nextPtr;
	}
	count = 0;
}

void StackLL::push(int elem){
	node* newNode = new node;
	newNode->data = elem;
	newNode->next = top;
	top = newNode;
	count++;
}

void StackLL::pop(int& returnedElem){
	if(top == NULL){
		cout << "empty stack, nothing to pop" << endl;
	} else {
		returnedElem = top->data;
		node* delNode = top;
		top = top->next;
		delete delNode;
		count--;
	}
}

bool StackLL::isEmpty(){
	return count;
}

int StackLL::peek() {
	if(!isEmpty()) {
		return top->data;
	} else {
		return 1;
	}
}

void StackLL::printStack(){
	if(top==NULL){
		cout << "stack is empty" << endl;
	} else {
		node *currentNode = top;
		while(currentNode != NULL){
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}





class QueueLL {
public:
	QueueLL();		//constructor
	QueueLL(int);	//overloaded constructor
	~QueueLL();		//destructor
	void enqueue(int);
	void dequeue(int&);
	int peek();
	bool isEmpty();
	void printQueue();
private:
	node *top;
	node *bottom;
	int count;
};

QueueLL::QueueLL(){
	top = NULL;
	bottom = NULL;
	count = 0;
}

QueueLL::QueueLL(int elem){
	count = 1;
	top = new node;
	top->data = elem;
	top->next = NULL;
	bottom = top;
}

QueueLL::~QueueLL(){
	while(top!=NULL){
		node* nextPtr = top->next;
		delete top;
		top = nextPtr;
	}
	count = 0;
}

void QueueLL::enqueue(int elem){
	node* newNode = new node;
	newNode->data = elem;
	newNode->next = NULL;
	if(count == 0){
		top = newNode;
		bottom = newNode;
	} else {
		bottom->next = newNode;
		bottom = newNode;
	}
	count++;
}

void QueueLL::dequeue(int& returnedElem){
	if(top == NULL){
		cout << "empty queue, nothing to dequeue" << endl;
	} else {
		returnedElem = top->data;
		node* delNode = top;
		top = top->next;
		delete delNode;
		count--;
		if(count == 0){
			bottom = NULL;
		}
	}
}

bool QueueLL::isEmpty(){
	return count;
}

int QueueLL::peek() {
	if(!isEmpty()) {
		return top->data;
	} else {
		return 1000;
	}
}

void QueueLL::printQueue(){
	if(top==NULL){
		cout << "queue is empty" << endl;
	} else {
		node *currentNode = top;
		while(currentNode != NULL){
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}




int main(int argc, char const *argv[]) {
	StackLL firstStack;
	// firstStack.printStack();
	StackLL secondStack(30);
	secondStack.printStack();
	firstStack.push(50);
	firstStack.push(21);
	firstStack.push(42);
	cout << "on top: " << firstStack.peek() << endl;
	firstStack.printStack();
	int poppedVal;
	firstStack.pop(poppedVal);
	firstStack.printStack();

	return 0;
}