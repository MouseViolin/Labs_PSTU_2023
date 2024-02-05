
#include <iostream>

using namespace std;

int main()
{
    int n, tmp, p, q;
    
    n = 11;
    p = 2;
    q = 6;  //или через cin
    
    int arr[11] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (p < q)
    {
        tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;
        p++;
        q--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
