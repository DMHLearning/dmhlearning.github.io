#include "pt4.h"
#include "fstream"
#include <iostream>
#include <vector>
using namespace std;

void Solve()
{
    Task("TheMassiv40");

    string inputName;
    string outputName;

    GetS(inputName);
    GetS(outputName);

    ifstream in("C:\\PT4Work\\" + inputName);

    string parse;
    if (in.is_open()) {
        getline(in, parse);

        int n = std::stoi(parse);

        int* array = new int[n];

        getline(in, parse);

        string num;
        string temp = parse;
        int counter{};
        for (char& c : temp) {
            if (c != ' ') {
                num += c;
            }
            else {
                int parsed = std::stoi(num);

                if (counter < n) array[counter] = parsed;

                counter += 1;
                num = "";
            }
        }

        std::vector<int> vec(n);
        counter = 0;
        for (int i = 0; i < n; i++) {
            vec[i] = array[i];
            if (vec[i] % 2 == 0) {
                counter++;
            }
        }
        
        std::vector<int> vec_final(n);
        for (int i = 0; i < n; i++) {
            vec_final[i] = vec[i];
        }

        int i{};
        int countvec{};
        for (auto x : vec) {
            i += 1;
            if (x % 2 == 0) {
                vec_final.insert(vec_final.begin() + i + countvec, 0);
                countvec++;
            }
        }
      
        delete[] array;

        ofstream outputStream("C:\\PT4Work\\" + outputName);

        for (auto x : vec_final)
            outputStream << x << " ";
    }

    if (!in.eof() && in.fail())
        std::cout << "error reading " << "C:\\PT4Work\\" + inputName << endl;

    in.close();


}
