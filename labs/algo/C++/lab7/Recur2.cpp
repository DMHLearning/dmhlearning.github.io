#include "iostream";

int Fact2(int n) {

	if (n <= 1) return 1;

	if (n == 2) return 2;

	return n * Fact2(n - 2);
}

void main() {
	int n{};

	for (int i = 0; i < 5; i++) {
		std::cout << "OUTPUT: ";
		std::cin >> n;

		std::cout << "OUTPUT: " << Fact2(n) << "\n";
	}
}