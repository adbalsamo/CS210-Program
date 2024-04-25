#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#ifndef ITEMFREQUENCEYPRINTER_H
#define ITEMFREQUENCEYPRINTER_H
using namespace std;

class ItemFrequencyPrinter {
public:
	ItemFrequencyPrinter();
	string itemPrinter(bool printOutput);


private:
	ifstream inFS;
	int itemFreq;
	string item;
	map<string, int> numItems;
};

#endif