#pragma once
#include <iostream>


using namespace std;




template <class Type>
class Set{
    Type* body;
    int size;
    int curIndx;
    int carriage;
    
public:
    Set(){ body = 0; size = 0; curIndx = 0; carriage = 0;};
    Set(Type k, int n){body = new Type[n]; curIndx = 0; size = n; carriage = 0;};
    
    void add(Type p){
        int tmp = 0;
        if (curIndx < size) for (; tmp < curIndx && body[tmp] != p; tmp++);
        if (tmp == curIndx) body[curIndx++] = p;
            
    };
    
    Type operator[](int a){
        if (a<curIndx) return body[a];
        else {
            cout << "Error, carriage < curIndx"<< endl;
            return body[a];
        }
    }
    int operator[](){return body[carriage];}
    int operator()(){return size;}
    
    Set& operator+ (const Set&a){
        Set *tmp = new Set;
        tmp -> size = this -> curIndx + a.curIndx;
        tmp -> body = new int[tmp -> size];
        for (int i(0); i < this -> curIndx; i++) tmp -> add(this -> body[i]);
        for (int i(0); i < a.curIndx; i++) tmp -> add(a.body[i]);
        
        return *tmp;
    }
    void operator++ (int){if (carriage<size) carriage++;}
    
    
    template <class T>
    friend ostream& operator << (ostream& out,const Set<T>&);
    template <class T>
    friend istream& operator >> (istream& in, Set<T>& a);
    ~Set(){if (body!=0 &&
               (typeid(body) == typeid(int)  ||
                typeid(body) == typeid(float) ||
                typeid(body) == typeid(double) )) delete [] body; body = 0;};
    
};

template <class T>
ostream& operator <<(ostream& out, const Set<T>& s){
    if (s.size ==0) out << "Empty" << endl;
    for (int i(0); i<s.curIndx; i++) out << s.body[i];
    out << endl;
    return out;
};
template <class T>
istream& operator >> (istream& in, Set<T>& a){
    for (int i(0); i < a.size; i++) {cin >> a.body[a.curIndx]; a.curIndx++;}
    return in;
}
