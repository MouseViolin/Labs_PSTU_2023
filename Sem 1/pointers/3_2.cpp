
#include <iostream>


using namespace std;

int main(){
    
    int a = 10, b = 90;
    int *ptr_0 = &a, *ptr_1 = &b;
    
    *ptr_0 += *ptr_1;
    
    cout << a << endl;
//    Можно также сделать это в отдельную переменную
//    int sum;
//    sum = *ptr_0 + *ptr_1;
//    cout << sum << endl;
    
    return 0;
}
