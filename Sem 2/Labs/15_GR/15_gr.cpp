#include "nuturalSort.h"
#include "splitFile.h"

#include <stdio.h>
#include <iostream>

using namespace std;

void showArr(int *arr, int size){
    for (int i(0); i < 6; ++i) cout << arr[i];
    cout << endl;
}

int main()
{
    int arr[6]{1,3,2,-1,4,-9};
    int countArr[6]{}; //2 1 2 1 0 0
    
    splitFile(arr, sizeof(arr)/sizeof(arr[0]), countArr);
    showArr(arr, 6);
    sortNutural(countArr, arr);
    showArr(arr, 6);
    
    return 0;
}
