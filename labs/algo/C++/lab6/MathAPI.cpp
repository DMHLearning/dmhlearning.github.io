#include "MathAPI.h"

/*
	MathAPI v0.0.1;
	A part of C++ Math module of a currently unnamed project to use in my C++/Java projects.
	No source code available at the moment. Names of the methods are changed to fit the task requirements.

	Compiled against Microsoft Visual Studio Community 2022 v17.3.3
	Made by Denis Kalashnikov (DMHDev)
	Licensed under MIT License.
*/

// Shows a least common divisor effectively using MOD instructions.
int NOD(int a, int b)
{
	if (a % b == 0)
		return b;

	if (b % a == 0)
		return a;

	if (a > b)
		return NOD(a % b, b);

	return NOD(a, b % a);
}

// Reduces numerator and denominator of the fraction.
int SOKR(int& a, int& b)
{
	int nod = NOD(a, b);

	a = a / nod;
	b = b / nod;

	return a, b;
}

// Gets the summary of two fractions using OVERWRITING parameters. 
// Use MathAPI#memorizedFractionSummary for a parameter-safe version, but requires more memory.
int SUMM(int& a, int& b, int c, int d)
{
	a = (a * d + b * c);
	b = (b * d);

	SOKR(a, b);

	return a, b;
}

// Gets the multiplication of two fractions using OVERWRITING parameters. 
// Use MathAPI#memorizedFractionMultiply for a parameter-safe version, but requires more memory.
int MULT(int& a, int& b, int c, int d)
{
	a = a * c;
	b = b * d;

	return a, b;
}
