#ifndef MOVIETREE_HPP 
#define MOVIETREE_HPP

#include <string>

struct MovieNode {

	int ranking;
	std::string title;
	int year;
	int quantity;
	MovieNode *parent;
	MovieNode *leftChild;
	MovieNode *rightChild;

	MovieNode() {}

	// Creates a head node, which contains the correct content but does not have a parent or any children
	MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity){
		ranking = in_ranking;
		title = in_title;
		year = in_year;
		quantity = in_quantity;

		parent = nullptr;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

class MovieTree {
public:
	MovieTree();
	~MovieTree();
	void printMovieInventory();
	void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
	void findMovie(std::string title);
	void rentMovie(std::string title);
private:
	MovieNode* search(MovieNode* node, std::string title);
	MovieNode* root;
};

#endif