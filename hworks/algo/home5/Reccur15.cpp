#include "pt4.h"
using namespace std;

double RecSum(const int& iterator, double component) {
    /* Recurrent solution, much faster, less memory */
    /*
    for (int i = 0; i < iterator; i++) {
        if (i == 0) {
            result = component;
        }

        double temp = 1;
        if (i > 0) {
            temp = pow(component, pow(2, iterator-1);

            result = result + temp;
            temp = 1;
        }
    }
    */
    
    /* Recurrent solution, less faster, more memory */
    if (iterator == 0) 
        return 0;
    else 
        return RecSum(iterator - 1, component) + pow(component, pow(2, iterator-1));
}

void Solve()
{
    Task("Reccur15");
    int n;
    double x;
    double s{};

    GetN(n);
    GetD(x);

    s = RecSum(n, x);
    pt << s;
}
