#include "Set.h"
#include <iostream>

using namespace std;



int main(){
    Set one(5);
    one.add(9);
    one.add(9);
    one.add(4);
    one.add(3);
    one.add(0);
    Set two(5);
    two.add(1);
    two.add(9);
    two.add(4);
    two.add(90);
    two.add(0);
    cout << one;
    one++;
    cout << one[] << endl;
    Set th;
    th = one + two;
    cout << th;
    return 0;
}

