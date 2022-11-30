#include "Base.h"

void Base::setMark() {
	cout << "Марка: ";
	getline(cin, this->mark);

}

void Base::setModel() {
	cout << "Модель: ";
	getline(cin, this->model);
}