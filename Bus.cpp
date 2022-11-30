#include "Bus.h"

Bus::Bus() {
	setMark();
	setModel();
	setSeats();
	setMaxSeats();
	setEndPoint();
}

Bus::Bus(string* lines) {
	this->mark = lines[1];
	this->model = lines[2];
	this->seats = stoi(lines[3]);
	this->maxSeats = stoi(lines[4]);
	this->endPoint = lines[5];
}

void Bus::edit() {
	setMark();
	setModel();
	setSeats();
	setMaxSeats();
	setEndPoint();
}

void Bus::setSeats() {
	cout << "Количество сидячих пассажирских мест: ";
	cin >> this->seats;
	cin.ignore();
}

void Bus::setMaxSeats() {
	cout << "Общее количество пассажирских мест: ";
	cin >> this->maxSeats;
	cin.ignore();
}

void Bus::setEndPoint() {
	cout << "Конечный пункт: ";
	getline(cin, this->endPoint);
}

string Bus::getData() {
	string result = string("Тип: \033[35mАвтобус\033[0m\n");

	result += "Марка: " + mark + string("\n");
	result += "Модель: " + model + string("\n");
	result += "Количество сидячих мест: " + to_string(seats) + string("\n");
	result += "Макс. количество мест: " + to_string(maxSeats) + string("\n");
	result += "Конченый пункт: " + endPoint + string("\n");

	return result;
}


string Bus::toFileString() {
	string result = "Bus\n";
	result += mark + string("\n");
	result += model + string("\n");
	result += to_string(seats) + string("\n");
	result += to_string(maxSeats) + string("\n");
	result += endPoint + string("\n");

	return result;
}


