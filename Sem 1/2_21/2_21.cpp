
#include <iostream>

using namespace std;

int main()
{
    
    bool flag_up = true;
    int n, up = 0;
    
    cin >> n ;
    up = n;
    
    while (n!=0) {
        cin >> n;
        
        if (n > up) {
            up = n;
        } else if (n!= 0){
            flag_up = false;
        }
        
    }
    
    if (up ==0) {
        cout << "0" << endl;
    }else {
        if (flag_up) {
            cout << "virare" << endl;
        } else {
            cout << "maina" << endl;
        }
    }
    
    return 0;
}
