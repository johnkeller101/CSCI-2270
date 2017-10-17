// ==========================================
// File: Assignment 3 starter code
// Author: Matt Bubernak
// Date: 1/29/2015
// Modified: Fall 2016 E.S.Boese
// Fall 2017 W.Temple
// Description: Linked List Fun
// ==========================================
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string>

using namespace std;

// DO NOT MODIFY THIS STRUCT
struct city {
	string name;
	city *next;
	int numberMessages; // how many messages passed through this city 
	string message; // message we are sending accross
};

/* Function prototypes */
city* addCity(city *head, city *previous, string cityName ); city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string filename); void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);
/* Do NOT modify main function */


int main(int argc, char* argv[]) {
	// pointer to the head of our network of cities
	city *head = NULL;
	head = handleUserInput(head); printPath(head);
	head = deleteEntireNetwork(head); 
	if (head == NULL)
		cout << "Path cleaned" << endl; 
	else
		printPath(head);
	cout << "Goodbye!" << endl;
	return 0; 
}

/*
* Purpose: handle the interaction with the user
* @param head the start of the linked list
* @return the start of the linked list *
* DO NOT MODIFY THIS FUNCTION */

city* handleUserInput(city *head) {
	bool quit = false; 
	string s_input; 
	int input;
	// loop until the user quits
	while (!quit) {
		displayMenu();
		// read in input, assuming a number comes in
		getline(cin, s_input); input = stoi(s_input);
		switch (input) {
		// print all nodes
			case 1: //rebuild network
				head = loadDefaultSetup(head); 
				printPath(head);
				break;
			case 2: // print path 
				printPath(head);
				break;
			case 3: //message is read in from file 
				{
					string cityReceiver;
					cout << "Enter name of the city to receive the message: " << endl;
					getline(cin, cityReceiver);
					cout << "Enter the message to send: " << endl; 
					string message;
					getline(cin, message);
					transmitMsg(head, cityReceiver, message);
				}
					break;
			case 4:
				{
					string newCityName;
					string prevCityName;
					cout << "Enter a new city name: " << endl; 
					getline(cin, newCityName);
					cout << "Enter the previous city name (or First): " << endl; 
					getline(cin, prevCityName);
					// find the node containing prevCity
					city *tmp = NULL; 
					if(prevCityName !="First")
						tmp = searchNetwork(head, prevCityName);
					// add the new node
					head = addCity(head, tmp, newCityName);
					printPath(head);
				}
					break;
			case 5:   // Delete city
				{
					string city;
					cout << "Enter a city name: " << endl; 
					getline(cin, city);
					head = deleteCity(head, city); 
					printPath(head);
				}
					break;
			case 6:  // Delete network
				head = deleteEntireNetwork(head);
				break;
			case 7:  // Quit
				quit = true;
				cout << "Quitting... cleaning up path: " << endl;
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
		}
	}
	return head;
}

/*
Purpose: Add a new city to the network
between the city *previous and the city that follows it in the network.
Prints: `prev: <city name> new: <city name>` when a city is added, prints _nothing_ if the city is being added to the _first_ position in the list.
@param head pointer to start of the list
@param previous name of the city that comes before the new city @param cityName name of the new city
@return pointer to first node in list
*/
city* addCity(city *head, city *previous, string cityName ) {
	if(head == NULL){
		// Case 1: No cities in the linked list

		// make a new node
		city *newCity = new city;
		// only node in list so no node after
		newCity->next = NULL;
		newCity->name = cityName;
		newCity->numberMessages = 0;
		newCity->message = "";
		head = newCity;

	} else if (previous == NULL){
		// Case 2: We are adding the value as the first item in the linked list

		city *newCity = new city;
		newCity->name = cityName;
		newCity->numberMessages = 0;
		newCity->message = "";
		newCity->next = head;
		head = newCity;

		// Print nothing
	} else {
		// Case 3: Cities exist in linked list

		// We need to add a city between *previous and the *previous->next

		// Now that we know what follows, we can setup the newCity to be inserted
		city *newCity = new city;
		newCity->name = cityName;
		newCity->numberMessages = 0;
		newCity->message = "";
		newCity->next = previous->next;

		cout << "prev: " << previous->name << "  new: " << cityName << endl;

		// Now we need to set the previous city to point to the new city
		previous->next = newCity;

		// As described, we need to print the following:
		
	}
	return head;
}

