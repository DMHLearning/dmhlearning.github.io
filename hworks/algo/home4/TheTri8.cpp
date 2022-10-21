#include "pt4.h"
#include "iostream"
using namespace std;

void Solve()
{
    Task("TheTri8");
    int a, b;

    GetN(a);
    GetN(b);

    int counter = 0;
    for (int i = a; i <= b; i++) {
        string string_number = to_string(i);
        string string_reversed = string_number;
        reverse(string_reversed.begin(), string_reversed.end());
        if (string_number == string_reversed) {
            counter++;
            PutN(i);
        }
    }

    if (counter == 0) {
        pt << "No solution";
    }
}
