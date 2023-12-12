
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    float a, max, n;
    int i = 2, cnt = 1;
    
    cin >> n ;
    max = round(sin(n + 1/n)*10)/10;
    
    while (i <= n) {
        a = sin(n+i/n);
        a = round(a*10)/10;
        if (a>max) {
            max = a;
            cnt = 1;
            }
        else if (a == max){
            cnt++;
        }
        i++;
    }
    cout << "max:" << max << ", cnt:" << cnt << endl;
    
    return 0;
}
