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
	cout << "����� ���������: ";
	cin >> this->engineCapacity;
	cin.ignore();
}

void Motorcycle::setEnginePower() {
	cout << "�������� ���������: ";
	cin >> this->enginePower;
	cin.ignore();
}

void Motorcycle::setTerrainType() {
	cout << "��� ���������: ";
	getline(cin, this->terrainType);
}


string* Motorcycle::getFieltsSet() {
	string* lines = new string[5]{
		string("�����: ") + mark,
		string("������: ") + model,
		string("����� ���������: ") + to_string(engineCapacity),
		string("�������� ���������: ") + to_string(enginePower),
		string("��� ���������: ") + terrainType,
	};

	return lines;
}

string Motorcycle::getData() {

	string result = "���: \033[34m��������\033[0m\n";
	result += "�����: " + mark + string("\n");
	result += "������: " + model + string("\n");
	result += "����� ���������: " + to_string(engineCapacity) + string("\n");
	result += "�������� ���������: " + to_string(enginePower) + string("\n");
	result += "��� ���������: " + terrainType + string("\n");

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