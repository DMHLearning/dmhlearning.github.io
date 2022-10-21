#include "pt4.h"
#include "fstream"
#include <iostream>
using namespace std;

void Solve()
{
    Task("TextFile6");

    ifstream in("C:\\PT4Work\\b.num");

    string parse;
    if (in.is_open()) {
        getline(in, parse);

        string temp = parse;

        int parsed = 0;
        string num;
        int count = 0;
        for (char& c : temp) {
            if (c != ' ') {
                num += c;
            }
            else {
                parsed = std::stoi(num);

                if (parsed >= 100 && parsed <= 999) {
                    if (parsed % 2 == 0) {
                        count++;
                    }
                }

                num = "";
            }
        }

        PutN(count);
    }

    if (!in.eof() && in.fail())
        std::cout << "error reading " << "C:\\PT4Work\\e.txt" << endl;

    in.close();
}
