#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheTwo14");

	int n;

	GetN(n);

	double summary = 0;
	double counter = 1;

	for (int i = 5; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			counter *= i;
		}

		summary += 1 / counter;
		counter = 1;
	}

	PutD(summary);
}