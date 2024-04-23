#pragma once
#include "Money.h"

#include <vector>
#include <iostream>



using namespace std;

typedef vector<Money> MVector;

MVector makeVector(int cnt){
    Money a;
    MVector m;
    for (int i(0); i<cnt; i++) {
        cin >> a;
        m.push_back(a);
    }
    return m;
}

void show(MVector& a){
    for (int i(0); i < a.size(); i++) cout << a[i] << endl;
    cout << endl;
}

void maxInStart(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    for (int i(1); i < a.size(); i++)
        if (tmp.getRub() + tmp.getKopeck()/100 < a[i].getRub() + a[i].getKopeck()/100)
            tmp = a[i];
    
    MVector one;
    one.push_back(tmp);
    for (int i(0); i < a.size(); i++){
        one.push_back(a[i]);
    }
    a.clear();
    for (int i(0); i < one.size(); i++){
        a.push_back(one[i]);
    }
}

void deleteMin(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    int pos = 0;
    for (int i(1); i < a.size(); i++)
        if (tmp.getRub() + tmp.getKopeck()/100 > a[i].getRub() + a[i].getKopeck()/100)
        {tmp = a[i]; pos = i;}
    
    MVector one;
    for (int i(pos+1); i < a.size(); i++) one.push_back(a[i]);
    for (int i(pos), size = a.size(); i < size; i++) a.pop_back();
    for (int i(0); i < one.size(); i++) a.push_back(one[i]);
    
}

void meanArith(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    for (int i(1); i < a.size(); i++) tmp = tmp+a[i];
    tmp.setRub(tmp.getRub()/a.size());
    tmp.setKopeck(tmp.getKopeck()/a.size());
    for (int i(0); i < a.size(); i++) a[i] = a[i] + tmp;
}
