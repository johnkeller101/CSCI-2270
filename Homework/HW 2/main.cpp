// ==========================================
// Created: August 23, 2016 // @author
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// struct to store word + count combinations
struct wordItem {
	string word;
	int count; 
};

/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference) * @return - none
* Note: The number of words is fixed to 50
*/

void getStopWords(char *ignoreWordFileName, vector<string> &_vecIgnoreWords);

/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words * @return - true (if word is a stop word), or false (otherwise)
*/

bool isStopWord(string word, vector<string> &_vecIgnoreWords);

/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/

int getTotalNumberNonStopWords(wordItem list[], int length);

/*
* Function name: arraySort
* Purpose: sort an array of wordItems, increasing, by their count fields * @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/

void arraySort(wordItem list[], int length);

/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems * @param topN - the number of top frequency words to print
* @return none
*/

void printTopN(wordItem wordItemList[], int topN);

void doubleArray(struct wordItem* &array, int count, int array_capacity);


const int STOPWORD_LIST_SIZE = 50; 
const int INITIAL_ARRAY_SIZE = 100;


// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt

int main(int argc, char *argv[]) {
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	// verify we have the correct # of parameters, else throw error msg & return
	if (argc != 4) {
		cout << "Usage: ";
		cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		// return 0;

		// Let's input some stuff
		argv[1] = (char *)"10";
		argv[2] = (char *)"HW2-HungerGames_edit.txt";
		argv[3] = (char *)"HW2-ignoreWords.txt";
	}

	getStopWords(argv[3], vecIgnoreWords);

	int arr_max = 100;
	int arr_count, double_arr_count, total_uncommon = 0;
	int arg_v1 = atoi(argv[1]);


	wordItem* pointer_array = new wordItem[arr_max];

	ifstream iFile;
	iFile.open(argv[2]);
	if(iFile.is_open()){
		cout << argv[2] << " has been opened!" << endl;

		string word;
		while(iFile >> word){
			// Test to see if the word is not loaded
			if (isStopWord(word, vecIgnoreWords) == false) {
				total_uncommon++;
				// Test to see if we need to double the array
				if(arr_max <= arr_count){
					arr_max = arr_max*2;
					doubleArray(pointer_array, arr_count, arr_max);
					double_arr_count++;
				}
				// Now let's add to our array!
				pointer_array[arr_count].word = word;
				pointer_array[arr_count].count++;
			}

		}

		iFile.close();
	} else {
		cout << "file could not be loaded" << endl;
	}

	/* ********************************** 1. Implement your code here.
	Read words from the file passed in on the command line, store and count the words.
	2. Implement the six functions after the main() function separately. ********************************** */
	return 0; 
}

void getStopWords(char *ignoreWordFileName, vector<string> &_vecIgnoreWords) {
	ifstream iFile;
	iFile.open(ignoreWordFileName);

	if(iFile.is_open()){
		string line;
		while(getline(iFile, line)){
			_vecIgnoreWords.push_back(line);
		}
	}

	return;
}

bool isStopWord(string word, vector<string> &_vecIgnoreWords){
	for (int i = 0; i < STOPWORD_LIST_SIZE; i++){
		if(_vecIgnoreWords[i] == word){
			return true;
		}
	}
	return false;
}

int getTotalNumberNonStopWords(wordItem wordItemList[], int numberOfUniqueWords){
	int all_word_count = 0;

	for (int i = 0; i < numberOfUniqueWords; i++){
		int word_count = wordItemList[i].count;
		all_word_count = all_word_count+word_count;
	}

	return all_word_count;
}

void arraySort(wordItem wordItemList[], int length){
	wordItem temp;

	for (int i = 1; i < length; i++){
		for (int j = 0; j < (length - 1); j++){
			if (wordItemList[j+1].count > wordItemList[j].count){
				temp = wordItemList[j];
				wordItemList[j] = wordItemList[j+1];
				wordItemList[j+1] = temp;
			}
		}
	}
	return;
}

void printTopN(wordItem wordItemList[], int n){
	for (int i = 0; i < n; i++){
		cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
	}
	return;
}

void doubleArray(struct wordItem* &array, int count, int array_capacity){
	wordItem* temp = new wordItem[array_capacity];
	// Copy array values to temp array
	for (int i = 0; i < count; i++){
		temp[i] = array[i];
	}
	// Remove  array from memory
	delete [] array;
	// Reassign new array to temp array
	array = temp;
}

