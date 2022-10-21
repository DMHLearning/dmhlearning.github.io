#include <iostream>
#include <cstdio>
#include <windows.h>

#pragma execution_character_set("utf-8")

/*
	Compiled against Microsoft Visual†Studio Community†2022 v17.3.3
	Made by Denis Kalashnikov (DMHDev)
	Licensed under MIT License.

	Tests:
	First - (1,1); Second - (2,2); Third - (3,3) | Result: 0
	First - (4,7); Second - (6,4); Third - (1,7) | Result: 4.5
	First - (3,1); Second - (2,4); Third - (7,3) | Result: 14
	First - (0,0); Second - (0,0); Third - (0,1) | Result: 0
*/

int coord_x1, coord_x2, coord_x3;
int coord_y1, coord_y2, coord_y3;
double area;

void main()
{
	// Fix broken UTF-8 in console output in both dev and user environments.
	SetConsoleOutputCP(65001);

    std::cout << "¬ведите координаты первой точки: ";
	std::cin >> coord_x1;
	std::cin >> coord_y1;

	std::cout << "¬ведите координаты второй точки: ";
	std::cin >> coord_x2;
	std::cin >> coord_y2;

	std::cout << "¬ведите координаты третьей точки: ";
	std::cin >> coord_x3;
	std::cin >> coord_y3;

	// Main formula: S = (1/2)*|(x2-x1)(y3-y1)-(x3-x1)(y2-y1)|

	// Count the area of the triangle
	area = (0.5 * abs(((coord_x2 - coord_x1) * (coord_y3 - coord_y1)) - ((coord_x3 - coord_x1) * (coord_y2 - coord_y1))));

	std::cout << "ѕлощадь треугольника:";
	std::cout << area;
}

