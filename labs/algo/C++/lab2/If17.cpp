#include "pt4.h"
using namespace std;

void Solve()
{
    Task("If17");
    
    double a, b, c;
    boolean upside = false;

    GetD(a);
    GetD(b);
    GetD(c);

    if (a > b && b > c && a > c) {
        upside = true;
    }

    if (upside) {
        a = a * 2;
        b = b * 2;
        c = c * 2;
    }
    else {
        a = abs(a);
        b = abs(b);
        c = abs(c);
    }

    PutD(a);
    PutD(b);
    PutD(c);
}
