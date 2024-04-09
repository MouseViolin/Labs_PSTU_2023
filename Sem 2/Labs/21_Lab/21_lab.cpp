#include <iostream>

using namespace std;

class Money{
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
    
    reference_wrapper<Money> operator+(const Money&a){
        Money tmp(this -> rub, this -> kopeck);
        tmp.rub += a.rub;
        tmp.kopeck += a.kopeck;
        return  reference_wrapper<Money>(tmp);
    }
    reference_wrapper<Money> operator-(const Money&a){
        Money tmp(this -> rub, this -> kopeck);
        tmp.rub -= a.rub;
        tmp.kopeck -= a.kopeck;
        return  reference_wrapper<Money>(tmp);
    }
    Money& operator=(Money& a){
        this -> rub = a.rub;
        this -> kopeck = a.kopeck;
        return *this;
    }
    
    
    friend ostream& operator << (ostream& os,const Money& a);
    friend istream& operator >> (istream& in, Money& a);
    
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


int main(){
    Money first;
    Money second;
    Money third;
    
    cin >> first;
    cin >> second;
    
    cout << first << endl;
    
    third = first + second;
    
    cout << third << endl;
    
}
