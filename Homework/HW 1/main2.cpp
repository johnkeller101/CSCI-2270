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
#include <string>
#include <vector>
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

// 2. Read in a .csv data file where each line is structured as such: "username,gpa,age". Store these values into a struct with username, gpa, and age (string, float, int) and create a list as a vector of these structs. As you read in each line from the file, parse each value using stringstream and convert to the appropriate data type. Then call the addUser function to create the struct and add it to the vector. Then call the printList function to loop through and print out the list formatted as: "username [gpa] age: #" e.g., "elle [3.87] age: 12" .
//     a. Use the following struct declaration:
//         struct list {
//             string username; 
//             float gpa;
//             int age;
//         };
//     b. Use the following function signatures:
//         void addUser(vector<list> *gradeList, string name, float _gpa, int _age)
//         void printList(const vector<list> gradeList)
//     c. Use getline, stringstream, stoi, stof.
//     d. Be sure to close your file when you are done.

// // PROBLEM 2


struct list {
    string username; 
    float gpa;
    int age;
};

void addUser(vector<list> *gradeList, string name, float _gpa, int _age){
    // cout << name << ", " << _gpa << ", " << _age << endl;

    list temp;
    temp.username = name;
    temp.gpa = _gpa;
    temp.age = _age;

    gradeList->push_back(temp);

}

void printList(const vector<list> gradeList){
    for (int i = 0; i < gradeList.size(); i++) {
        list temp = gradeList[i];
        cout << temp.username << " [" << temp.gpa << "] age: " << temp.age << endl;
    }
}


int main(int argc, char* argv[]) {
    // Declare file ifstream
    ifstream file;

    // Test to determine if filename is provided via command-line-args
    if(argc <= 1){
        // no argument found, default to dat.txt
        cout << "no command line arguments found, defaulting to gpa.csv" << endl;
        argv[1] = (char *)"gpa.csv";
    }

    // Open the file
    file.open(argv[1]);  

    // Declare vector with data
    vector<list> *dataList;


    // test if file opened sucessfully
    if(file.is_open()) {
        // print the name of the text file
        cout << argv[1] << endl; 

        // Declare variables
        string data;
        int i = 0;

        // Get values for each line of data
        while(getline(file, data)) {
            char delim = ',';

            string username = data.substr(0,data.find(delim));

            string gpa_str = data.replace(0,data.find(delim)+1,"");
            gpa_str = gpa_str.substr(0,gpa_str.find(delim));
            float gpa = stof(gpa_str);

            string age_str = data.replace(0,data.find(delim)+1,"");
            age_str = age_str.substr(0,age_str.find(delim));
            int age = stoi(age_str);

            addUser(dataList, username, gpa, age);
            // Irease counter int
            i++;
        }

        cout << i << " entries read" << endl;

        //close the file
        file.close(); 


    } else {
        // Catch if file could not be opened
        cout << "Error: File unsuccessfully opened" << endl;
    }
    return 0; 
}

