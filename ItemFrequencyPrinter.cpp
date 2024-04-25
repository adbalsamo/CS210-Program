#include "ItemFrequencyPrinter.h"
//#include <iostream>
#include <fstream>
#include <string>


using namespace std;

ItemFrequencyPrinter::ItemFrequencyPrinter() {
}

string ItemFrequencyPrinter::itemPrinter(bool printOutput) { // bool argument to make sure function does not print with file output, but does otherwise
	if (printOutput) {
		cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;
		cout << endl;
	}
	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
		cout << endl;
		return "";
	}
	// Read and print each item from the file
	while (getline(inFS, item)) {
		if (numItems.count(item)) {
			numItems[item]++;
		}
		else {
			numItems.emplace(item, 1);
		}
	}
	inFS.close(); // close file

	string dataToReturn;

		for (const auto& groceries : numItems) { // loop that iterates through map
			// dataToReturn is used so this data can be returned when function is called and printing is needed
			dataToReturn += groceries.first + " " + to_string(groceries.second) + "\n"; // collects item and amount from list and concatenates them
		}
		if (printOutput) { // prints when argument is "true" when calling function - does not print if "false"
			for (const auto& groceries : numItems) {
				cout << groceries.first << " " << groceries.second << endl;
			}
		}

	return dataToReturn;
}
