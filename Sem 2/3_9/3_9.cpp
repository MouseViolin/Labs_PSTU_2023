#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n;
    cin >> n;
    int array[100];
    int lb = 20, ub = 100;
    
    for (int j = 0; j < n; j++) {
        array[j] = (rand() % (ub - lb +1)) + lb;
        cout << array[j] << " " ;
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        if (array[i]%2 != 0) {
            for (int j = i; j < n-1; j++) {
                array[j] = array[j+1];
            }
            i--;
            n--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
