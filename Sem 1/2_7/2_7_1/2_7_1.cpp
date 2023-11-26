#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int stars = pow(n, 0.5);
    for (int i = 0; i < stars; i++)
    {
        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
