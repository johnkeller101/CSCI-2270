#include <iostream>

using namespace std;

struct Movie { 
	string title;
	int ranking;
	int year;
	Movie* next; 
};

// watch the room

Movie* makeNewMovie(string movieTitle, int movieRank, int movieYear);
int hashSum(string movieTitle, int hashTableSize);
Movie* movieSearch(string movieTitle, Movie* movies[], int hashTableSize);
bool insertMovie(string movieTitle, int movieRank, int movieYear, Movie* movies[], int hashTableSize);

int main(int argc, char const *argv[]) {
	int htSize = 1000000;
	Movie* movieList[htSize];

	// you must go through and set everything as null, in order to prevent the head of the list containing various random details
	for (int i = 0; i < htSize; i++) {
		movieList[i] = NULL;
	}

	string movieNameTest = "whatever.";

	if(insertMovie(movieNameTest,10,2015,movieList,htSize)){
		cout << "object added to movie list" << endl;
	}
	if(insertMovie(movieNameTest,10,2015,movieList,htSize)){
		cout << "object added to movie list" << endl;
	}
	Movie* searchedMovie = movieSearch(movieNameTest,movieList,htSize);
	if(searchedMovie!=NULL){
		cout << "title: " << searchedMovie->title << endl;
		cout << "rank: " << searchedMovie->ranking << endl;
		cout << "year: " << searchedMovie->year << endl;
	}

	// return 0;
}


Movie* makeNewMovie(string movieTitle, int movieRank, int movieYear){
	Movie* movie = new Movie;
	movie->title = movieTitle;
	movie->ranking = movieRank;
	movie->year = movieYear;
	movie->next = NULL;
	return movie;
}

int hashSum(string movieTitle, int hashTableSize){
	int letterSum = 0;
	for (int i = 0; i < movieTitle.length(); i++){
		// get ascii value of each letter and add it to letter sum
		letterSum += int(movieTitle[i]);
	}
	return letterSum % hashTableSize;
}

bool insertMovie(string movieTitle, int movieRank, int movieYear, Movie* movies[], int hashTableSize){
	// we are going to insert everything in alphabetical order

	// get the hashsum
	int movieHashSum = hashSum(movieTitle, hashTableSize);
	if(movies[movieHashSum] == NULL){
		// list is empty
		Movie* movieToAdd = makeNewMovie(movieTitle, movieRank, movieYear);
		movies[movieHashSum] = movieToAdd;
		return true;
	} else {
		// list contains items
		// find where to insert
		Movie* temp = movies[movieHashSum];
		bool inList = false;
		bool movieInserted = false;

		if(temp->title > movieTitle){
			// the new item is going to be inserted to the front of the list
			Movie* movieToAdd = makeNewMovie(movieTitle,movieRank,movieYear);
			movieToAdd->next = temp;
			movies[movieHashSum] = movieToAdd;
			movieInserted = true;
		}
		while(!inList && temp != NULL && !movieInserted){
			// move through the list to determine where to insert the item
			if(temp->title == movieTitle){
				// movie is already in list
				inList = true;
			} else if((temp->next != NULL && temp->title > movieTitle) || temp == NULL){
				// we are going to insert the new node after the current node
				Movie* movieToAdd = makeNewMovie(movieTitle, movieRank, movieYear);
				movieToAdd->next = temp->next;
				temp->next = movieToAdd;
				movieInserted = true;
			} else {
				// move onto next item in list
				temp = temp->next;
			}
		}
		if(inList){
			cout << "item is already in hash table" << endl;
			return false;
		} else if(!movieInserted){
			cout << "error" << endl;
			return false;
		} else {
			// movie inserted
			return true;
		}
	}
}

Movie* movieSearch(string movieTitle, Movie* movies[], int hashTableSize){
	int movieHashSum = hashSum(movieTitle, hashTableSize);
	bool movieFound = false;
	Movie* movieToFind = movies[movieHashSum];
	if(movies[movieHashSum] == NULL){
		delete movieToFind;
		return NULL;
	} else {
		while(!movieFound && movieToFind != NULL){
			if(movieToFind->title != movieTitle){
				// move to next item in list, not found
				movieToFind = movieToFind->next;
			} else {
				movieFound = true;
			}
		}
	}
	return movieToFind;
}