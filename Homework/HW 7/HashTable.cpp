#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


HashTable::HashTable(int newhashTableSize){
	// constructor which creates a hash table to a specified size
	hashTableSize = newhashTableSize;
	hashTable = new wordItem*[hashTableSize];
	numUniqueWords = 0;
	numCollisions = 0;

	// you must go through and set everything as null, in order to prevent the head of the list containing various random details
	for (int i = 0; i < hashTableSize; i++) {
		hashTable[i] = NULL;
	}
}

HashTable::~HashTable(){
	// deconstructor which deletes all items in the hash table
	wordItem* temp = new wordItem;
	wordItem* next = new wordItem;
	for (int i = 0; i < hashTableSize; i++) {
		temp = hashTable[i];
		while(temp != NULL){
			next = temp->next;
			delete temp;
			temp = next;
		}
		hashTable[i] = NULL;
	}
}

void HashTable::getStopWords(char *ignoreWordFileName){
	ifstream iFile;
	iFile.open(ignoreWordFileName);

	if(iFile.is_open()){
		string line;
		while(getline(iFile, line)){
			vecIgnoreWords.push_back(line);
		}
		iFile.close();
	}
}

bool HashTable::isStopWord(std::string word){
	// determines if a word is in the stop word vector
	for (int i = 0; i < STOPWORD_LIST_SIZE; i++){
		if(vecIgnoreWords[i] == word){
			return true;
		}
	}
	return false;
}

bool HashTable::isInTable(std::string word){
	// determines if a word is already in the hashmap
	if(searchTable(word) != NULL){
		return true;
	} else {
		return false;
	}
}

void HashTable::incrementCount(std::string word){
	// searches for particular item in hashmap, then adds one to its count
	wordItem* result = searchTable(word);
	result->count++;
}

void HashTable::addWord(std::string word){
	// create the struct for our new word
	wordItem* wordToAdd = new wordItem;
	wordToAdd->word = word;
	wordToAdd->count = 0;
	wordToAdd->next = 0;

	// determine if hash table already exists
	int tempHashValue = getHash(word);
	if(hashTable[tempHashValue] == NULL){
		// linked list is empty
		hashTable[tempHashValue] = wordToAdd;
		incrementCount(word);
	} else {
		// linked list already has items
		wordToAdd->next = hashTable[tempHashValue];
		hashTable[tempHashValue] = wordToAdd;
		incrementCount(word);
		numCollisions++;
	}
	numUniqueWords++;
}

int HashTable::getTotalNumberNonStopWords(){
	// this function gets the total number of words, then subtracts them if they are stop words
	int finalCount = 0;

	for (int index = 0; index < hashTableSize; index++) {
		wordItem *temp = hashTable[index];
		while (temp != NULL) {
			finalCount = finalCount+temp->count;
			temp = temp->next;
		}
	}
	return finalCount;
}

void HashTable::printTopN(int n){
	// Write a member function named printTopN that takes the value of N
	// as an argument and determines the top N words in the array. Hint: Declare an array of pointers 
	// of size n (static declaration), and use the insertIntoSortedArray algorithm from Assignment 1 
	// to fill this array with words with the largest counts.
	int min = 0;
	int count = 0;
	wordItem *tempArr[n];
	wordItem *temp;
	
	for (int index = 0; index < hashTableSize; index++) {
		temp = hashTable[index];
		while (temp != NULL) {
			if (temp->count > min){
				// define a temp index variable so we can properly iterate without changing the count
				int index = count;
				while (temp->count > tempArr[index - 1]->count && index > 0){
					// move left
					tempArr[index] = tempArr[index - 1];
					// decrease the index by one
					index--;
				}
				if (count >= n){
					count = n;
				} else {
					count++;
				}
				// set the item in tempArr so we can actually print it later
				tempArr[index] = temp;
				// define the min variable
				min = tempArr[count - 1]->count;
			}
			// move onto next item
			temp = temp->next;
		}
	}
	// now to print out all the items from the array
	for (int i = 0; i < n; i++){
		cout <<tempArr[i]->count << " - "<< tempArr[i]->word << endl;
	}
}

int HashTable::getNumUniqueWords(){
	// returns the total number of unique words, which is convinently predefined
	return numUniqueWords;
}

int HashTable::getNumCollisions(){
	// counts all times where the count for a word is greater than one
	return numCollisions;
}

// Private methods

int HashTable::getHash(std::string word){
	int letterSum = 0;
	for (int i = 0; (unsigned)i < word.length(); i++){
		// get ascii value of each letter and add it to letter sum
		letterSum += int(word[i]);
	}
	return letterSum % hashTableSize;
}

wordItem* HashTable::searchTable(std::string word) {
	int wordHashSum = getHash(word);
	bool wordFound = false;
	wordItem* wordToFind = hashTable[wordHashSum];

	if(hashTable[wordHashSum] == NULL){
		delete wordToFind;
		return NULL;
	} else {
		while(!wordFound && wordToFind != NULL){
			if(wordToFind->word != word){
				// move to next item in the list, not found
				wordToFind = wordToFind->next;
			} else {
				wordFound = true;
			}
		}
	}
	return wordToFind;
}

// Main function

int main(int argc, char const *argv[]) {
	// implement code here

	// Your program takes four command-line arguments: the number of most common words to print out, 
	// the name of the text file to process, the stop word list file, and the size of your hash table.

	if (argc != 4) {
		cout << "Usage: ";
		cout << argv[0] << " <most common words> <filename.txt> <ignorefilename.txt> <hash table size>";
		cout << endl;
		// return 0;

		// Let's input some stuff
		argv[1] = (char *)"10";
		argv[2] = (char *)"HW7-HungerGames_edit.txt";
		argv[3] = (char *)"HW7-stopWords.txt";
		argv[4] = (char *)"53";
	}

	HashTable myHashTable = new HashTable(atoi(argv[4]));
	hashTable.getStopWords(argv[3]);

	cout << "#" << endl;
	cout << "Number of collisions: " << myHashTable.getNumCollisions() << endl;
	cout << "#" << endl;
	cout << "Unique non-stop words: " << myHashTable.getNumUniqueWords() << endl;
	cout << "#" << endl;
	cout << "Total non-stop words: " << myHashTable.getTotalNumberNonStopWords() << endl;

	return 0;
}