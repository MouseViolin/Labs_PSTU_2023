
# Лабораторная работа №16
>[!IMPORTANT]
>Тема : "Методы поиcка"
>Цель: Работа с алгоритмами: линейный, интерполяционный, бинарный, разбор алгоритмов и их реализация.

# Вариант №6
- linearSearch
- binarySearch
- InterpolationSearch

# Блок-схема
О.о

# Код программы

```cpp
#include <iostream>

using namespace std;

void InterpolationSearch(int key, int *arr, int leftIndx, int rightIndx){
    int midIndx = leftIndx + ((key - arr[leftIndx])*(rightIndx-leftIndx))/(arr[rightIndx] - arr[leftIndx]);
    if (arr[midIndx] == key) {cout << midIndx << endl; return;}
    if (arr[midIndx+1] <= key) InterpolationSearch(key, arr, midIndx+1, rightIndx);
    else InterpolationSearch(key, arr, leftIndx, midIndx-1);
}

void binarySearch(int key, int *arr, int leftIndx, int rightIndx){
    int midIndx = (rightIndx+leftIndx)/2;
    if (arr[midIndx] == key) {cout << midIndx << endl; return;}
    if (arr[midIndx+1]<=key) binarySearch(key, arr, midIndx+1, rightIndx);
    else binarySearch(key, arr, leftIndx, midIndx-1);
}


void linearSearch(int key, int *arr, int size){
    for (int i(0); i < size; i++) if (arr[i] == key) { cout << i << endl; break;}
}

void binarySearch(int key, int *arr , int size){
    binarySearch(key, arr, 0, size - 1);
}

void InterpolationSearch(int key, int *arr , int size){
    InterpolationSearch(key, arr, 0, size-1);
}


int main()
{
    int arr[6]{1,2,3,4,5,6};
    linearSearch(1, arr, 6);
    binarySearch(3, arr, 6);
    InterpolationSearch(6, arr, 6);
    return 0;
}
``
