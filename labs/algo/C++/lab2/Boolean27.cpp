#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Boolean27");

    boolean answer = false;
    double x, y;
    GetD(x);
    GetD(y);

    if (x < 0) {
        answer = true;
    }

    PutB(answer);
}
