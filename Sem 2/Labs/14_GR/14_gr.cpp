#include <iostream>

using namespace std;

int partition(int arr[], int lowIndx, int highIndx)
{
    int pivot = arr[lowIndx];
    int num = 0;

    for (int i = lowIndx+1; i <= highIndx; i++)
        if (arr[i] < pivot) num++;
    

    int posIndx = lowIndx + num;

    swap(arr[posIndx], arr[lowIndx]);

    int i = lowIndx, j = highIndx;
    while (i < posIndx && j > posIndx)
    {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;

        if (i < posIndx && j > posIndx)
            swap(arr[i++], arr[j--]);
    }
    return posIndx;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pI = partition(arr, low, high);
    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);
}

void showArr(int *arr , int size){
    for (int i(0); i < 6; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main(){
    int arr[6] = {35, 7, 60, 22, 1, 13};
    showArr(arr, 6);
    quickSort(arr, 0, 5);
    showArr(arr, 6);
    
    return 0;
}
