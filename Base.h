#pragma once

#include <string>
#include <iostream>

using namespace std;

class Base
{
public: 

	virtual string getData() = 0;
	virtual string toFileString() = 0;

	virtual void edit() = 0;

	void setMark();

	void setModel();

protected:
	string mark;
	string model;
private:

};

