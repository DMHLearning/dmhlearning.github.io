#include "iostream";

void main() {
	int n{};

	std::cin >> n;

	double* array = new double{};
	double* arrayB = new double{};

	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}

	for (int j = 0; j < n; j++) {
		arrayB[j] = 0;
		for (int k = j; k < n; k++) {
			arrayB[j] += array[k];
		}
	}

	for (int c = 0; c < n; c++) {
		std::cout << arrayB[c] << " ";
	}
}