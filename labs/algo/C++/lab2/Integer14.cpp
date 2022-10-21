#include "pt4.h"
#include <string>
using namespace std;

void Solve()
{
    Task("Integer14");

    int i, j, k;

    GetN(i);

    j = i % 10;

    k = i / 10;

    string one = to_string(j);
    string two = to_string(k);

    number = one + two;

    int num = std::stoi(number);

    PutN(num);
}
