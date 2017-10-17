#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* insertAtBeginning(Node* head, int value);
void printHeadtoTail(Node* head);


int main(int argc, char const *argv[])
{
    Node* head = NULL;

    printHeadtoTail(head);
    head = insertAtBeginning(head,9);
    printHeadtoTail(head);
    head = insertAtBeginning(head,10);
    printHeadtoTail(head);
    head = insertAtBeginning(head,11);
    printHeadtoTail(head);

    return 0;
}



Node* insertAtBeginning(Node* head, int value){
    // Set contents of newNode
    Node *newNode = new Node;
    newNode->data = value;

    // First case: list has no contents
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    // Return the head so we can keep track of the list
    return head;
}


void printHeadtoTail(Node* head){
    
    Node* curPtr = head;

    if(curPtr == NULL){
        // Nothing is in here
        cout << "nothing in the list" << endl;
    } else {
        cout << "NULL";
        while(curPtr != NULL){
            cout << " <-> " << curPtr->data << " <-> ";
            curPtr = curPtr->next;
        }
        cout << "NULL" << endl;
    }
}