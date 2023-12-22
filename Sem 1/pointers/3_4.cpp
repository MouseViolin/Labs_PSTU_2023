
#include <iostream>


using namespace std;

int main(){
    
    int n, tmp, max, min;
    int *ptr=&tmp;
    

    cin >> n >> *ptr;
    max = *ptr;
    min = *ptr;

    for (int i = 1; i < n; i++)
    {
        cin >> *ptr;
        if (*ptr > max) { max = *ptr; }
        else if (*ptr < min) { min = *ptr; }
    }
    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
    
    return 0;
}
