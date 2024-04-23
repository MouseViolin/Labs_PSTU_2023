#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Money{
protected:
    long rub;
    int kopeck;
    
public:
    Money(){
        rub = 'I';
        kopeck = 0;
    }
    Money(long cnt, int ar){
        rub = cnt;
        kopeck = ar;
    }
    Money(const Money&NoName){
        rub = NoName.rub;
        kopeck = NoName.kopeck;
    }
    void showClass(){
        printf("Price: %li,%i\n", rub, kopeck);
    }
    
    long getRub(){return rub;}
    int getKopeck(){return kopeck;}
    void setRub(long tmp){rub = tmp;}
    void setKopeck(int tmp){kopeck = tmp;}
    
    Money& operator+(const Money&a){
        Money *tmp = new Money;
        tmp ->setRub(this -> rub); tmp -> setKopeck(this -> kopeck);
        tmp -> rub += a.rub;
        tmp ->kopeck += a.kopeck;
        return  *tmp;
    }
    Money& operator-(const Money&a){
        Money *tmp = new Money;
        tmp -> setRub(this -> rub); tmp -> setKopeck(this -> kopeck);
        tmp -> rub -= a.rub;
        tmp -> kopeck -= a.kopeck;
        return  *tmp;
    }
    Money& operator=(Money& a){
        this -> rub = a.rub;
        this -> kopeck = a.kopeck;
        return *this;
    }
    
    bool operator==(Money&a){
        if (rub == a.rub && kopeck == a.kopeck) return 1;
        else return 0;
    }
    
    friend ostream& operator << (ostream& os,const Money& a);
    friend istream& operator >> (istream& in, Money& a);
    
    friend fstream& operator >> (fstream& fin, Money&a);
    friend fstream& operator << (fstream& fout, const Money&a);
    
    ~Money(){}
    
};

ostream& operator << (ostream& os,const Money& a){
    os << "Price: " << a.rub;
    os << "." << a.kopeck;
    return  os;
}
istream& operator >> (istream& in, Money& a){
    cout << "Rub: "; in >> a.rub;
    cout << "Kopeck: "; in >> a.kopeck;
    return in;
}

fstream& operator >> (fstream& fin, Money&a){
    fin >> a.rub;
    fin >> a.kopeck;
    return fin;
}

fstream& operator << (fstream& fout, const Money&a){
    fout << a.rub << '\n' << a.kopeck << endl;
    return fout;
}

