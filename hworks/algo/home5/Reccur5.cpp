#include "pt4.h"
using namespace std;

void RecMin(int& in, int& out) {
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
}

void Solve()
{
    Task("Reccur5");
    int n;

    GetN(n);

    int out;
    RecMin(n, out);
    
    pt << out;
}
