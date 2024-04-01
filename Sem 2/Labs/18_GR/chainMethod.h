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
