#include "iostream"

int DigitCount(int number) {
	int counter{};
	while (number > 0) {
		number /= 10;
		counter++;
	}

	return counter;
}

void main() {
	std::cout << DigitCount(2192);
	std::cout << DigitCount(3);
	std::cout << DigitCount(678);
	std::cout << DigitCount(619);
	std::cout << DigitCount(24355);
}
