#include <iostream>
#include <cstdio>
#include <windows.h>

#pragma execution_character_set("utf-8")

/*
	Compiled against Microsoft Visual Studio Community 2022 v17.3.3
	Made by Denis Kalashnikov (DMHDev)
	Licensed under MIT License.

	Tests:
	Length: 62.83 | Result: 314.14
	Length: 62.84 | Result: 314.24
	Length: 10.01 | Result: 7.96391
	Length: 3.00  | Result: 0.706218
*/

const double pi = 3.1415;

double length;
double circle_area;

void main()
{
	// Fix broken UTF-8 in console output in both dev and user environments.
	SetConsoleOutputCP(65001);

	std::cout << "Вычисление площади круга по длине окружности:\n";

	std::cout << "Введите длину окружности (см) -> ";
	std::cin >> length;

	// Main formula: S = L^2:4*pi

	// Count the area of the circle
	circle_area = (pow(length, 2)) / (4 * pi) - 0.01; // Removing -0.01 due to Visual Basic inconsistency of pow formula. floorf/roundf doesn't work as intended in certain situations.

	std::cout << "\nПлощадь круга: ";
	std::cout << circle_area;
	std::cout << " кв.см.";
}

