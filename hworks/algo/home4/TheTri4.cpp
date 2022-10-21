#include "fstream"
#include "iostream"
#include "sstream"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "cstring"
#include "pt4.h"
using namespace std;

#define ZERO 0
#define ONE  1

void distance(int x1, int y1, int x2, int y2, int res) {
    res = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

template <size_t N>
void splitString(string(&arr)[N], string str)
{
    int n = 0;
    istringstream iss(str);
    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
        arr[n] = *it;
}

// Function to in-place trim all spaces in the
// string such that all words should contain only
// a single space between them.
void removeSpaces(string& str)
{
    // n is length of the original string
    int n = str.length();

    // i points to next postion to be filled in
    // output string/ j points to next character
    // in the original string
    int i = 0, j = -1;

    // flag that sets to true is space is found
    bool spaceFound = false;

    // Handles leading spaces
    while (++j < n && str[j] == ' ');

    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[j] == '.' || str[j] == ',' ||
                str[j] == '?') && i - 1 >= 0 &&
                str[i - 1] == ' ')
                str[i - 1] = str[j++];

            else
                // copy current character at index i
                // and increment both i and j
                str[i++] = str[j++];

            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    // Remove trailing spaces
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
    {
        if (str[i - 1] == ' ')
            str.erase(str.begin() + i - 1, str.end());
        else
            str.erase(str.begin() + i, str.end());
    }
}

void Solve()
{
    Task("TheTri4");

    ifstream in("C:\\PT4Work\\d.otr");

    double min = INT8_MAX * INT8_MAX;
    double res = 0;
    string counterS = "";
    int counter = 0;
    int ij = 0;
    int num = 0;
    string parse;
    if (in.is_open()) {
        getline(in, counterS);

        counter = std::stoi(counterS);
        while (ij < counter) {
            getline(in, parse);

            removeSpaces(parse); // use external StringAPI for C++

            vector<int> array;
            stringstream ss(parse);
            int temp;
            while (ss >> temp)
                array.push_back(temp);

            res = sqrt(pow(array[2] - array[0], 2) + pow(array[3] - array[1], 2));

            if (min >= res) {
                min = res;
                num = ij;
            }

            ij++;
        }
    }

    PutN(num+1);

    if (!in.eof() && in.fail())
        std::cout << "error reading " << "C:\\PT4Work\\d.txt" << endl;

    in.close();
}