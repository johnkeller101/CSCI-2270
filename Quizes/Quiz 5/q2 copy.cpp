#import <iostream>
using namespace std;

struct node
{
    int key;
    node *next;
    node *prev;
};

node * Delete(int value, node *head);


node * Delete(int value, node *head){
	// we need to iterate through the list until we find the correct key value...

	while(head != NULL){
		if(head->key == value){
			node *del_node = head;
			head->next = head->prev;
			head = head->next;
			delete del_node;
		}
		head = head->next;
	}
	return head;
}