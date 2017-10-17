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

class Movie {
	public:
		void setTitle(string set_title);
		string getTitle();
		void setYear(int set_year);
		int getYear();
		void setRating(double set_rating);
		double getRating();
		Movie();
		Movie(string set_title, int set_year, double set_rating);
	private:
		string title;
		int year;
		double rating;
};

void Movie::setTitle(string set_title){
	title = set_title;
}
string Movie::getTitle(){
	return title;
}
void Movie::setYear(int set_year){
	year = set_year;
}
int Movie::getYear(){
	return year;
}
void Movie::setRating(double set_rating){
	rating = set_rating;
}
double Movie::getRating(){
	return rating;
}
Movie::Movie() {
	title = "unknown";
	year = 2016;
	rating = 0.0;
}

Movie::Movie(string set_title, int set_year, double set_rating) {
	title = set_title;
	year = set_year;
	rating = set_rating;
}

int main(int argc, char* argv[]) {
	// Function to test all the functions

	// Write a driver program that creates three movies and tests all methods.

	// Test setting and getting values
	Movie movie1("The Wizard of Oz",1939,9.9);
	cout << movie1.getTitle() << " (" << movie1.getYear() << ") was rated " << movie1.getRating() << endl;

	// Test the default values
	Movie movie2;
	cout << movie2.getTitle() << " (" << movie2.getYear() << ") was rated " << movie2.getRating() << endl;

	// Test setting the values individually
	Movie movie3;
	cout << "changing movie title from " << movie3.getTitle() << " to 'Mad Max: Fury Road'" << endl;
	// movie3.set_title("Mad Max: Fury Road");
	cout << "changing movie year from " << movie3.getYear() << " to '2015'" << endl;
	// movie3.set_year(2015);
	cout << "changing movie rating from " << movie3.getRating() << " to '9.7'" << endl;
	// movie3.set_rating(9.7);
	cout << "Final output: " << movie3.getTitle() << " (" << movie3.getYear() << ") was rated " << movie3.getRating() << endl;

	return 0;
}