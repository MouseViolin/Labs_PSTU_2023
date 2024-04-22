#pragma once

#include "Money.h"
#include <iostream>
#include <fstream>

using namespace std;

int fileMake(const char* fName){
    fstream stream(fName, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    Money tmp;
    cout << "quantity: "; cin >> n;
    for (int i(0); i < n; i++){
        cin >> tmp;
        stream << tmp << '\n' ;
    }
    stream.close();
    return n;
}

int printFile(const char* fName){
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    Money tmp; int i(0);
    while (stream >> tmp) {
        cout << tmp << '\n';
        i++;
    }
    stream.close();
    return i;
    
}

int delElem(const char* fName, int k){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m;
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        if (i != k) tmp << m;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}

int increaseElemFile(const char* fName){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m; Money a(1,50);
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        tmp << m+a;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}

int additionalElem(const char* fName,int k, int n){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m;
    while (stream>>m && i != k) {
        if (stream.eof()) break;
        i++;
        tmp << m;
    }
    for(; n!=0;n--) { 
        cin >> m;
        tmp << m << '\n' ;
    }
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        tmp << m;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}
