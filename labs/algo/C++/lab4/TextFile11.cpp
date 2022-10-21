#include "pt4.h"
#include "fstream"
using namespace std;

int sum(int init) {
    int summary = 0;
    while (init != 0)
    {
        summary += init % 10;
        init /= 10;
    }

    return summary;
}

void Solve()
{
    Task("TextFile11");
    int n, k;

    GetN(n);
    GetN(k);

    ofstream outputStream("C:\\PT4Work\\c.dat");

    for (int i = 0; i < n; i++) {
        if (sum(i) == k) {
            outputStream << i << endl;
        }
    }
}
