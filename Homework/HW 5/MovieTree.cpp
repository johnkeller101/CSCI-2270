#include <iostream>
#include "MovieTree.hpp"

using namespace std;


MovieTree::MovieTree() {
	// constructor
}

MovieTree::~MovieTree() {
	// deconstructor
}

void MovieTree::printMovieInventory() {

}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity){

}

void MovieTree::findMovie(std::string title){

}

void MovieTree::rentMovie(std::string title){
	// 
}


// PRIVATE
MovieNode* MovieTree::search(MovieNode* node, std::string title){
	// searches for a specific movie with title
}




int main(int argc, char const *argv[]) {

	// Main has to load all the stuff from the test file
	// read all movie data line by line, creating a MovieNode for each movie.
	// Insert each node into the Binary Search Tree ordered alphabetically by movie title
		// NOTE: the data should be added to the tree in the order that it is read in


	

	int menu_input = 0;
	while(menu_input != 4){
		// MENU DISPLAY
		cout << "======Main Menu======" << endl;
		cout << "1. Find a movie" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Print the inventory" << endl;
		cout << "4. Quit" << endl;


		// MENU ORDERING
	}




	return 0;
}