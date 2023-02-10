#include "iostream";

void main() {
	int n{};

	std::cin >> n;

	int* array = new int{};

	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}

	int i;

	for (i = 0; i < n - 1; i++) if (array[i] * array[i + 1] >= 0) break;
	if (i == n - 1) {
		std::cout << 0;
	}
	else std::cout << i + 2;
}