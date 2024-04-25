#include "ItemFrequencyCounter.h"
#include <iostream>
#include <fstream>
#include <string>



using namespace std;
void GetUserChoice();
ItemFrequencyCounter::ItemFrequencyCounter() { // definining constructor
}

string ItemFrequencyCounter::itemCounter() { // creating function
	// opening file with validation
	cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;
	inFS.open("CS210_Project_Three_Input_File.txt");
	cout << endl;

	// error message if file does not open properly
	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
		return "";
	}

	// input for userItem // making sure captilization is correct so user input matches strings from .txt file properly
	cout << "Enter an item:" << endl;
	cin >> userItem;
	userItem[0] = toupper(userItem[0]);
	for (size_t i = 1; i < userItem.length(); ++i) {
		userItem[i] = tolower(userItem[i]);
	}

	itemFreq = 0;

	// Identify when an item matches userItem and increase itemfreq
	bool found = false;

	while (inFS >> currItem) {
		if (currItem == userItem) {
			++itemFreq;
			found = true;
		}
	}

	inFS.close(); // Close file

		if (!found) {
			cout << endl;
			cout << "No item found. Check spelling." << endl;
			cout << "Search items should be pluralized." << endl;
			return "";
		}
		cout << endl;
		return userItem + " " + to_string(itemFreq);
	}


	

