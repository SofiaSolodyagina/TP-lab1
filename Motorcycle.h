#pragma once
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

class Motorcycle : public Base
{
public:

	Motorcycle();

	Motorcycle(string* lines);

	void edit();

	void setEngineCapacity();

	void setEnginePower();

	void setTerrainType();

	string* getFieltsSet();

	string getData();

	string toFileString();

private:
	float engineCapacity;
	float enginePower;
	string terrainType;
};

