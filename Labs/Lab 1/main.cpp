//
//  main.cpp
//  Recitation 2: Files, Array of Struct, & stringstream
//
//  Created by John on 9/7/17.
//  Copyright © 2017 John. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct CarData {
    string model, make, year;
};

int main(int argc, char* argv[]) {
    // Declare ifstream files
    ifstream inFile;
    // Temperary workaround to build outside of the command line
    // Test to see if extra arguments were provided
    if(argc <= 1){
        // no argument found
        inFile.open("cars.txt");
    } else {
        // argument provided, let's open it!
        inFile.open(argv[1]);
    }

    string data;  
    //open the file 
    if(inFile.is_open()) {
        // give feedback that the file was opened sucessfully
        cout << "opened successfully" << endl; 

        CarData carArray[10];
        int i = 0;
        while(getline(inFile, data)){
            // For each line in the file
            stringstream ss(data);
            string carName, carModel, carYear;
            ss >> carName;
            ss >> carModel;
            ss >> carYear;
            // Set elements in array
            carArray[i].make = data.substr(0,data.find(" ",0));
            carArray[i].model = carModel;
            carArray[i].year = carYear;
            // Increase int
            i++;
        }
        //close the file
        inFile.close(); 

        // Read elements in the array and print it back out
        for (int i = 0; i < 10; ++i) {
            cout << "make:" << carArray[i].make << " model:" << carArray[i].model << " year:" << carArray[i].year << endl;
        }


    } else {
        // Catch if file could not be opened
        cout << "File unsuccessfully opened" << endl;
    }
    return 0; 
}