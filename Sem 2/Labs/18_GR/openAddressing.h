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
