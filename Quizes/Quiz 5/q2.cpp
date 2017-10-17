#import <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
    node *prev;
};
Node* insertAtEnd(Node*,int);
void printTailToHead(Node*);
void printHeadtoTail(Node*);
Node * Delete(Node*, int);
Node * AddAfterIndex(Node *head, int indexIn, int value);



int main(int argc, char const *argv[]) {
	// Main is going to create a doubly linked list
	// Then insert stuff into the list
	// Then print everything out

	Node* head = NULL;
	Node* tail = NULL;

	printTailToHead(tail);

	tail = insertAtEnd(tail,9);
	tail = insertAtEnd(tail,2);
	tail = insertAtEnd(tail,1);

	tail = AddAfterIndex(tail, 4, 2);

	printTailToHead(tail);

	return 0;
}



void ChangeValue(node*& head, int key){
	head->key = key;
	return;
}


node* AddAfterIndex(node *head, int indexIn, int value){

	node* temp = new node;

	int counter = 0;
	// iterate through the linked list
	while(temp->next != NULL){
		if(counter+1 == indexIn){
			// we are adding after this one
			node* toInsert = new node;
			toInsert->prev = temp;
			toInsert->next = temp->next;
			toInsert->value = value;
			temp->next = toInsert;
		}
		// bump it
		counter++;
		temp = temp->next;
	}
	head = temp;

	// head = temp;

	// Node* temp = head;


	// if(head == NULL){

	// 	head->previous = temp;
	// 	temp->next = NULL;
	// 	temp->next = head;
	// 	head = temp;

	// } else if(indexIn == 1){

	// 	temp->previous = NULL;
	// 	temp->next = NULL;
	// 	head = temp;

	// } else {

	// 	Node* temp2 = head;

	// 	// itterare through the list
	// 	for(int i = 0; i<(indexIn - 2);i++){
	// 		temp1 = temp1->next;
	// 	}

	// 	temp->next=temp1->next;
	// 	temp->previous = temp1;
	// 	temp1->next = temp;
	// 	if(temp->next != NULL){
	// 		temp2 = temp->next;
	// 		temp2->previous = temp;
	// 	}

	// }
	// return head;
}

Node * Delete(Node *head, int value){
	return head;
}

Node* insertAtEnd(Node* tail,int value){
	// First case: tail is null

	if(tail == NULL){
		// make a new node
		Node *newNode = new Node;
		// only node in list so no node before or after
		newNode->next = NULL;
		newNode->previous = NULL;
		newNode->key = value;

		tail = newNode;

	} else {
		// make a new node
		Node *newNode = new Node;

		newNode->next = NULL;

		newNode->previous = tail;
		newNode->key = value;
		tail->next = newNode;
		tail = newNode;
	}
	return tail;
	// This is how we are going to keep track of the list

}

void printTailToHead(Node* tail){
	Node* curPtr = tail;

	if(curPtr == NULL){
		// Nothing is in here
		cout << "nothing in the list" << endl;
	} else {
		cout << "NULL";
		while(curPtr != NULL){
			cout << " <-> " << curPtr->key << " <-> ";
			curPtr = curPtr->previous;
		}
		cout << "NULL" << endl;
	}
}


void printHeadtoTail(Node* head){
	
	Node* curPtr = head;

	if(curPtr == NULL){
		// Nothing is in here
		cout << "nothing in the list" << endl;
	} else {
		cout << "NULL";
		while(curPtr != NULL){
			cout << " <-> " << curPtr->key << " <-> ";
			curPtr = curPtr->next;
		}
		cout << "NULL" << endl;
	}
}



