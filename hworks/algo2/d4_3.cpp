#include <stack>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Windows.h" // Windows API for console output.
#include "consoleapi2.h"
#include <signal.h>
#include <string>
#include <list>

extern "C" void aborting(int signal_number) {
	std::cout << "--- SIGABRT CALL EXCEPTION HANDLED ---\n";
	std::cout << "Возникла ошибка инициализации файла. Введены неверные значения для обработки или неверно указан путь к файлу.\n";
	std::cout << "Код ошибки: " << signal_number;
}

bool isInt(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

float scan(char ch) {
	int value;
	value = ch;
	return float(value - '0');
}

int isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') return 1;
	return -1;
}

int isOperand(char ch) {
	if (ch >= '0' && ch <= '9') return 1;
	return -1;
}

float operation(int a, int b, char op) {
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return static_cast<float>(b) / a;
	else if (op == '^')
		return pow(b, a);
	else
		return INT_MIN;
}

float postfixEval(std::string postfix) {
	int a, b;
	std::stack<float> stack;
	std::string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++) {
		if (isOperator(*it) != -1) {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(operation(a, b, *it));
		}
		else if (isOperand(*it) > 0) {
			stack.push(scan(*it));
		}
	}
	return stack.top();
}

/*
3. Считать из текстового файла арифметическое выражение в постфиксной записи (например, 5 6 3 * + ).
Выражение содержит знаки четырех арифметических действий. Вычислить его значение, используя для решения стек.
*/

void main() {
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	signal(SIGABRT, &aborting);
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	std::string path;
	std::ifstream inputStream;

	std::cout << "Введите путь до желаемого файла: ";

	std::cin >> path;

	std::cout << "\n";

	try {
		std::string eval;

		inputStream.open(path);

		while (std::getline(inputStream, eval)) {
			std::string delimiter = " ";

			size_t pos = 0;
			std::string token;
			while ((pos = eval.find(delimiter)) != std::string::npos) {
				token = eval.substr(0, pos);
				eval = eval + token;
				eval.erase(0, pos + delimiter.length());
			}
		}

		std::cout << postfixEval(eval);
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Невозможно открыть файл " << path << ", поскольку он повреждён или недоступен для чтения. Также возможно указан неверный путь до файла.";
	}
}