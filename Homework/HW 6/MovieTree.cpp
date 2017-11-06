#include "MovieTree.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


MovieTree::MovieTree() {
	// constructor
	root = NULL;
}

MovieTree::~MovieTree() {
	// deconstructor
	deleteAll(root);
}

void MovieTree::printMovieInventory() {
	printMovieHelper(root);
}

void MovieTree::printMovieHelper(MovieNode *tree){
	// We are using a helper function so we can properly do recursion
	if(tree != NULL){
		if(tree->leftChild != NULL){
			// node has left child
			printMovieHelper(tree->leftChild);
		}
		cout << "Movie: " << tree->title << " " << tree->quantity << endl;
		if(tree->rightChild != NULL){
			// node has right child
			printMovieHelper(tree->rightChild);
		}
	}
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity){
	MovieNode *newNode = new MovieNode(ranking, title, releaseYear, quantity);

	if(root == NULL){
		// No movies exist in the tree
		root = newNode;
		// That's it!
	} else {
		// Movies do exist in the tree
		MovieNode *tempNode = root;

		while(tempNode != NULL){
			// Let's iterate through the tree until we find the correct spot to add the movie
			if(title.compare(tempNode->title) < 0){
				// LEFT CHILD TEST
				if(tempNode->leftChild != NULL){
					// Node has left child, so we need to set that as the new temp
					tempNode = tempNode->leftChild;
				} else {
					// node does not have left child
					tempNode->leftChild = newNode;
					newNode->parent = tempNode;
					tempNode = NULL;
				}
			} else {
				// RIGHT CHILD TEST
				if(tempNode->rightChild != NULL){
					// node has right child
					tempNode = tempNode->rightChild;
				} else {
					// node does not have right child
					tempNode->rightChild = newNode;
					newNode->parent = tempNode;
					tempNode = NULL;
				}
			}
		}
	}
}

void MovieTree::findMovie(std::string title){
	// This method goes through the whole tree in order to find the matching node with title matching the search title
	MovieNode *returnNode = root;
	while(returnNode != NULL){
		if(title.compare(returnNode->title) < 0){
			// move onto left child
			returnNode = returnNode->leftChild;

		} else if (title.compare(returnNode->title) > 0){
			// move onto right child
			returnNode = returnNode->rightChild;
		} else {
			// it's a match!
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << returnNode->ranking << endl; 
			cout << "Title:" << returnNode->title << endl;
			cout << "Year:" << returnNode->year << endl;
			cout << "Quantity:" << returnNode->quantity << endl;
			return;
		}
	}
	// no movie found after going through the tree
	cout << "Movie not found." << endl;
	return;
}

MovieNode* MovieTree::search(MovieNode* node, string title){
	if(node != NULL){
		if(title < node->title && node->leftChild != NULL){
			return search(node->leftChild, title);
		} else if (title > node->title && node->rightChild != NULL){
			return search(node->rightChild, title);
		} else if (title == node->title){
			return node;
		} else {
		}
	}
	return NULL;
}

void MovieTree::rentMovie(std::string title){
	// this item simply removes one from the quantity of a specified movie

	MovieNode *returnNode = search(root,title);
	if(returnNode == NULL){
		// no movie was found
		cout << "Movie not found." << endl;
	} else {
		returnNode->quantity = returnNode->quantity - 1;
		cout << "Movie has been rented." << endl;
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << returnNode->ranking << endl; 
		cout << "Title:" << returnNode->title << endl;
		cout << "Year:" << returnNode->year << endl;
		cout << "Quantity:" << returnNode->quantity << endl;
		if(returnNode->quantity <= 0){
			deleteMovie(returnNode->title);
		}
	}
}

// HELPER FUNCTION TO DELETE MOVIES RECURSIVLY
MovieNode* MovieTree::max(MovieNode* tree){
	if(tree == NULL){
		return NULL;
	}
	while(tree->rightChild != NULL){
		tree = tree->rightChild;
	}
	return tree;
}

MovieNode* MovieTree::min(MovieNode* tree){
	if(tree->leftChild != NULL){
		return min(tree->leftChild);
	} else {
		return tree;
	}
}

void MovieTree::deleteAll(MovieNode* tree){
	if(tree != NULL){
		deleteAll(tree->leftChild);
		deleteAll(tree->rightChild);
		delete tree;
		tree = NULL;
	}
}


