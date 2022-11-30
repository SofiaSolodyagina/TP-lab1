#include "Motorcycle.h"

Motorcycle::Motorcycle() {
	setMark();
	setModel();
	setEngineCapacity();
	setEnginePower();
	setTerrainType();
}

Motorcycle::Motorcycle(string* lines) {
	this->mark = lines[1];
	this->model = lines[2];
	this->engineCapacity = stof(lines[3]);
	this->enginePower = stof(lines[4]);
	this->terrainType = lines[5];
}

void Motorcycle::edit() {
	setMark();
	setModel();
	setEngineCapacity();
	setEnginePower();
	setTerrainType();
}

void Motorcycle::setEngineCapacity() {
	cout << "Объём двигателя: ";
	cin >> this->engineCapacity;
	cin.ignore();
}

void Motorcycle::setEnginePower() {
	cout << "Мощность двигателя: ";
	cin >> this->enginePower;
	cin.ignore();
}

void Motorcycle::setTerrainType() {
	cout << "Тип местности: ";
	getline(cin, this->terrainType);
}


string* Motorcycle::getFieltsSet() {
	string* lines = new string[5]{
		string("Марка: ") + mark,
		string("Модель: ") + model,
		string("Объём двигателя: ") + to_string(engineCapacity),
		string("Мощность двигателя: ") + to_string(enginePower),
		string("Тип местности: ") + terrainType,
	};

	return lines;
}

string Motorcycle::getData() {

	string result = "Тип: \033[34mМотоцикл\033[0m\n";
	result += "Марка: " + mark + string("\n");
	result += "Модель: " + model + string("\n");
	result += "Объём двигателя: " + to_string(engineCapacity) + string("\n");
	result += "Мощность двигателя: " + to_string(enginePower) + string("\n");
	result += "Тип местности: " + terrainType + string("\n");

	return result;
}

string Motorcycle::toFileString() {
	string result = "Motorcycle\n";
	result += mark + string("\n");
	result += model + string("\n");
	result += to_string(engineCapacity) + string("\n");
	result += to_string(enginePower) + string("\n");
	result += terrainType + string("\n");

	return result;
}