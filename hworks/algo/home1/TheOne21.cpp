#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheOne21");

    int n;

    double m;

    GetN(n);
    GetD(m);

    switch (n) {
        case 1: pt << m; break;
        case 2: pt << (m / 1000000); break;
        case 3: pt << (m / 1000); break;
        case 4: pt << (m * 1000); break;
        case 5: pt << (m * 100); break;
    }
}
