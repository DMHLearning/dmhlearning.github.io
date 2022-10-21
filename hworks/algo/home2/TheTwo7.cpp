#include "pt4.h"
void Solve()
{
    Task("TheTwo7");

    int n;
    GetN(n);

    int firstHoney = 100;
    float secondHoney = 100;

    for (int i = 2; i <= n; i++) {
        firstHoney += 50;
        secondHoney += firstHoney;
    }

    secondHoney /= 1000;

    PutN(firstHoney);
    PutD(secondHoney);
}