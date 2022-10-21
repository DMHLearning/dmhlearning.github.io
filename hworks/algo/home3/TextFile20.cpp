#include "pt4.h"
#include "fstream"
#include <iostream>
using namespace std;

void Solve()
{
    Task("TextFile20");

    ifstream in("C:\\PT4Work\\e.txt");

    string parse;
    if (in.is_open()) {
        getline(in, parse); // ignore the number since we don't need it whatsoever
        getline(in, parse);

        string temp = parse;

        int parsed = 0;
        string num;
        int max = -1;
        for (char& c : temp) {
            if (c != ' ') {
                num += c;
            }
            else {
                parsed = std::stoi(num);

                if (max <= parsed) {
                    max = parsed;
                }

                num = "";
            }
        }

        string sub = std::to_string(max);

        int start = 0;
        int count = 0;
        int pos = 0;
        for (;;) {
            pos = parse.find(sub.c_str(), start);
            if (pos != -1) {
                start = pos + sub.size();
                count++;
            }
            else {
                break;
            }
        }

        PutN(count);
    }

    if (!in.eof() && in.fail())
        std::cout << "error reading " << "C:\\PT4Work\\e.txt" << endl;

    in.close();
}