/*
* Purpose: Search the network for the specified city and return a pointer
* to that node
* @param ptr head of the list
* @param cityName name of the city to look for in network
* @return pointer to node of cityName, or NULL if not found
* @see addCity, deleteCity */

// CORRECT

city *searchNetwork(city *ptr, string cityName) {
	if(ptr == NULL){
		//no network exists...
		return NULL;
	} else {
		// We know the pointer exists, so let's iterate through it until we find the correct pointer

		while(ptr != NULL){
			if(ptr->name == cityName){
				// the two are equal, so let's return that pointer
				return ptr;
			}
			ptr = ptr->next;
		}
		// we went through everything and didnt find the city, so return null
		return NULL;
	}
}

/*
* Purpose: deletes all cities in the network starting at the head city.
* @param ptr head of list
* @return NULL as the list is empty 
*/
city* deleteEntireNetwork(city *ptr) {
	city* current_city = ptr;
	city* next_city;

	int delete_count = 0;

	while(current_city != NULL){
		delete_count++;
		cout << "deleting: " << current_city->name << endl;
		next_city = current_city->next;
		free(current_city);
		current_city = next_city;
	}
	ptr = NULL;
	if(delete_count>0){
		cout << "Deleted network" << endl; // return head, which should be NULL
	}
	return ptr;
}

/*
* Purpose: transmit a message from city to city
* @param head pointer to head of the list
* @param receiver the name of the City to receive the message
* @param message the message to transmit
*/
void transmitMsg(city *head, string receiver, string message) {
	// This function takes the message, and passes it through all the cities until it finds the correct one
	// Each city updates the numberMessages variable +1 when a message passes through

	city* sender = head;

	if(head == NULL) {
		cout << "Empty list" << endl;
		return;
	} else {
		while(sender != NULL){
			// itterate though the list of cities
			sender->numberMessages++;
			sender->message = message;

			cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
			if(sender->name == receiver){
				return;
			}
			sender = sender->next;
		}
		return;
	}
}

/*
* Purpose: delete the city in the network with the specified name.
* @param head first node in list
* @param cityName name of the city to delete in the network
* @return head node of list 
*/

city* deleteCity(city *head, string cityName) {
	city* sender = head;
	if(head == NULL) {
		cout << "Empty list" << endl;
		return head;
	} else if(head->name == cityName) {
		head = head->next;
		return head;
	} else {
		while(sender != NULL){
			if(sender->next->name == cityName){
				// We know that the next city is the one we want to remove
				sender->next = sender->next->next;
				return head;
			}
			sender = sender->next;
		}	
		cout << "City does not exist." << endl;
		return head;
	}
}

/*
* Purpose: prints the current list nicely
* @param ptr head of list 
*/

void printPath(city *ptr) {
	cout << "== CURRENT PATH ==" << endl;
	// If the head is NULL
	if (ptr == NULL) {
		cout << "nothing in path" << endl;
	} else {
		while(ptr != NULL){
			cout << ptr->name << " -> ";
			ptr = ptr->next;
		}
		cout << " NULL" << endl;
	}
	cout << "===" << endl; 
}

/*
* Purpose: populates the network with the predetermined cities
* @param head start of list
* @return head of list 
*/

city* loadDefaultSetup(city *head) {
	head = deleteEntireNetwork(head);
	
	head = addCity(head,NULL,"Los Angeles");
	city* prev = head;
	head = addCity(head,prev,"Phoenix");
	prev = head->next;
	head = addCity(head,prev,"Denver");
	prev = head->next->next;
	head = addCity(head,prev,"Dallas");
	prev = head->next->next->next;
	head = addCity(head,prev,"Atlanta");
	prev = head->next->next->next->next;
	head = addCity(head,prev,"New York");
	

    return head;
}


/* Purpose: displays a menu with options 
* DO NOT MODIFY THIS FUNCTION
*/

void displayMenu() {
	cout << "Select a numerical option:" << endl; cout << "======Main Menu=====" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message" << endl; cout << "4. Add City" << endl;
	cout << "5. Delete City" << endl;
	cout << "6. Clear Network" << endl; cout << "7. Quit" << endl;
}

