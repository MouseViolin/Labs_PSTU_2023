#pragma once
#include <iostream>

using namespace std;

class Pair{
protected:
    int first;
    int second;
    
public:
    Pair(){
        first = 0;
        second = 0;
    }
    Pair(int cnt, int ar){
        first = cnt;
        second = ar;
    }
    Pair(const Pair&NoName){
        first = NoName.first;
        second = NoName.second;
    }
    void showClass(){
        printf("Price: %i,%i\n", first, second);
    }
    
    int getFirst(){return first;}
    int getSecond(){return second;}
    void setFirst(int tmp){first = tmp;}
    void setSecond(int tmp){second = tmp;}
    
    reference_wrapper<Pair> operator+(const Pair&a){
        Pair tmp(this -> first, a.first);
        tmp.first += this -> second;
        tmp.second += a.second;
        return  reference_wrapper<Pair>(tmp);
    }

    Pair& operator=(Pair& a){
        this -> first = a.first;
        this -> second = a.second;
        return *this;
    }
    
    
    friend ostream& operator << (ostream& os,const Pair& a);
    friend istream& operator >> (istream& in, Pair& a);
    
    virtual ~Pair(){}
    
};

ostream& operator << (ostream& os,const Pair& a){
    os << "First: " << a.first;
    os << "\nSecond: " << a.second;
    return  os;
}
istream& operator >> (istream& in, Pair& a){
    cout << "First: "; in >> a.first;
    cout << "Second: "; in >> a.second;
    return in;
}
