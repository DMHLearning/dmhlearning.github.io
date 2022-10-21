#include "iostream"
using namespace std;

void main() {
	double a = 0, s = 0, b = 0, c = 0, n, x;
	cin >> n >> x;
	unsigned int i = 0, counter = 0;

	while (i < n)
	{
		i = i + 1;

		if (i == 1) {
			b = x;
			c = 1;
			a = b * c;
		}

		if ((i > 1) && (i % 2 == 0)) {
			b = b * x;
			c = static_cast<double>(1) / i;
			a = -(b * c);
		}
		else {
			b = b * x;
			c = static_cast<double>(1) / i;
			a = (b * c);
		}

		s = s + a;
	}

	cout << s;
	cout << "\n";
	cout << log(x + 1);
}