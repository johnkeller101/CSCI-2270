
#import <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node *parent;
};


Node* addNode(Node *tree, int value);
int getSize(Node *tree);
int getMinValue(Node *tree);
int getMaxDepth(Node *tree);
Node *makeNewNode(int val);

// new functions
Node *deleteNode(Node *node, int val);

// new helper function that finds a node with a given value
Node *search(Node *node, int val);

// new helper function that finds the max value starting from a given node
int getMaxVal(Node *node);



int main(int argc, char const *argv[]) {
	Node *root = NULL;
	root = makeNewNode(15);
	root = addNode(root,18);
	root = addNode(root,6);
	root = addNode(root,7);
	root = addNode(root,3);
	root = addNode(root,20);
	root = addNode(root,9);
	root = addNode(root,17);

	return 0;
}

Node *makeNewNode(int val){
	// helper function for making a new node
	Node* node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL; // new code
	return node;
}

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
			tree->left->parent = tree; // new code in lab 8
		}
	} else if (value > tree->data){
		if (tree->right != NULL){
			addNode(tree->right, value);
		} else {
			tree->right = makeNewNode(value);
			tree->right->parent = tree; // new code in lab 8
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

int getMaxValue(Node *node){
	if(node != NULL){
		while(node->right != NULL){
			node = node->right;
		}
		return node->data;
	} else {
		return -100;
	}
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

Node *search(Node *node, int key) {
	Node *returnNode = node;
	if(node!=NULL){
		if(key < node->data && node->left != NULL){
			return search(node->left, key);
		} else if (key > node->data && node->right != NULL){
			return search(node->right, key);
		} else if (key == node->data) {
			return node;
		} else {
			cout << "error" << endl;
		}
	}
	return NULL;

	// while(returnNode != NULL){
	// 	if(returnNode->data < val){
	// 		// move onto left child
	// 		returnNode = returnNode->left;
	// 	} else if (returnNode->data > val){
	// 		// move onto right child
	// 		returnNode = returnNode->right;
	// 	} else {
	// 		// it's a match!
	// 		return returnNode;
	// 	}
	// }
	// // no movie found after going through the tree
	// cout << "No item found" << endl;
	// return NULL;
}



Node *deleteNode(Node* node, int val){
	Node *target = search(node,val);
	if(target!=NULL){
		if(target->left != NULL){
			// has at least one left child
			int maxLeft = getMaxValue(target->left);
			Node* maxNodeLeft = search(target->left, maxLeft);
			if(maxNodeLeft->left != NULL){
				// maxNodeLeft has a child
				maxNodeLeft->left->parent = maxNodeLeft->parent;
				if(maxNodeLeft->parent->data > maxNodeLeft->data){
					// maxNodeLeft is a left child
					maxNodeLeft->parent->left = maxNodeLeft->left;
				} else {
					/// maxNodeLeft is a right child
					maxNodeLeft->parent->right = maxNodeLeft->left;
				}
			} else {
				// maxNodeLeft has no children
				if(maxNodeLeft->parent->data > maxNodeLeft->data){
					maxNodeLeft->parent->left = NULL;
				} else {
					maxNodeLeft->parent->right = NULL;
				}
			}
			delete maxNodeLeft;
			target->data = maxLeft;
		} else if(target->right != NULL){
			// target has one child (right child)
			int minRight = getMinValue(target->right);
			Node* minRightNode = search(target->right, minRight);
			if(minRightNode->right != NULL){
				minRightNode->right->parent = minRightNode->parent;
				if(minRightNode->parent->data > minRightNode->data){
					minRightNode->parent->left = minRightNode->right;
				} else {
					minRightNode->parent->right = minRightNode->right;
				}
			} else {
				if(minRightNode->parent->data > minRightNode->data){
					minRightNode->parent->left = NULL;
				} else {
					minRightNode->parent->right = NULL;
				}
			}
			delete minRightNode;
			target->data = minRight;
		} else {
			// target for deletion has NO children
			if(target->parent->data > target->data){
				// target is a left child
				target->parent->left = NULL;
			} else {
				// target is a right child
				target->parent->right = NULL;
			}
			delete target;
		}
		
	} else {
		cout << "item is not in tree" << endl;
	}
	return node;
}
