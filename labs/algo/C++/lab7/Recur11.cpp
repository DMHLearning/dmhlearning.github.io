#include "iostream";

int MaxElem(int* array, int n)
{
    if (n == 1) return array[0];

    return array[n - 1] > MaxElem(array, n - 1) ? array[n - 1] : MaxElem(array, n - 1);
    // if previous element is more than next -> switch to next and hold the stack for max element to reverse it on end of the recursion.
}

void main() {
    int nA, nB, nC;

    std::cout << "INPUT: ";
    std::cin >> nA >> nB >> nC;
    std::cout << "\n INPUT OF ARRAYS: \n";

    int* a = new int[nA];
    int* b = new int[nB];
    int* c = new int[nC];

    for (int i = 0; i < nA; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < nB; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i < nC; i++) {
        std::cin >> c[i];
    }

    std::cout << "OUTPUT: " << "nA: " << MaxElem(a, nA) << "\n";
    std::cout << "OUTPUT: " << "nB: " << MaxElem(b, nB) << "\n";
    std::cout << "OUTPUT: " << "nC: " << MaxElem(c, nC) << "\n";
}