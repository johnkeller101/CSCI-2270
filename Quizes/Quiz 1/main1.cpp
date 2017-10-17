//
//  main.cpp
//  Homework 1
//
//  Created by John Keller on 9/10/17.
//  Copyright © 2017 John. All rights reserved.
//

#include <iostream>

using namespace std;

int search(int arr[], int size, int searchNum)
{
    int mid;
    mid = arr[size / 2];
    if (mid == searchNum)
    {
        cout << "The value was found in index: " << mid - 1 << endl;
    }
    else 
    {
        for (int i = (size / 2); i > 0; i--) 
        {
            if (arr[i] == searchNum) 
            {
                cout << "The value was found in index: " << i - 1 << endl;
            }
            else 
            {
                return -1;
            }
        }
    }
    return 1;
}

void sort(int arr[], int size) 
{
    int temp, j;
    for (int i = 0; i < size; i++)
    {
        j = i;

        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main() 
{
    int searchNum, input, size;
    char *arr;

    size = 
    arr = new int[size];
    cout << "Please begin entering your array values: " << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> input;
        arr[i] = input;
    }
    sort(arr, size);
    cout << "Please enter a number to search for: " << endl;
    cin >> searchNum;
    search(arr, size, searchNum);
    delete[] arr;
    system("pause");
    return 0;
}