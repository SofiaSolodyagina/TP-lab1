#include "Car.h"


Car::Car() {
	setMark();
	setModel();
	setEngineCapacity();
	setColor();
	setTransmissionType();
}

Car::Car(string* lines) {
	this->mark = lines[1];
	this->model = lines[2];
	this->engineCapacity = stof(lines[3]);
	this->color = lines[4];
	this->transmissionType = lines[5];
}

void Car::edit() {
	setMark();
	setModel();
	setEngineCapacity();
	setColor();
	setTransmissionType();
}

void Car::setEngineCapacity() {
	cout << "Объём двигателя: ";
	cin >> this->engineCapacity;
	cin.ignore();
}

void Car::setColor() {
	cout << "Цвет: ";
	getline(cin, this->color);
}

void Car::setTransmissionType() {
	cout << "Тип КПП: ";
	cin >> this->transmissionType;
	cin.ignore();
}


string Car::getData() {

	string result = "Тип: \033[31mАвтомомбиль\033[0m\n";
	result += "Марка: " + mark + string("\n");
	result += "Модель: " + model + string("\n");
	result += "Объём двигателя: " + to_string(engineCapacity) + string("\n");
	result += "Цвет: " + color + string("\n");
	result += "Тип трансмисси: " + transmissionType + string("\n");

	return result;
}


string Car::toFileString() {
	string result = "Car\n";
	result += mark + string("\n");
	result += model + string("\n");
	result += to_string(engineCapacity) + string("\n");
	result += color + string("\n");
	result += transmissionType + string("\n");

	return result;
}

