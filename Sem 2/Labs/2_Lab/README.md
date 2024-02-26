
# Лабораторная работа №2
>[!IMPORTANT]
>Тема : "Работа с двумерными массивами"
>Цель: Получение навыков обработки двумерных массивов.

# Вариант №О.о
Все элементы выше главной диагонали = 0. Элементы стоящие на главной диагонали и на параллельно заполнены одинаковыми числами

# Блок-схема
![2_Lab](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/82839047-157d-4375-b8fd-cfdcfeb89c32)



# Код программы

```cpp
#include <iostream>

using namespace std;

int main() {
    
    int str_arr,col_arr,cnt;
    cin >> str_arr >> col_arr >> cnt;
    int array[str_arr][col_arr];
    
    int num[cnt];
    for (int i = 0; i < cnt; i++) {
        num[i] = i+1;
    }
    
    for (int i = 0; i<str_arr; i++) {
        for (int j = 0; j < col_arr; j++) {
            array[i][j] = 0;
        }
    }
    
    for (int i = 0, k = 0; i<str_arr; k++, i++) {
        for (int n = 0; n < col_arr - k; n++) {
            array[i+n][n] = num[k%cnt] ;
        }
    }
    for (int i = 0; i < str_arr; cout << endl, i++)
            for (int j = 0; j < col_arr;cout << array[i][j] << " ", j++);
    
    return 0;
}

```
