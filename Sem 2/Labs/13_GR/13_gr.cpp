#include <iostream>

using namespace std;

void shellSort(int arr[], int n)
{
    for (int h = n/2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j = 0;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}

void showArr(int *arr , int size){
    for (int i(0); i < 6; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main(){
    int arr[6] = {35, 7, 60, 22, 1, 13};
    showArr(arr, 6);
    shellSort(arr, 6);
    showArr(arr, 6);
    
    return 0;
}
