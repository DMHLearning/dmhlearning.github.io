#include "list"
#include "iostream"
#include "fstream"
#include "string"
#include "Windows.h" // Windows API for console output.
#include "consoleapi2.h"
#include <signal.h>

bool isInt(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false && !str[i] == '-')
			return false;
	return true;
}

/*
1. Создать два списка (контейнер list). 
Вывести их на экран. Вставить первый список во второй перед элементом со значением k. 
Вывести второй список на экран. Использовать splice.
*/

void main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	std::list<int> listOne{4, 524, 45, 3, 1, -74, -1};
	std::list<int> listTwo{654,-148,541,3251,6875,6541,21,54,33310,-42022};

	std::string k;

	std::cout << "Введите k по условию задачи: ";

	std::cin >> k;

	std::cout << "\n";

	while (!isInt(k)) {
		std::cout << "\nОшибка: Неверный ввод k.\n";
		std::cout << "Введите k по условию задачи: ";
		std::cin >> k;
		std::cout << "\n";
	}

	int kInt = std::stoi(k);

	std::cout << "Выводим все числа, которые были успешно обработаны и перемещены в списки... \n";

	if (listOne.size() > 0) {
		for (int it : listOne) {
			std::cout << it << " ";
		}
	}
	else {
		std::cout << "\nCписок пуст! \n";
	}

	std::cout << "\n";

	if (listTwo.size() > 0) {
		for (int it : listTwo) {
			std::cout << it << " ";
		}
	}
	else {
		std::cout << "\nCписок пуст! \n";
	}

	std::cout << "\nРезультирующий список: \n";
	auto it = listOne.begin();

	for (int i = 0; i < kInt; i++) {
		it++;
	}

	it--;
	listOne.splice(it, listTwo);

	if (listOne.size() > 0) {
		for (int it : listOne) {
			std::cout << it << " ";
		}
	}
	else {
		std::cout << "\nДек пуст! \n";
	}
}