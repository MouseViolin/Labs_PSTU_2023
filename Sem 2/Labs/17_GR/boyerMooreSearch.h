#pragma once

#include <iostream>
#include <string>

using namespace std;

const int CHAR_NUM = 256;

void calcCharTable(string str, int size, int charTable[CHAR_NUM])
{
    for (int i = 0; i < CHAR_NUM; i++)
        charTable[i] = -1;
    
    for (int i = 0; i < size; i++)
        charTable[(int)str[i]] = i;
}

void boyerMooreSearch(string str, string pat)
{
    int strSize = (int)str.size();
    int patSize = (int)pat.size();

    int shift_table[CHAR_NUM];

    calcCharTable(str, patSize, shift_table);

    int shift = 0;

    while(shift <= (strSize - patSize))
    {
        int j = patSize - 1;
        while(j >= 0 && pat[j] == str[shift+j]) j--;

        if (j < 0)
        {
            cout << "Паттерн найден по индексу " << shift << endl;
            if (shift+patSize < strSize)
                shift += patSize - shift_table[str[shift+patSize]];
            else shift++;
        }
        else shift += max(1, j - shift_table[str[shift+j]]);
    }
}
