
#include <iostream>
using namespace std;

int main()
{
    float max = 0, min = 0;
    int n, k;
    
    cin >> n;
    cin >> k;
    max = k;
    min = k;
    for (int i = 1; i < n; i++) {
        cin >> k;
        if (k > max) {
            max = k;
        } else if (k < min) {
            min = k;
        }
    }
    cout << max + min << endl;
    return 0;
}
