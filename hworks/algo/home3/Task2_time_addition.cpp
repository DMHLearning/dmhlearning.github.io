#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

void main() {
	std::time_t currentTime = std::time(0);

	int p, q, r;

	std::cin >> p >> q >> r;

	std::ostringstream oss;

	currentTime += (r);
	currentTime += (60 * q);
	currentTime += (60 * 60 * p);

	oss << std::put_time(std::localtime(&currentTime), "%H:%M:%S");

	auto str = oss.str();

	std::cout << str;
}