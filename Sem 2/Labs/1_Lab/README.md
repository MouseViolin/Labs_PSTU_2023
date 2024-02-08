
# Лабораторная работа №1
>[!IMPORTANT]
>Тема : "Работа с двумерными массивами"
>Цель: Получение навыков обработки двумерных массивов.

# Вариант №О.о
Заполнить массив, если сумма номера строки и номера столбца - нечетное число, то такой элемент = 0. Все остальные элементы заполняются от 1-9 по порядку(последовательно, пропуская те элементы, которые заняты нулями)

# Блок-схема
О.о


# Код программы

```cpp

#include <iostream>
using namespace std;

int main() {

    int str_arr,col_arr, k = 0, num[9] = {1,2,3,4,5,6,7,8,9};
    cin >> str_arr >> col_arr;
    int array[str_arr][col_arr];
    
    int *ptr0 = &array[0][1];
    int *ptr1 = &array[0][0];
    
    
    for (int i = 0; i < (str_arr*col_arr); i+=2) {
        *ptr1 = num[k%9];
        k++;
        ptr1 +=2;
        *ptr0 = 0;
        ptr0 += 2;
    }
    
    for (int i = 0; i < str_arr; cout << endl, i++)
        for (int j = 0; j < col_arr;cout << array[i][j] << " ", j++);
    
    
    return 0;
}

```