void MovieTree::deleteMovie(std::string title){
	MovieNode* target = search(root, title);
	// test if the tree is empty
	if(target == NULL){
		cout << "Movie not found." << endl;
		return;
	}
	// Now, for the actual tests

	if(target->leftChild != NULL){
		// CASE 1: Target has one child
		string maxLeftTitle = max(target->leftChild)->title;
		int maxLeftRanking = max(target->leftChild)->ranking;
		int maxLeftYear = max(target->leftChild)->year;
		int maxLeftQuantity = max(target->leftChild)->quantity;

		MovieNode* maxNodeLeft = max(target->leftChild);

		if(maxNodeLeft->leftChild != NULL){
			// maxNodeLeft has a LEFT child
			maxNodeLeft->leftChild->parent = maxNodeLeft->parent;
			if(maxNodeLeft->parent->title > maxNodeLeft->title){
				// maxNodeLeft is a left child to its parent
				maxNodeLeft->parent->leftChild = maxNodeLeft->leftChild;
			} else {
				// maxNodeLeft is a right child to its parent
				maxNodeLeft->parent->rightChild = maxNodeLeft->leftChild;
			}
		} else {
			// maxNodeLeft has NO child
			if(maxNodeLeft->parent->title > maxNodeLeft->title){
				maxNodeLeft->parent->leftChild = NULL;
			} else {
				maxNodeLeft->parent->rightChild = NULL;
			}
		}
		delete maxNodeLeft;
		target->title = maxLeftTitle;
		target->ranking = maxLeftRanking;
		target->year = maxLeftYear;
		target->quantity = maxLeftQuantity;

	} else if(target->rightChild != NULL){
		// target has a RIGHT child
		string minRightTitle = max(target->rightChild)->title;
		int minRightRanking = max(target->rightChild)->ranking;
		int minRightYear = max(target->rightChild)->year;
		int minRightQuantity = max(target->rightChild)->quantity;


		MovieNode* minRightNode = min(target->rightChild);

		if(minRightNode->rightChild != NULL){
			minRightNode->rightChild->parent = minRightNode->parent;
			if(minRightNode->parent->title > minRightNode->title){
				minRightNode->parent->leftChild = minRightNode->rightChild;
			} else {
				minRightNode->parent->rightChild = minRightNode->rightChild;
			}
		} else {
			if(minRightNode->parent->title > minRightNode->title){
				minRightNode->parent->leftChild = NULL;
			} else {
				minRightNode->parent->rightChild = NULL;
			}
		}
		delete minRightNode;
		target->title = minRightTitle;
		target->ranking = minRightRanking;
		target->year = minRightYear;
		target->quantity = minRightQuantity;
	} else if(target->parent != NULL) {
		// Target for deletion has NO children, but has a parent
		if(target->parent->title > target->title){
			target->parent->leftChild = NULL;
		} else {
			target->parent->rightChild = NULL;
		}
		delete target;
	} else {
		// target for deletion is root
		delete root;
		root = NULL;
	}
}

int count(MovieNode* tree){
	if(tree != NULL){
		return(count(tree->leftChild) + count(tree->rightChild)) + 1;
	} else {
		// tree os empty
		return 0;
	}
}

void MovieTree::countMovies(){
	// counts all movies in the tree
	cout << "Count = " << count(root) << endl;
}


int main(int argc, char const *argv[]) {

	// Main has to load all the stuff from the test file
	// read all movie data line by line, creating a MovieNode for each movie.
	// Insert each node into the Binary Search Tree ordered alphabetically by movie title
		// NOTE: the data should be added to the tree in the order that it is read in

	// First, let's import all the data from the text file

	MovieTree tree;
	ifstream ifile;
	// Movie Information is in a file and the name of the file is passed in as a command-line argument. An example file is on the website HW5-Movies.txt.
	
	// argv[1] = "HW5-Movies.txt";
	// ifile.open(argv[1]);
	// string line;
	// while(getline(ifile,line)){
	// 	// for each line in the text file
	// 	// we need to split up the data by commas
		
	// 	string ranking, title, year, quantity;

	// 	istringstream ss(line);
	// 	string temp;
	// 	int i = 1;
	// 	while(getline(ss,temp,',')){
	// 		if(i==1){
	// 			ranking = temp;
	// 		} else if(i==2){
	// 			title = temp;
	// 		} else if(i==3){
	// 			year = temp;
	// 		} else {
	// 			quantity = temp;
	// 		}
	// 		i++;
	// 	}
	// 	// cout << title << endl;
	// 	tree.addMovieNode(stoi(ranking), title, stoi(year), stoi(quantity));
	// }

	string addMovies[8] = {"Man on Wire","Hands on a Hardbody","Dogtown and Z-Boys","Dancin' Outlaw","Jiro Dreams of Sushi","Enron: The Smartest Guys in the Room", "Bowling for Columbine", "Taxi to the Dark Side"};
	for (int i = 0; i < 8; i++) {
		tree.addMovieNode(2, addMovies[i], 1990, i);
	}
	tree.printMovieInventory();

	string deleteMovies[3] = {"Jiro Dreams of Sushi","Man on Wire","Dancin' Outlaw"};
	for (int i = 0; i < 3; i++){
		cout << "-----------------------------------" << endl;
		cout << "deleting " << deleteMovies[i] << endl;
		tree.deleteMovie(deleteMovies[i]);
		cout << "new inventory: " << endl;
		tree.printMovieInventory();
	}

	// HANDLE INPUTS

	// int input = 0;

	// while(input != 4){
	// 	cout << "======Main Menu======" << endl;
	// 	cout << "1. Find a movie" << endl;
	// 	cout << "2. Rent a movie" << endl;
	// 	cout << "3. Print the inventory" << endl;
	// 	cout << "4. Quit" << endl;

	// 	string inputString;
	// 	getline(cin, inputString);
	// 	input = stoi(inputString);

	// 	if(input == 1){
	// 		// user wants to find a movie
	// 		string movieToFind;
	// 		cout << "Enter title:" << endl;
	// 		getline(cin, movieToFind);
	// 		tree.findMovie(movieToFind);
	// 	} else if(input == 2){
	// 		// user wants to rent a movie
	// 		string movieToRent;
	// 		cout << "Enter title:" << endl;
	// 		getline(cin, movieToRent);
	// 		tree.rentMovie(movieToRent);
	// 	} else if(input == 3){
	// 		// user wants to print the inventory
	// 		tree.printMovieInventory();
	// 	}
	// }
	// cout << "Goodbye!" << endl;
}




