#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("TextFile2");

    int n1, n2;

    GetN(n1);
    GetN(n2);

    int i = 0, a = 0, b = 0, c = 0;
    ofstream outputStream;

    outputStream.open("C:\\PT4Work\\b.tst");

    if (outputStream.is_open()) {
        while (i <= n2) {

            if (i == 0) {
                a = 0;
                c = a + b;
                if (n1 <= i && i <= n2) {
                    outputStream << c << endl;
                }
            }

            if (i == 1) {
                b = 1;
                c = a + b;
                if (n1 <= i && i <= n2) {
                    outputStream << c << endl;
                }
            }

            if (i > 1) {
                c = a + b;
                a = b;
                b = c;

                if (n1 <= i && i <= n2) {
                    outputStream << c << endl;
                }
            }

            i = i + 1;
        }
    }
}
