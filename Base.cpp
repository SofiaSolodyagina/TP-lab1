#include "Base.h"

void Base::setMark() {
	cout << "�����: ";
	getline(cin, this->mark);

}

void Base::setModel() {
	cout << "������: ";
	getline(cin, this->model);
}