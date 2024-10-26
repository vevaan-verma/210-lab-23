// COMSC-210 | Lab 23 | Vevaan Verma
using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include "Goat.h"

/* FUNCTION PROTOTYPES */
int select_goat(list<Goat> trip);
void add_goat(list<Goat>& trip, string[], string[]);
void delete_goat(list<Goat>& trip);
void display_trip(list<Goat> trip);
int main_menu();
int getValidatedChoice(int min, int max);

/* CONSTANTS */
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// main() is the entry point of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0));

	// read & populate arrays for names and colors
	ifstream fin("names.txt");
	string names[SZ_NAMES];

	int i = 0;

	while (fin >> names[i++]);

	fin.close();

	ifstream fin1("colors.txt");
	string colors[SZ_COLORS];

	i = 0;

	while (fin1 >> colors[i++]);

	fin1.close();

	return 0;

}

// main_menu() displays the main menu and gets the user's choice
// arguments: none
// returns: int - the user's choice
int main_menu() {

	// output main menu
	cout << "*** GOAT MANAGER 3001 ***\n"
		<< "[1] Add a goat\n"
		<< "[2] Delete a goat\n"
		<< "[3] List goats\n"
		<< "[4] Quit\n"
		<< "Choice --> ";

	return getValidatedChoice(1, 4);

}

// select_goat() displays the goats in the trip and gets the user's choice
// arguments: list<Goat> trip - the list of goats
// returns: int - the user's choice
int select_goat(list<Goat> trip) {

	int count = 1;

	for (list<Goat>::iterator iterator = trip.begin(); iterator != trip.end(); iterator++) { // iterate through the list of goats

		cout << "[" << count << "] " << (*iterator).get_name() << " (" << (*iterator).get_age() << ", " << (*iterator).get_color() << ")" << endl; // output the goat's name, age, and color
		count++; // increment the count

	}

	cout << "Select a goat: "; // prompt the user to select a goat
	return getValidatedChoice(1, trip.size()) - 1; // return the user's choice (validated to be between 1 and the size of the list) minus 1 (to get the index of the goat in the list)

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}