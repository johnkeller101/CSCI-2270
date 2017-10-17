//
//  main.cpp
//  Homework 1
//
//  Created by John Keller on 9/10/17.
//  Copyright © 2017 John. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Objectives
// - Read in command-line-args
// - Read a file
// - Loop through an array
// - Split a string
// - Create an array of struct
// - Pass by reference
// - Create a class with constructors/getters/setters
// - Create header files with header guards

// Problem Set
// 1. Read in a data file (the filename comes in via command-line arguments) with numbers on each line in the file and store these values into a sorted array. Create the array of size 100 and use an array sentinel to keep track of the actual number of entries (will not exceed 100). As you read each value in, place it into the correct position in the sorted array. Then prompt the user for a number, and report back to the user if it is in the list and if so, what position in the list.
//     a. Use getline to read in each line from the file.
//     b. Print out the name of the file you read in from command-line args.
//     c. Create a function named insertIntoSortedArray that takes the array, number of entries currently in the array, and new value to be inserted as parameters. Inside the function insert the new value into the correct position in the sorted array. Use the following signature:
//         int insertIntoSortedArray(int myArray[ ], int numEntries, int newValue)
//     d. Print out the entire array each time after calling insertIntoSortedArray, displaying the values as a comma separated list.
//     e. Print out the total number of entries in the array after reading in the file

//         Example: Given a data file named dat.txt with the following values:
//             9
//             3
//             6
//         The output would be:
//             dat.txt
//             9
//             3,9
//             3,6,9
//             3

// 2. Read in a .csv data file where each line is structured as such: "username,gpa,age". Store these values into a struct with username, gpa, and age (string, float, int) and create a list as a vector of these structs. As you read in each line from the file, parse each value using stringstream and convert to the appropriate data type. Then call the addUser function to create the struct and add it to the vector. Then call the printList function to loop through and print out the list formatted as: "username [gpa] age: #" e.g., "elle [3.87] age: 12" .
//     a. Use the following struct declaration:
//         struct list {
//             string username; float gpa;
//             int age;
//         };
//     b. Use the following function signatures:
//         void addUser(vector<list> *gradeList, string name, float _gpa, int _age)
//         void printList(const vector<list> gradeList)
//     c. Use getline, stringstream, stoi, stof.
//     d. Be sure to close your file when you are done.

// 3. Create a class named Movie that maintains information about the title (string), year (int), and rating (double). Create all accessors and mutators, and overload the constructor with a default constructor and one that takes all 3 values (title, year, rating). Make the default constructor initialize with the following default values: "unknown", 2016, 0.0. Write a driver program that creates three movies and tests all methods.

// // PROBLEM 1

int insertIntoSortedArray(int myArray[], int numEntries, int newValue) {
    // cout << "number of entries in array: " << numEntries;

    myArray[numEntries] = newValue;

    // Sorting method without using sort()
    for (int i = 0; i < numEntries; i++){
        for (int j = i+1; j <= numEntries; j++){
            if (myArray[j] < myArray[i]){
                int temp_val = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = temp_val;
            }
        }
    }

    return numEntries+1;
}

int main(int argc, char* argv[]) {
    // Declare file ifstream
    ifstream file;

    // Test to determine if filename is provided via command-line-args
    if(argc <= 1){
        // no argument found, default to dat.txt
        cout << "no command line arguments found, defaulting to dat.txt" << endl;
        argv[1] = (char *)"dat.txt";
    }

    // Open the file
    file.open(argv[1]);  

    // test if file opened sucessfully
    if(file.is_open()) {
        // print the name of the text file
        cout << argv[1] << endl; 

        // Declare variables
        int sortedArray[100];
        string data;
        int i = 0;

        // Get values for each line of data
        while(getline(file, data)) {
            // setup stringstream
            stringstream ss(data);
            // declare value string
            int numberValue;
            // set value string to line contents
            ss >> numberValue;

            insertIntoSortedArray(sortedArray, i, numberValue);

            // Irease int
            i++;

            // Loop to print out all items in the array properly
            for (int l = 0; l < i; l++){
                cout << sortedArray[l];
                // If statement to properly format csv
                if(i-l!=1){
                    cout << ",";
                }
            }
            cout << endl;
        }

        // print total number of entries
        cout << i << endl;

        //close the file
        file.close(); 


    } else {
        // Catch if file could not be opened
        cout << "Error: File unsuccessfully opened" << endl;
    }
    return 0; 
}

