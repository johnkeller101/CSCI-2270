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
	// TODO: Delete all the items from memory
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
	MovieNode *returnNode = node;
	while(returnNode != NULL){
		if(title.compare(returnNode->title) < 0){
			// move onto left child
			returnNode = returnNode->leftChild;

		} else if (title.compare(returnNode->title) > 0){
			// move onto right child
			returnNode = returnNode->rightChild;
		} else {
			// it's a match!
			return returnNode;
		}
	}
	// no movie found after going through the tree
	cout << "Movie not found." << endl;
	return NULL;
}

void MovieTree::rentMovie(std::string title){
	// this item simply removes one from the quantity of a specified movie

	MovieNode *returnNode = search(root,title);
	if(returnNode == NULL){
		// no movie was found

		// because it already couts in the findMovie function, we arent going to do it here a second time.
	} else if(returnNode->quantity <= 0){
		cout << "Movie out of stock." << endl;
	} else {
		returnNode->quantity = returnNode->quantity - 1;
		cout << "Movie has been rented." << endl;
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << returnNode->ranking << endl; 
		cout << "Title:" << returnNode->title << endl;
		cout << "Year:" << returnNode->year << endl;
		cout << "Quantity:" << returnNode->quantity << endl;
	}
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
	ifile.open(argv[1]);
	string line;
	while(getline(ifile,line)){
		// for each line in the text file
		// we need to split up the data by commas
		
		string ranking, title, year, quantity;

		istringstream ss(line);
		string temp;
		int i = 1;
		while(getline(ss,temp,',')){
			if(i==1){
				ranking = temp;
			} else if(i==2){
				title = temp;
			} else if(i==3){
				year = temp;
			} else {
				quantity = temp;
			}
			i++;
		}
		// cout << title << endl;
		tree.addMovieNode(stoi(ranking), title, stoi(year), stoi(quantity));
	}

	// HANDLE INPUTS

	int input = 0;

	while(input != 4){
		cout << "======Main Menu======" << endl;
		cout << "1. Find a movie" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Print the inventory" << endl;
		cout << "4. Quit" << endl;

		string inputString;
		getline(cin, inputString);
		input = stoi(inputString);

		if(input == 1){
			// user wants to find a movie
			string movieToFind;
			cout << "Enter title:" << endl;
			getline(cin, movieToFind);
			tree.findMovie(movieToFind);
		} else if(input == 2){
			// user wants to rent a movie
			string movieToRent;
			cout << "Enter title:" << endl;
			getline(cin, movieToRent);
			tree.rentMovie(movieToRent);
		} else if(input == 3){
			// user wants to print the inventory
			tree.printMovieInventory();
		}
	}
	cout << "Goodbye!" << endl;
}




