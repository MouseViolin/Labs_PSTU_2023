#include "Pair.h"
#include "LongInt.h"
#include "Vector.h"
#include <iostream>

using namespace std;



int main(){
    Vector v(5);
    Pair one;
    cin >> one;
    LongInt two;
    cin >> two;
    
    v.add(&one);
    v.add(&two);
    
    cout << v;
    
    return 0;
}

