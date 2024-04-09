#include <iostream>
#include "Pair.h"
#include "LongInt.h"

using namespace std;



int main(){
    Pair one(1,2);
    Pair one1(1,2);
    one = one+one1;
    cout << one << endl;
    LongInt two(1,2,3,4);
    LongInt three(1,2,3,4);
    LongInt th(1,1,1,1);


    two = two + three;
    two = two*th;
    cout << two << endl;
    
    
    
    
    
    
    
    
}

