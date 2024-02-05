
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n, p;
    bool flag = true;
    cin >> n;
    int array[n];
    int lb = 20, ub = 100;
    
    
    for (int j = 0; j < n; j++) {
        array[j] = (rand() % (ub - lb +1)) + lb;
        cout << array[j] << " " ;
    }
    p = array[0];
    for (int i = 1; i < n; i++) {
        if (p < array[i]) {
            p = array[i];
        }
        else{flag = false;}
    }
    if (flag) {
        cout << "+" << endl;
    } else {
        cout << "-" << endl;
    }
    return 0;
}
