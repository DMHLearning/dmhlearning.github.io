#include "pt4.h"
using namespace std;

void Swap(double &first, double &second) {
    double buffer{};

    buffer = first;
    first = second;
    second = buffer;
}

void Solve()
{
    Task("Proc10");

    double a, b, c, d;
    GetD(a);
    GetD(b);
    GetD(c);
    GetD(d);

    Swap(a, b);
    Swap(c, d);
    Swap(b, c);

    PutD(a);
    PutD(b);
    PutD(c);
    PutD(d);
}
