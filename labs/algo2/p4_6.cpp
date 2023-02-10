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
	std::string k;
	std::string n;

	std::cout << "Введите путь до желаемого файла: ";

	std::cin >> path;

	std::cout << "\n";

	std::cout << "Введите k по условию задачи: ";

	std::cin >> k;

	std::cout << "\n";

	while (!isInt(k)) {
		std::cout << "\nОшибка: Неверный ввод k.\n";
		std::cout << "Введите k по условию задачи: ";
		std::cin >> k;
		std::cout << "\n";
	}

	std::cout << "Введите N по условию задачи: ";

	std::cin >> n;

	std::cout << "\n";

	while (!isInt(n)) {
		std::cout << "\nОшибка: Неверный ввод N.\n";
		std::cout << "Введите N по условию задачи: ";
		std::cin >> n;
		std::cout << "\n";
	}

	std::ifstream inputStream;

	try {
		std::deque<int> deque;
		std::string number;
		int numberInt;

		int kInt = std::stoi(k);
		int nInt = std::stoi(n);

		inputStream.open(path);

		while (!inputStream.eof()) {
			inputStream >> number;
			inputStream.ignore();

			if (isInt(number)) {
				numberInt = std::stoi(number);
				if (!(numberInt < kInt)) deque.push_back(numberInt);
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

		int counter{};

		if (deque.size() > 0) {
			for (int it : deque) {
				if (it == nInt) counter++;
			}

			std::cout << "\nКоличество чисел равных N = " << nInt << ": " << counter << "\n";
		}
		else {
			std::cout << "\nДек пуст и не найдены числа равные N!\n";
		}
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Невозможно открыть файл " << path << ", поскольку он повреждён или недоступен для чтения. Также возможно указан неверный путь до файла.";
	}
}