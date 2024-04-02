

# Лабораторная работа №6
>[!IMPORTANT]
>Тема : "Методы поиcка"
>Цель: Работа с алгоритмами Кнут-Моррис-Пратта и Бойер-Мура, разбор алгоритмов и их реализация.

# Вариант №6
- boyerMooreSearch
- knuthMorrisPrattSearch

# Блок-схема
О.о

# Код программы

### main.cpp

```cpp

#include "boyerMooreSearch.h"
#include "knuthMorrisPrattSearch.h"


int main(){
    cout << "Какой способ сортировки:\n"
    << "1 - boyerMooreSearch\n"
    << "2 - knuthMorrisPrattSearch\n";
    int number;
    cin >> number;
    switch (number) {
        case 1:{
            boyerMooreSearch("aa3araatchukua.aa", "huku");
            break;
        }
        case 2:{
            knuthMorrisPrattSearch("aa3araatchukua.aa", "chuku");
            break;
        }
        default:{
            cout << "1 OR 2 -_-" << endl;
            break;
        }
    }
    return 0;
}

### boyerMooreSearch.h

```cpp
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

    int shiftTable[CHAR_NUM];

    calcCharTable(str, patSize, shiftTable);

    int shift = 0;

    while(shift <= (strSize - patSize))
    {
        int j = patSize - 1;
        while(j >= 0 && pat[j] == str[shift+j]) j--;

        if (j < 0)
        {
            cout << "Паттерн найден по индексу " << shift << endl;
            if (shift+patSize < strSize)
                shift += patSize - shiftTable[str[shift+patSize]];
            else shift++;
        }
        else shift += max(1, j - shiftTable[str[shift+j]]);
    }
}
```

### knuthMorrisPrattSearch.h

```cpp
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
``
