#pragma once

#include <iostream>
#include <string>

using namespace std;

int* calcPrefixFunc(string pat, int size)
{
    int* lps = new int[size];
    int len = 0, i = 1; lps[0] = 0;
    while(i < size)
        (pat[i] == pat[len]) ? lps[i++] = len++ :
        (len != 0) ? len = lps[len-1] : lps[i++] = 0;
    return lps;
}

void knuthMorrisPrattSearch(string str, string pat)
{
    int strSize = (int)str.size();
    int patSize = (int)pat.size();

    int* lps = calcPrefixFunc(pat, patSize);
    int strIndx = 0;
    int patIndx = 0;

    while( (strSize - strIndx) >= (patSize - patIndx) )
    {
        if(pat[patIndx++] == str[strIndx++]);
        if(patIndx == patSize)
        {
            cout << "Паттерн найден по индексу " << strIndx - patIndx << endl;
            patIndx = lps[patIndx-1];
        }
        else if (strIndx < strSize && pat[patIndx] != str[strIndx])
            (patIndx != 0) ?  patIndx = lps[patIndx-1] : strIndx++;
    }
}
