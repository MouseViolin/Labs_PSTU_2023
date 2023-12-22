
#include <iostream>


using namespace std;

int main(){
    
    float a = 1.650, b = 1.90;
    float *ptr_0 = &a, *ptr_1 = &b;
    
    *ptr_0 += *ptr_1;
    
    cout << a << endl;
//    Можно также сделать это в отдельную переменную
//    float sum;
//    sum = *ptr_0 + *ptr_1;
//    cout << sum << endl;
    
    return 0;
}
