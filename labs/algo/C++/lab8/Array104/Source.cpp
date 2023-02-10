#include "iostream"

void main() {
	int n{};

	std::cin >> n;

	double* array = new double{};

	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}

	int k{}, m{};
	std::cin >> k >> m;

	double* arrayB = new double{};

	if (!(m > 1 && m < 10) || !(1 <= k && k <= m)) std::cout << "Incorrect parameters. Restart the program.";

	for (int i = 0; i < k - 1; i++) {
		arrayB[i] = array[i];
	}

	for (int j = k - 1; j < m+1; j++) {
		arrayB[j] = 0.00;
	}

	for (int f = (k - 1 + m); f < m + n + 1; f++) {
		arrayB[f] = array[f - m];
	}

	for (int p = 0; p < m + n; p++) {
		std::cout << arrayB[p] << " ";
	}
}