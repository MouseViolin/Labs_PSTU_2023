#include <iostream>

using namespace std;

class LinearEquation{
    double first;
    double second;

public:
    void setEq(double a, double b){
        first = a;
        second = b;
        }
    void root(){
        if (first!=0) {
            cout << (-second)/first + 0.0 << endl;
        } else {
            cout << "Error" << endl;
        }
    }
};



int main(){
    linearEquation eq;
    eq.setEq(2, 5);
    eq.root();
    
}
