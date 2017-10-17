#import <iostream>
using namespace std;

struct Node {
	int key;
	Node *next;
	Node *previous;
};

Node* insertAtEnd(Node*,int);
void printTailToHead(Node*);
void printHeadtoTail(Node*);
Node * Delete(Node*, int);



int main(int argc, char const *argv[]) {
	// Main is going to create a doubly linked list
	// Then insert stuff into the list
	// Then print everything out

	Node* head = NULL;
	Node* tail = NULL;

	printTailToHead(tail);

	tail = insertAtEnd(tail,9);
	tail = insertAtEnd(tail,1);
	tail = insertAtEnd(tail,1);

	printTailToHead(tail);

	tail = Delete(tail, 1);

	printTailToHead(tail);

	return 0;
}

Node * Delete(Node *head, int value){
	Node* temp = head;

	while(temp != NULL){
		if(temp->previous == NULL){
			// this is the head
			if(temp->next->key == value){
				// the next item is the item to be removed

				// now, lets skip the item we want to delete
				temp->next = temp->next->next;
				temp->previous = temp;

			}
		} else {
			// after the head



		}
		temp = temp->next;
	}

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



