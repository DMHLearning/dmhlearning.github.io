#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheMassiv30");
    int n;

    GetN(n);

    int* array = new int[n];

    for (int i = 0; i < n; i++) {
        pt >> *(array+i);
    }

    int counter{};
    for (int j = n-2; j > 0; j--) {
        if (*(array + j - 1) < *(array + j) && *(array + j + 1) < *(array + j)) {
            pt << j;
            counter++;
        }
    }

    pt << counter;
    delete[] array;
}
