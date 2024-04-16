#include "Set.h"
#include "Money.h"
#include <iostream>

using namespace std;



int main(){
    Money m;
    cout << "Money" << endl;
    cin >> m;
    cout << m;
    
    cout << "Set 1" << endl;
    Set<Money> A(m, 2);
    cin >> A;
    cout << A;
    
    cout << "Set 2" << endl;
    Set<Money> B(m, 3);
    cin >> B;
    cout << B;
    
    B = A;
    cout << "Set 3" << endl;
    cout << B;
    cout << "1(1)" << endl;
    cout << A[0] << endl;
    cout << "Size 3" << endl;
    cout << B() << endl;
    
    return 0;
}


