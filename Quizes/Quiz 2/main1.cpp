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

void calculateCost(int count, float& subTotal, float& taxCost) {
    if (count < 10) {
        subTotal = count * 0.50;
    } else {
        subTotal = count * 0.20;
    }
    taxCost = 0.1*subTotal;
}


int main(int argc, char const *argv[])
{
    float tax = 0.0, subTotal = 0.0;

    calculateCost(15, subTotal, tax);
    cout << "The cost for 15 items is " << subTotal << ", and the tax for " << subTotal << " is " << tax << endl;
    return 0;
}

// int funcThatDoesSomething(int inputOne, int inputTwo){
//     if (inputTwo > 0)
//     {
//         cout << inputTwo << ",";
//         return (inputOne * funcThatDoesSomething(inputOne, inputTwo - 1));
//     }

//     cout << inputTwo << ";";
//     return 1;
// }

// int main(int argc, char const *argv[])
// {
//     int returnValue = funcThatDoesSomething(4,5);
//     cout << "Returning:" << returnValue;
//     return 0;
// }