
# Лабораторная работа №6
>[!IMPORTANT]
>Тема : "Hash-таблицы"
>Цель: Работа с hash-таблицами, разбор алгоритмов разрешение коллизий и их реализация.

# Вариант №6
- openAddressing
- chainMetod

# Блок-схема
О.о

# Код программы

### main.cpp

```cpp
#include "chainMethod.h"
#include "openAddressing.h"

#include <iostream>
#include <string>

using namespace std;


int main(){
    cout << "Какой способ сортировки:\n"
    << "1 - open addressing\n"
    << "2 - the chain method\n";
    int number;
    cin >> number;
    switch (number) {
        case 1:{
            hashTableOpAdr* people = new hashTableOpAdr;
            people -> setHashTable(100);
            people -> showTable();
            break;
        }
        case 2:{
            hashTableChain* people = new hashTableChain;
            people -> setHashTable(100);
            people -> showTable();
            break;
        }
        default:{
            cout << "1 OR 2 -_-" << endl;
            break;
        }
    }
    
}
```

### hashGen.h

```cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;


// H(k)= [M (kAmod1)], 0<A<1, mod1 – получение дробной части, [] – получение целой части
int hashGen(int size, string str){
    unsigned int key = 0;
    for (int i(0); i < str.size(); key+=str[i], i++);
    return  static_cast<int>(key*0.2)%size;
}

```

### openAddressing.h

```cpp

#pragma once

#include "hashGen.h"

#include <iostream>
#include <string>

using namespace std;



struct nodeTableOpAdr{
    string fullName{" "};
    string numberPasport{" "};
    string adress{" "};
};

struct hashTableOpAdr{
    const int sizeTable = 45;
    nodeTableOpAdr* table = new nodeTableOpAdr[sizeTable];
    void setTable(string fullName, string numberPasport, string adress){
        int hash = hashGen(sizeTable,adress);
        while (table[hash%(sizeTable)].adress != " ") if (++hash - sizeTable == sizeTable) break;
        if (hash - sizeTable < sizeTable) {
            table[hash%sizeTable].fullName = fullName;
            table[hash%sizeTable].numberPasport = numberPasport;
            table[hash%sizeTable].adress = adress;
        }
        
    }
    void showTable(){
        for (int i(0); i < sizeTable; i++){
            printf("[%s]{%s} ", table[i].fullName.c_str(), table[i].adress.c_str());
            cout << endl;
        }
    }


    void setHashTable(int cnt){
        auto randStr = [](){
            string str;
            static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
            for (int i(0); i < rand()%8 + 3; i++) str += absd[rand()%26];
            return str;
        };
        
        auto randNumber = [](){
            string numPh = "7";
            for (int i = 0; i < 10; i++) numPh += rand() % 10 + 0x30;
            return numPh; };
        
        for (int i(0); i < cnt; i++)
            setTable(randStr(), randNumber(), randStr());
        
        
    }
};
```

### chainMethod.h

```cpp
#pragma once

#include "hashGen.h"

#include <iostream>
#include <string>

using namespace std;



struct nodeTableChain{
    string fullName{' '};
    string numberPasport{' '};
    string adress{' '};
    nodeTableChain* next = nullptr;
    nodeTableChain* prev = nullptr;
    int size = 0;
};

struct hashTableChain{
    const int sizeTable = 45;
    nodeTableChain* table = new nodeTableChain[sizeTable];
    void setTable(string fullName, string numberPasport, string adress){
        int hash = hashGen(sizeTable,adress);
        if (table[hash].adress != " ") {
            nodeTableChain* newNode = new nodeTableChain;
            newNode -> fullName = fullName;
            newNode -> numberPasport = numberPasport;
            newNode -> adress = adress;
            nodeTableChain *tmp = &table[hash];
            for (int i(0); i < table[hash].size-1; i++) tmp = tmp->next;
            tmp -> next = newNode;
            newNode -> prev = tmp;
            table[hash].size++;
        }else {
            table[hash].fullName = fullName;
            table[hash].numberPasport = numberPasport;
            table[hash].adress = adress;
            table[hash].size++;
        }
        
    }
    
    void showTable(){
        for (int i(0); i < sizeTable; i++) {
            if (table[i].size == 0) continue;
            else {
                nodeTableChain *tmp = &table[i];
                for (int j(0); j <= table[i].size && tmp != nullptr; j++) {
                    printf("[%s]{%s} ", tmp -> fullName.c_str(), tmp -> adress.c_str());
                    tmp = tmp -> next;
                }
                cout << endl;
            }
        }
    }
    void setHashTable(int cnt){
        auto randStr = [](){
            string str;
            static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
            for (int i(0); i < rand()%8 + 3; i++) str += absd[rand()%26];
            return str;
        };
        
        auto randNumber = [](){
            string numPh = "7";
            for (int i = 0; i < 10; i++) numPh += rand() % 10 + 0x30;
            return numPh; };
        
        for (int i(0); i < cnt; i++)
            setTable(randStr(), randNumber(), randStr());
        
        
    }
};
```
