#include "iostream";

// MathAPI v0.0.2:
// Shows a greatest common divisor effectively using MOD instructions.
int GCD(int a, int b)
{
	if (b == 0)
		return a;

	if (a > b)
		return GCD(b, a % b);

	else
		return GCD(a, b % a);
}

void main() {
	int a, b, c, d;

	std::cout << "INPUT: ";
	std::cin >> a >> b >> c >> d;

	std::cout << "OUTPUT: " << GCD(a, b) << " " << GCD(a, c) << " " << GCD(a, d);

}