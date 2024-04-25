#include "ItemHistogram.h"
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

ItemHistogram::ItemHistogram() {
}

string ItemHistogram::itemHist() {

	cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;
	inFS.open("CS210_Project_Three_Input_File.txt");
	cout << endl;

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
		return "";
	}
	//Read and print each item from the file
	while (getline(inFS, item)) {
		if (numItems.count(item)) {
			numItems[item]++;
		}
		else {
			numItems.emplace(item, 1);
		}
	}
	for (auto groceries : numItems) {
		cout << right << setw(11) << groceries.first << " "; // aligns output to look cleaner and is better visual as graph
		for (int i = 0; i < groceries.second; ++i) {
			cout << "*"; // for loop to print '*' times number (numItems)
		}
		cout << endl;
	}

	inFS.close(); //close file


	return item;
}
