#include "pt4.h"
using namespace std;

int RecMin(const int in, int& out) {
    /* Recurrent solution, much faster, less memory */
    /*
    int min = MAXINT;
    int cur{};

    if (in == 0) {
        min = 0;
    }

    while (in != 0) {
        cur = in % 10;
        in /= 10;

        if (min >= cur) {
            min = cur;
        }
    }

    out = min;
    */

    /* Recursive solution, much slower, more memory */
    if (in == 0) return in;

    int temp = in % 10;

    if (out > temp) out = temp;

    return RecMin(in / 10, out);
}

void Solve()
{
    Task("Reccur5");
    int n;

    GetN(n);

    int out = n % 10;
    RecMin(n, out);

    pt << out;
}
