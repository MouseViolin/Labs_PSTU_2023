
#include <iostream>

using namespace std;

int main(){
    int k, size, tmp, arr[5] = {1,2,3,4,5};
    cin >> k >> size ;

    for (k,tmp = arr[0] ; k > 0;  arr[size-1] = tmp, tmp = arr[0],k--)
        for (int i = 0; i < size-1; arr[i] = arr[i+1], i++);
    
    for (int t = 0; t < size; cout << arr[t] << " ", t++);
    cout << endl;
    return 0;
}
