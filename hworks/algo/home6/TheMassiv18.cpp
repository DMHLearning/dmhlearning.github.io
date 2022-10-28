#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheMassiv18");
    int n;

    GetN(n);

    int* array = new int[n];

    for (int j = 0; j < n; j++) {
        pt >> array[j];
    }

    int max_one = -MAXINT;
    int max_two = -MAXINT;

    for (int i = 0; i < n; i++) {

        if (array[i] >= max_two) {
            max_two = array[i];
        }

        if (array[i] >= max_one) {
            max_two = max_one;
            max_one = array[i];
        }
    }

    pt << max_two;
    pt << max_one;
    delete[] array;
}
