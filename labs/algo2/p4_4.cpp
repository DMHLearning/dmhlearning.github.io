#include "deque"
#include "iostream"
#include "fstream"
#include "string"
#include "Windows.h" // Windows API for console output.
#include "consoleapi2.h"
#include <signal.h>

extern "C" void aborting(int signal_number) {
	std::cout << "--- SIGABRT CALL EXCEPTION HANDLED ---\n";
	std::cout << "Возникла ошибка инициализации файла. Введены неверные значения для обработки или неверно указан путь к файлу.\n";
	std::cout << "Код ошибки: " << signal_number;
}

bool isInt(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false && !str[i] == '-')
			return false;
	return true;
}

void main() {
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	signal(SIGABRT, &aborting);
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	std::string path;

	std::cout << "Введите путь до желаемого файла: ";

	std::cin >> path;

	std::cout << "\n";

	std::ifstream inputStream;

	try {
		std::string number;
		std::deque<int> deque;
		int numberInt;

		inputStream.open(path);

		while (!inputStream.eof()) {
			inputStream >> number;
			inputStream.ignore();

			if (isInt(number)) {
				numberInt = std::stoi(number);
				if (numberInt % 2 == 0) deque.push_back(-1);

				deque.push_back(numberInt);
			}
			else {
				std::cout << "Ошибка: данная строка не является числом! Найденная строка: " << number << ". Игнорируем её...\n";
			}
		}

		inputStream.close();

		std::cout << "Выводим все числа, которые были успешно обработаны и перемещены в дек... \n";

		if (deque.size() > 0) {
			for (int it : deque) {
				std::cout << it << " ";
			}
		}
		else {
			std::cout << "\nДек пуст! \n";
		}
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Невозможно открыть файл " << path << ", поскольку он повреждён или недоступен для чтения. Также возможно указан неверный путь до файла.";
	}
}