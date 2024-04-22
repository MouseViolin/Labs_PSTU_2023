#pragma once
#include "error.h"
#include <iostream>



using namespace std;

class Set{
    int* body;
    int size;
    int curIndx;
    int carriage;
    
public:
    Set(){ body = 0; size = 0; curIndx = 0; carriage = 0;};
    Set(int n){body = new int[n]; curIndx = 0; size = n; carriage = 0;};
    Set(Set&a){
        delete [] body;
        size = a.size;
        curIndx = a.curIndx;
        carriage = 0;
        body = new int[size];
        for (int i(0); i < size; i++) body[i] = a.body[i];
    };
    void add(int p){
        int tmp = 0;
        if (curIndx < size) for (; tmp < curIndx && body[tmp] != p; tmp++);
        if (tmp == curIndx) body[curIndx++] = p;
            
    };
    
    int operator[](int a){
        if (a<curIndx && a>=0) return body[a];
//        else throw 1;
        else throw IndexError();
    }
    int operator[](){return body[carriage];}
    
    Set& operator+ (const Set&a){
        Set *tmp = new Set;
        tmp -> size = this -> curIndx + a.curIndx;
        tmp -> body = new int[tmp -> size];
        for (int i(0); i < this -> curIndx; i++) tmp -> add(this -> body[i]);
        for (int i(0); i < a.curIndx; i++) tmp -> add(a.body[i]);
        
        return *tmp;
    }
    
    
    void operator++ (int){if (curIndx<size) {cout << '>';cin >> body[curIndx]; curIndx++;} /*else throw 2;*/ else throw OverSizeError();}
    
    
    friend ostream& operator <<(ostream& out,const Set&);
    friend istream& operator >> (istream& in, Set& a);
    
    ~Set(){if (body!=0) delete [] body; body = 0;};
    
    
};

ostream& operator <<(ostream& out, const Set& s){
    if (s.size ==0) out << "Empty" << endl;
    for (int i(0); i<s.curIndx; i++) out << s.body[i] << ' ';
    out << endl;
    return out;
};
istream& operator >> (istream& in, Set& a){
    for (int i(0); i < a.size; i++) {cin >> a.body[i]; a.curIndx++;}
    return in;
}
