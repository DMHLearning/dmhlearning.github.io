#include "pt4.h"
#include <algorithm> // for std::find

using namespace std;

void Solve()
{
    Task("str36");

    string s;

    pt >> s;

    int count{};
    string result;

    for (char c : s) {
        bool exists = (result.find(c)) != -1;
        if ((int(c) < 0)) { // This solution is based on weird chars state when all cyrillic chars are out of default ASCII table positions and they're negative.
            if (!exists) {
                result += c;
            }
        }
    }

    pt << result.size() << result;
}
