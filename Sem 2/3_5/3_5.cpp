
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n, max;
    cin >> n;
    int array[n];
    int lb = 20, ub = 100;
    
    
    for (int j = 0; j < n; j++) {
        array[j] = (rand() % (ub - lb +1)) + lb;
        cout << array[j] << " " ;
    }
    cout << endl ;
    max = array[0];
    for (int i = 1; i <n; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    
    cout << max ;
    return 0;
}
