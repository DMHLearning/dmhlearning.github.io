#include "iostream"
#include <Windows.h>
#include <string>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;

	std::cin >> n;

	double prevElement;
	double element;
	double res;
	int prevElementCounter = 0, elementCounter = 0;
	int min = INT8_MAX * INT8_MAX;

	for (int i = 0; i <= n - 1; i++) {
		std::cin >> element;
		if (i == 0) {
			prevElement = element;
		}

		if (i > 0) {

			res = prevElement * element;

			if (min >= res) {
				min = res;
				elementCounter = i + 1;
				prevElementCounter = i;
			}

			prevElement = element;
		}
	}

	std::cout << "Меньший номер: " + std::to_string(prevElementCounter) << "\n";

	std::cout << "Больший номер: " + std::to_string(elementCounter) << std::endl;
}
