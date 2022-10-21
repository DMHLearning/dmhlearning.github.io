#include "pt4.h"
#include <iostream>

void Solve()
{
    Task("TheOne10");

    double x, y;

    GetD(x);
    GetD(y);

    if ((pow(x-1, 2) + pow(y, 2) <= 1) && (y <= 0.5)) {
        pt << true;
    }
    else {
        pt << false;
    }
}
