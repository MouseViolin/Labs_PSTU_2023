#include <iostream>
using namespace std;

int main()
{
    int n,k, max_first = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k > max_first) {
            max_first = k;
        }
    }
    cout << max_first << endl;
    return 0;
}



