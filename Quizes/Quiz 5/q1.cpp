#include <iostream>

using namespace std;

struct Element
{
    int key;
    Element *next;
};

void AddElement(Element** head, int num);

int main(int argc, char const *argv[]){
	Element* head = 4;
	return 0;
}

void AddElement(Element** head, int num){
	Element *temp = new Element;
	temp->key = num;
	temp->next=*head;
	*head = temp;
}