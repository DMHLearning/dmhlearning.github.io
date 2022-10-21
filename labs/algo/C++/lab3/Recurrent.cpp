#include "iostream";
#include "fstream"

void main() {
	double epsilon = 0.0001;

	double a = 0, b = 0, c = 1;
	int i = 0;

	double x;

	std::cin >> x >> epsilon;

	std::cout << "Original: " << (1 / pow(1-x, 2));
	std::cout << "\n";

	double answer = 0.00;

	while (abs(c) > epsilon) {
		i = i + 1;

		if (i == 1) {
			a = 1.0;
			b = 1.0;
			c = a * b;
		}

		if (i > 1) { 
			a = i;
			b = b*x;
			c = a*b;
		}

		answer = answer + c;
	}

	
	std::cout << "Recurrent: " << answer;
	std::cin.get();
}