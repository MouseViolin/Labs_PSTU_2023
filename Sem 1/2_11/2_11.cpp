#include <iostream>
using namespace std;

int main()
{
    bool a = false;
    int n,k;
    
    cin >> n;
    cin >> k;
    n--;
    if (k == 0) {
        while (k == 0 and n!=0) {
            cin >> k;
            if (k!=0) {
                if (k>0) {
                    a = true;
                    n--;
                }
                else{
                    n--;
                }
            }
            else{
                n--;
            }
        }
        if (n == 0 && k==0) {
            cout << "Все числа 0" << endl;
        }
        else{
            for (int i = 0; i < n; i++) {
                cin >> k;
            }
            
        }
    } 
    else {
        if (k>0) {
            a = true;
        }
    }
    if (a == true) {
        cout << "+" << endl;
    } else if (n!=0){
        cout << "-" << endl;
    }
    
    
    return 0;
}


