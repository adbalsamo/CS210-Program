#include "ItemFrequencyCounter.h"
#include "ItemFrequencyPrinter.h"
#include "ItemHistogram.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

//function to format menu
string nCharString(size_t n, char c) {
	string result;
	for (size_t i = 0; i < n; ++i) {
		result += c;
	}
	return result;
}

void PrintMenu() {
	// print menu options
	string menuLineOne = nCharString(30, '=');
	cout << menuLineOne << endl;
	int spacing = (30 - 12) / 2; //centering "Menu"
	cout << nCharString(spacing, ' ') << "Menu Options" << nCharString(spacing, ' ') << endl;
	cout << nCharString(30, '-') << endl;

	cout << "Option 1: Search For Item" << endl;
	cout << "Option 2: Print Item Frequency" << endl;
	cout << "Option 3: Print Item Frequencey Histogram" << endl;
	cout << "Option 4: Quit" << endl;
	cout << endl;
}
// function to get userInput then call associated function
void GetUserChoice() {
	int userChoice;
	bool validInput = false;
	string result;
	ItemFrequencyCounter itemAmount; //creating itemCounter object
	ItemFrequencyPrinter itemNameAndAmount; //creating itemNameAndAmount object
	ItemHistogram itemHistorgram; //creating itemHistogram object

	while (true) {
		PrintMenu(); // calling PrintMenu function
		if (!(cin >> userChoice)) { // if-statement to make sure user input is a number
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input. Please Enter a Number." << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// if user enters 1, call itemCounter function
			if (userChoice == 1) {
				cout << endl;
				cout << itemAmount.itemCounter() << endl;
				cout << endl;
			}
			// if user enters 2, call itemPrinter function
			else if (userChoice == 2) {
				string dataToWrite = itemNameAndAmount.itemPrinter(true); // passes true as argument to make sure function prints here
			}
			// if user enters 3, call itemHist function
			else if (userChoice == 3) {
				itemHistorgram.itemHist();
			}
			else if (userChoice == 4) {
				cout << "Have a nice day!" << endl; // nice note :-)
				break; // break to end program
			}
			else {
				cout << "Invalid Input. Please Enter a Number 1-4:" << endl;
			}
		}
	}
}

int main() {
	ItemFrequencyPrinter itemNameAndAmount;
	string dataToWrite = itemNameAndAmount.itemPrinter(false); // calling itemPrinter function - parameter is false so function does not print here
	ofstream outFS; // Output file stream
	
	outFS.open("frequency.dat"); // Open file

	// write to file then close
	if (outFS.is_open()) {
		outFS << dataToWrite;
		outFS.close();
	}
	// error message if file does not open correctly
	else if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat." << endl;
		return 1;
	}

	GetUserChoice(); // calling function to print menu to print menu then get user input

	return 0;
}