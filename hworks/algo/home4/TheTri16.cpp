#include "pt4.h"
#include "iostream"
#include "cstring"
using namespace std;

int map_x2i(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return 0;
}

int xtoi(const char* str, int base)
{
    int i = 0;
    size_t l = strlen(str);
    while (l--) { i = i * base + map_x2i(*str++); }
    return i;
}

char base_char(unsigned num)
{
    return (num <= 9) ? ('0' + num) : ('A' + num - 10);
}

string show_num(unsigned num, unsigned base)
{
    if (base <= 1)
    {
        std::cout << base << ": " << "invalid base" << std::endl;
    }
    else if (num == 0)
    {
        std::cout << base << ": " << "0" << std::endl;
    }
    else
    {
        std::string str;

        while (num)
        {
            str.insert(0, 1, base_char(num % base));
            num /= base;
        }

        return str.c_str();
    }
}

void Solve()
{
    Task("TheTri16");
    int x, y, p;

    GetN(x);
    GetN(y);
    GetN(p);

    int x10, y10;
    x10 = xtoi(to_string(x).c_str(), p);
    y10 = xtoi(to_string(y).c_str(), p);

    int res = x10 - y10;
    string r = show_num(res, p);
    PutN(std::stoi(r));
}
