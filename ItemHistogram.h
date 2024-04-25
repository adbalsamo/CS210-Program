#pragma once
#include "ItemFrequencyPrinter.h"
#include <iostream>
#include <fstream>
#include <string>

#ifndef ITEMHISTORGRAM_H
#define ITEMHISTORGRAM_H

class ItemHistogram : public ItemFrequencyPrinter {
public:
	ItemHistogram();
	string itemHist();

private:
	ifstream inFS;
	int itemFreq;
	string item;
	map<string, int> numItems;
};


#endif