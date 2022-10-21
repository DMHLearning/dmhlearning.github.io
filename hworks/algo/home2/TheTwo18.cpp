#include <windows.h>
#pragma hdrstop
#include "pt4.h"
using namespace std;

void Solve()
{
	Task("TheTwo18");
	int n, a, min = 10, num = 1, i = 1;
	pt >> n;
	while (n > 0)
	{
		a = n % 10;
		if (a <= min)
		{
			min = a;
			num = i;
		}
		i++;
		n /= 10;
	}
	pt << min << num;
}