
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float y = 0, x, f =1;
    cin >>  x >>  n;
    y = 1 + x ;
    for (int i = 2; i <= n; i++) {
          f *= i;
          y += (pow(x, i))/f;
        
    }
    cout << y << endl;
    return 0;
}
