#pragma once
#include <iostream>
#include <fstream>
#include <string>
#ifndef ITEMFREQUENCEYCOUNTER_H
#define ITEMFREQUENCEYCOUNTER_H
using namespace std;


class ItemFrequencyCounter {
public:
	ItemFrequencyCounter(); //declare constructor
	string itemCounter();
	

private:
	ifstream inFS; //Input file stream
	string userItem;
	int itemFreq;
	string currItem;
	
	

};

#endif