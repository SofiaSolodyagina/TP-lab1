#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <filesystem>

#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"

using namespace std;

namespace fs = std::filesystem;

Keeper garage;

bool check() {
	if (!garage) return true; 

	cout << "\033[34mГараж пуст!\033[0m" << endl;
	cout << endl << "\033[35mНажмите любую клавишу чтобы вернуться в меню\033[0m" << endl;
	cin.get();
		
	return false;
}

void show() {
	if (!check()) return;

	for (int i = 0; i < garage.getSize(); i++) {
		cout << garage.getList()[i]->getData() << endl;
	}

	cout << endl << "\033[35mНажмите любую клавишу чтобы вернуться в меню\033[0m" << endl;

	cin.get();
}

void add() {

	cout << "1. Автомобиль" << endl;
	cout << "2. Мотоцикл" << endl;
	cout << "3. Автобус" << endl;

	int command;

	cout << "\033[35mТип: \033[0m";
	cin >> command;
	cin.get();

	system("@cls||clear");

	switch (command)
	{
	case 1:
		garage.addTransport(new Car());
		break;
	case 2:
		garage.addTransport(new Motorcycle());
		break;
	case 3:
		garage.addTransport(new Bus());
		break;
	default:
		return;
		break;
	}
}

void edit() {
	if (!check()) return;

	for (int i = 0; i < garage.getSize(); i++) {
		cout << "=== Номер #" << (i + 1) << " ===" << endl;
		cout << garage.getList()[i]->getData() << endl;
		cout << "=================" << endl << endl;
	}

	int number;

	cout << "\033[35mНомер: \033[0m";
	cin >> number;
	cin.get();

	number--;

	if (number < 0 || number >= garage.getSize()) return;

	system("@cls||clear");

	garage.getList()[number]->edit();
}

void remove() {
	if (!check()) return;

	for (int i = 0; i < garage.getSize(); i++) {
		cout << "=== Номер #" << (i + 1) << " ===" << endl;
		cout << garage.getList()[i]->getData() << endl;
		cout << "=================" << endl << endl;
	}

	int number;

	cout << "\033[35mНомер: \033[0m";
	cin >> number;
	cin.get();

	number--;

	if (number < 0 || number >= garage.getSize()) return;

	garage.removeTransport(number);
}

void load() {
	string ext(".garage");
	
	int i = 0;
	auto iterator = fs::recursive_directory_iterator("./");

	for (auto& p : iterator)
	{
		if (p.path().extension() == ext)
			std::cout << (++i) << ". " << p.path().filename().string() << endl;
	}

	int number;

	cout << "\033[35mНомер: \033[0m";
	cin >> number;
	cin.get();
	system("@cls||clear");

	i = 0;
	iterator = fs::recursive_directory_iterator("./");

	for (auto& p : iterator)
	{
		if (p.path().extension() == ext) {
			i++;

			if (i == number) {
				garage.load(p.path().filename().string());
			}
		}
	}
}

void save() {
	string name;
	cout << "\033[35mНазвание сохранения: \033[0m";
	cin >> name;
	cin.get();
	system("@cls||clear");

	garage.save(name + ".garage");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int command;

	while (true) {
		system("@cls||clear");

		cout << "1. Список транспорта в гараже" << endl;
		cout << "2. Добавить транспорт" << endl;
		cout << "3. Редактировать транспорт" << endl;
		cout << "4. Удалить транспорт" << endl;
		cout << "5. \033[33mСохранить\033[0m" << endl;
		cout << "6. \033[32mЗагрузить\033[0m" << endl;
		cout << "0. \033[31mВыход\033[0m" << endl;

		cout << "\033[35mКоманда: \033[0m";
		cin >> command;
		cin.get();

		system("@cls||clear");

		switch (command)
		{
		
		case 1:
			show();
			break;

		case 2:
			add();
			break;

		case 3:
			edit();
			break;

		case 4:
			remove();
			break;

		case 5:
			if (!check()) continue;
			save();
			break;
		case 6:
			load();
			break;
		case 0:
			exit(0);
		default:
			return 0;
			break;
		}
	}

}

