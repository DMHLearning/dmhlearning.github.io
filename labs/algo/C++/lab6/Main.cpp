#include "iostream"
#include "MathAPI.h"
#include "windows.h"
#include "string"

#pragma execution_character_set("utf-8")

/*
	Compiled against Microsoft Visual Studio Community 2022 v17.3.3
	Made by Denis Kalashnikov (DMHDev)
	Licensed under MIT License.
*/

void main() {
	/* Fix console output by setting ConsoleOutput to 65001 (modern UTF-8) */
	SetConsoleOutputCP(65001);

	/* Parse all the required parameters; */
	int a, b, c, d, k, m, e, f;

	std::cout << "Введите все необходимые переменные для решения задачи: \n";
	std::cin >> a >> b >> c >> d >> k >> m >> e >> f;

	/* Solve the problematic task using our custom MathAPI; See MathAPI.h and MathAPI.cpp for source code; */

	SUMM(a, b, c, d); /* Note: this function resets the first two parameters since we're doing simple math, not memorized ones. Memorized ones is supported in MathAPI, but not implemented in this project. */

	SUMM(a, b, k, m); /* Note: this function resets the first two parameters since we're doing simple math, not memorized ones. Memorized ones is supported in MathAPI, but not implemented in this project. */

	MULT(a, b, e, f); /* Note: this function resets the first two parameters since we're doing simple math, not memorized ones. Memorized ones is supported in MathAPI, but not implemented in this project. */

	std::cout << "Значение дроби: " << std::to_string(a) << "/" << std::to_string(b); // Show the answer.
}	