
#include <iostream>


using namespace std;

int main(){
    
    int a = 55;
    int b = 7;
    
    
    int *temp = new int(); // Уточнить, как точно происходит динамическое выделение памяти
    *temp = a;
    
    int *numb = &b;
    
    a = *numb;
    b = *temp;
    
    
    cout << a << endl;
    cout << b << endl;
    return 0;
}
