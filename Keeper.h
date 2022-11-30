#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "Base.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"

using namespace std;

class Keeper
{
public:

	void addTransport(Base* transport);

	void removeTransport(int number);

	void save(string fileName);
	
	void load(string fileName);

	Base** getList();

	int getSize();

	friend const bool operator! (Keeper& garage);

private:
	Base** list = {};
	int listSize = 0;
};