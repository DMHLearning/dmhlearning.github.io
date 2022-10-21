#include "pt4.h"
using namespace std;

void RecSum(int iterator, double component, double& result) {
    for (int i = 0; i < iterator; i++) {
        if (i == 0) {
            result = component;
        }

        double temp = 1;
        if (i > 0) {
            for (int j = 0; j < pow(2, i); j++) {
                temp = temp * component;
            }

            result = result + temp;
            temp = 1;
        }
    }
}

void Solve()
{
    Task("Reccur15");
    int n;
    double x;
    double s{};

    GetN(n);
    GetD(x);

    RecSum(n, x, s);
    pt << s;
}
