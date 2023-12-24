
#include <iostream>

using namespace std;

int main()
{
    int n;
    int k = 0;

    cin >> n;

    while (n > 0)
    {
        k = k*10 + n % 10;
        n /= 10;
    }
    cout << k << endl;
    return 0;
}
