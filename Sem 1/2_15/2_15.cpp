
#include <iostream>
using namespace std;

int main()
{
    int n, s;
    bool flag = false;
    
    
    cin >> n;
    cin >> s;
    
    while (!flag and n!=0) {
        if (s == n%10 ) {
            flag = true;
            cout << "+" << endl;
        } else {
            n /= 10;
        }
        
    }
    if (!flag) {
        cout << "-" << endl;
    }
    return 0;
}
