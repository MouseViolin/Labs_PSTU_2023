
#include <iostream>
using namespace std;

int main()
{
    int n, s = 0;
    bool flag = false;
    
    
    cin >> n;
    
    for (int i = 1; i <=n; i++) {
        if (!flag) {
            s += -1*i;
            flag = true;
        } else {
            s += i;
            flag = false;
        }
    }
        
    cout << s << endl;
    
    return 0;
}
