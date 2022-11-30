
#include "Keeper.h"


void Keeper::addTransport(Base* transport) {
	Base** newList = new Base * [listSize + 1];

	for (int i = 0; i < listSize; i++) {
		newList[i] = list[i];
	}

	newList[listSize++] = transport;

	delete[]list;
	list = newList;
}

void Keeper::removeTransport(int number) {
	Base** newList = new Base * [listSize - 1];

	int index = 0;
	for (int i = 0; i < listSize; i++) {
		if (i == number) continue;

		newList[index] = list[index];
		index++;
	}

	delete[] list;
	list = newList;
	listSize--;
}

void Keeper::save(string fileName) {
	ofstream out;

	out.open(fileName);

	if (out.is_open())
	{
		for (int i = 0; i < listSize; i++) {
			out << list[i]->toFileString() << "\n";
		}
		cout << "Сохранено!";
	}
	else {
		cout << "Не удалось открыть файл!";

	}

	out.close();

	cout << endl << "\033[35mНажмите любую клавишу чтобы вернуться в меню\033[0m" << endl;
	cin.get();
}

void Keeper::load(string fileName) {

	string line;

	ifstream in(fileName);

	try
	{
		if (!in.is_open()) throw std::runtime_error("Не удалось открыть файл.");

		int numberOfLines = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n'); // считаем количество строк в файле
		if (numberOfLines <= 0 || numberOfLines % 7 != 0) throw std::runtime_error("Файл повреждён!");

		in.seekg(0);

		int lineNum = 0;
		Base** newList = new Base * [(int)numberOfLines / 7];
		string lines[7];

		while (getline(in, line))
		{
			string str = line;

			lines[(lineNum++) % 7] = str;

			int pos = lineNum / 7 - 1;

			if (lineNum % 7 == 0) {
				if (string("Car") == lines[0]) newList[pos] = new Car(lines);
				else if (string("Bus") == lines[0]) newList[pos] = new Bus(lines);
				else if (string("Motorcycle") == lines[0]) newList[pos] = new Motorcycle(lines);
				else throw std::runtime_error("Неизвестный тип транспорта");
			}
		}

		delete[]list;

		list = newList;
		listSize = (int)numberOfLines / 7;

		cout << "Загружено!";
	}
	catch (std::runtime_error err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка!";
	}

	in.close();

	cout << endl << "\033[35mНажмите любую клавишу чтобы вернуться в меню\033[0m" << endl;
	cin.get();

}

Base** Keeper::getList() {
	return list;
}

int Keeper::getSize() {
	return listSize;
}

const bool operator!(Keeper& garage)
{
	return (bool)garage.getSize();
}
