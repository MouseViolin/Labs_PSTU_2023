
#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class LongInt:public Pair{
protected:
    int bigHalf, litHalf;
    
public:
    
    LongInt():Pair(){
        bigHalf = 0;
        litHalf = 0;
    }
    LongInt(int cnt, int ar, int big, int lit):Pair(cnt, ar){
        bigHalf = big;
        litHalf = lit;
    }
    LongInt(const LongInt&NoName){
        first = NoName.first;
        second = NoName.second;
        bigHalf = NoName.bigHalf;
        litHalf = NoName.litHalf;
    }
    void Show(){cout << '2' << endl;};
    
    LongInt& operator+(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second =a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf =a.bigHalf;
        tmp -> first += this -> second;
        tmp -> second += a.second;
        tmp -> bigHalf += this -> litHalf;
        tmp -> litHalf += a.litHalf;
        return  *tmp;
    }
    
    LongInt& operator-(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second =a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf =a.bigHalf;
        tmp -> first -= this -> second;
        tmp -> second -= a.second;
        tmp -> bigHalf -= this -> litHalf;
        tmp -> litHalf -= a.litHalf;
        return  *tmp;
    }
    LongInt& operator*(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second = a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf = a.bigHalf;
  
        tmp->first *= this -> second;
        tmp->second *= a.second;
        tmp->bigHalf *= this -> litHalf;
        tmp->litHalf *= a.litHalf;
        return  *tmp;
    }
    
    LongInt& operator=(LongInt& a){
        this -> first = a.first;
        this -> second = a.second;
        this -> bigHalf = a.bigHalf;
        this -> litHalf = a.litHalf;
        return *this;
    }
    

    friend ostream& operator << (ostream& os,const LongInt& a);
    friend istream& operator >> (istream& in, LongInt& a);
    
    ~LongInt(){}
};

ostream& operator << (ostream& os,const LongInt& a){
    os << "First: " << a.first;
    os << "\nSecond: " << a.second;
    os << "\nBigHalf: " << a.bigHalf;
    os << "\nLitHalf: " << a.litHalf;
    return  os;
}
istream& operator >> (istream& in, LongInt& a){
    cout << "First: "; in >> a.first;
    cout << "Second: "; in >> a.second;
    cout << "BigHalf: "; in >> a.second;
    cout << "LitHalf: "; in >> a.second;
    return in;
}
