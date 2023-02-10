#include <list>
#include <iostream>
#include <string>
#include "Windows.h" // Windows API for console output.
#include "consoleapi2.h"
#include <signal.h>

/*
2. Сгенерировать список из N элементов. Список должен содержать числа от -20 до 20. 
Удалить из списка все числа, кратные 5. Обязательно использовать предикаты.
*/

bool isDividableByFive(int it) {
	if (it % 5 == 0) return true;
				else return false;
}

extern "C" void aborting(int signal_number) {
	std::cout << "--- SIGABRT CALL EXCEPTION HANDLED ---\n";
	std::cout << "Возникла ошибка ввода данных. Введены неверные значения для обработки или неверно указан путь к файлу.\n";
	std::cout << "Код ошибки: " << signal_number;
}

bool isInt(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

void main() {
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	signal(SIGABRT, &aborting);
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	std::string N{};

	std::cout << "Введите количество элементов списка: ";
	std::cin >> N;

	while (!isInt(N)) {
		std::cout << "\nОшибка: Неверный ввод.\n";
		std::cout << "Введите количество элементов списка: ";
		std::cin >> N;
		std::cout << "\n";
	}

	int SIZE_INT = stoi(N);
	std::list<int> list;

	srand(time(0));

	for (int i = 0; i < SIZE_INT; i++) {
		int r = rand() % 41 - 20;

		list.push_back(r);
	}

	std::cout << "Элементы списка: ";
	for (int it : list) {
		std::cout << it << " ";
	}
	
	std::cout << "\n";
	std::cout << "Элементы изменённого списка: ";
	list.remove_if(isDividableByFive);

	for (int it : list) {
		std::cout << it << " ";
	}
}