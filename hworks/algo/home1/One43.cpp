#include "pt4.h"
#include <iostream>
using namespace std;

void Solve()
{
    Task("One43");

    int i;
    int one, two, three, fourth;
    bool answer = false;

    GetN(i);

    one = i / 1000;
    two = i / 100 % 10;
    three = i / 10 % 10;
    fourth = i % 10;

    //cout << one << two << three << fourth;

    if (one * two * three == fourth) {
        answer = true;
    }

    if (two * three * fourth == one) {
        answer = true;
    }

    if (one * two * fourth == three) {
        answer = true;
    }

    if (one * three * fourth == two) {
        answer = true;
    }

    PutB(answer);
}
