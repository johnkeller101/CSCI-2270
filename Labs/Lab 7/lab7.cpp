#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* addNode(Node *tree, int value);
int getSize(Node *tree);
int getMinValue(Node *tree);
int getMaxDepth(Node *tree);
Node *makeNewNode(int val);

Node* addNode(Node *tree, int value){
	// Adds a node to the tree in the appropriate place
	if(tree == NULL){
		Node *newNode = makeNewNode(value);
		return newNode;
	} else if (value < tree->data) {
		if(tree->left != NULL){
			addNode(tree->left, value);
		} else {
			tree->left = makeNewNode(value);
		}
	} else if (value > tree->data){
		if (tree->right != NULL){
			addNode(tree->right, value);
		} else {
			tree->right = makeNewNode(value);
		}
	} else {
		cout << "node with value " << value << " is already in the tree" << endl;
	}
	return tree;
}

int getSize(Node *tree){
	// Returns the total number of nodes
	int size = 0;
	if(tree!=NULL){
		size++;
		size+=getSize(tree->left);
		size+=getSize(tree->right);
	}
	return size;
}

int getMinValue(Node *tree){
	// Returns the smallest value in the tree
	if(tree->left != NULL){
		return getMinValue(tree->left);
	} else {
		return tree->data;
	}
}

int getMaxDepth(Node *tree){
	// returns the longest branch
	int leftDepth = 0;
	int rightDepth = 0;

	if(tree == NULL){
		return 0;
	} else {
		leftDepth = getMaxDepth(tree->left);
		rightDepth = getMaxDepth(tree->right);
		if(leftDepth > rightDepth){
			return leftDepth + 1;
		} else {
			return rightDepth + 1;
		}
	}
}

Node *makeNewNode(int val){
	// helper function for making a new node
	Node* node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main(int argc, char const *argv[]){
	Node *root = NULL;
	root = makeNewNode(8);
	// root = addNode(3);

	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth of tree: " << getMaxDepth(root) << endl;
	cout << "current min of tree: " << getMinValue(root) << endl;

	root = addNode(root, 19);

	
	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth of tree: " << getMaxDepth(root) << endl;
	cout << "current min of tree: " << getMinValue(root) << endl;

	return 0;
}