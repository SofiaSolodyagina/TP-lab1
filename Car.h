#pragma once
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

class Car : public Base
{
public:
	
	Car();

	Car(string* lines);

	void edit();

	void setEngineCapacity();

	void setColor();

	void setTransmissionType();

	string getData();
	
	string toFileString();


private:
	float engineCapacity;
	string color;
	string transmissionType;
};

