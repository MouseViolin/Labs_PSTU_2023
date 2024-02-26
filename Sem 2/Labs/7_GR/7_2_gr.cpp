#include <iostream>

using namespace std;


int minn(int m, ...){
    int *p = &m +1;
    int min = *p;
    p+=2;
    for (; m > 1; m--) {
        if (*p < min) min = *p;
        p+=2;
    }
    
    return min;
}

int main()
{
    
    cout << minn(5, 4, 76, 1, 6, 8 ) << endl;
    cout << minn(10, 56, 43, 78, 23, 44, 56, 33, 12, 77, 89) << endl;
    cout << minn(12, 4, 76, 1, 6, 23, 44, 56, 33, 12, 23, 99, 0) << endl;
    
}


