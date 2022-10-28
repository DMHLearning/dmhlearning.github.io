#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheMassiv10");
    int n;

    GetN(n);

    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        pt >> array[i];
    }

    int max = array[0];
    int min = array[n-1];

    for (int j = 0; j < (n / 2); j++) {
        if (max < array[j]) {
            max = array[j];
        }
    }

    for (int j = n - 1; j > (n / 2); j--) {
        if (min > array[j]) {
            min = array[j];
        }
    }

    pt << max;
    pt << min;
    delete[] array;
}
