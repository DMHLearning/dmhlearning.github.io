#include "pt4.h"
#include "string"
#include <fstream>
using namespace std;

void Solve()
{
    Task("str22");
    
    string s;

    //boolean array  isLatinOrCyrillic, isNumber, isLittle, isBig, isSpecializedSymbol;
    boolean array[5]{false, false, false, false, false};

    int type;

    pt >> s >> type;

    unsigned char c = s[0];

    if ((c >= 65 && c <= 90) 
        || (c >= 97 && c <= 122) 
        || (c >= 128 && c <= 159)
        || (c >= 160 && c <= 175)
        || (c >= 224 && c <= 239)) array[0] = true;

    if ((c >= 48 && c <= 57)) array[1] = true;

    if ((c >= 97 && c <= 122) || (c >= 160 && c <= 175) || (c >= 224 && c <= 239) || c == 241) array[2] = true;
    if ((c >= 65 && c <= 90) || (c >= 128 && c <= 159) || c == 240) array[3] = true;
    if (c <= 32) array[4] = true;

    bool answer = array[type-1]; // bool<->boolean conversion from 0/1 to false/true;
    pt << answer;
}
