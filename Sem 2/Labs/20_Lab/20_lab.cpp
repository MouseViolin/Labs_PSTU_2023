#include <iostream>

using namespace std;

class Country{
    string capital;
    int countPeoples;
    double area;
    
public:
    Country(){
        capital = "You";
        countPeoples = 'I';
        area = 0;
    }
    Country(string str, int cnt, double ar){
        capital = str;
        countPeoples = cnt;
        area = ar;
    }
    Country(const Country&NoName){
        capital = NoName.capital;
        countPeoples = NoName.countPeoples;
        area = NoName.area;
    }
    void showClass(){
        printf("Capital: %s, Size: %i, Area: %f\n", capital.c_str(), countPeoples, area);
    }
    
    string getCapital(){return capital;}
    int getSize(){return countPeoples;}
    double getArea(){return area;}
    void setCapital(string tmp){capital= tmp;}
    void setSize(int tmp){countPeoples = tmp;}
    void setArea(double tmp){area = tmp;}
    
    
    ~Country(){}
    
};



int main(){
    Country first;
    first.showClass();
    
    Country second("Jopa", 100, 1000);
    second.showClass();
    
    Country third = second;
    third.setCapital("Xyz");
    third.setSize(1);
    third.setArea(55.55);
    
    printf("Capital: %s, Size: %i, Area: %f\n", third.getCapital().c_str(),third.getSize(), third.getArea());
    
    
    
    
    
}


