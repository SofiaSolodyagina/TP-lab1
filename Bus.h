#pragma once
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

class Bus : public Base
{
public:
	Bus();

	Bus(string* lines);

	void setSeats();
	
	void edit();

	void setMaxSeats();

	void setEndPoint();

	string getData();

	string toFileString();

private:
	int seats;
	int maxSeats;
	string endPoint;
};

