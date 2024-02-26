# Лабораторная работа №7.1

>[!IMPORTANT]
>Тема : "Перегрузка функций в С++"
>Цель: Знакомство с организацией перегруженных функций в
С++

# Блок-схема
![7_1_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/7eac4e8a-10a9-45b3-a9d4-59b1b4653d95)


# Вариант №6
Написать перегруженные функции и основную программу,
которая их вызывает.
1) для вычитания вещественных чисел;
2) для вычитания комплексных чисел.

# Код программы

```cpp
#include <iostream>
#include <complex>
using namespace std;

double sum(double a , double b){
    return a-b;
}

complex<double> sum(complex<double> a, complex<double> b){
    return a-b;
}


int main()
{
    complex< double > z1( 1.0, 2.0 );
    complex< double > z2( 2.0, 1.0 );
    double k1 = 4.5, k2 = 5.5;
    cout << sum(k1,k2) << endl;
    cout << sum(z1,z2) << endl;
    
    
}

```

# Лабораторная работа №7.2
>[!IMPORTANT]
>Тема : "Функции с переменным числом параметров"
>Цель: Знакомство с организацией функций с переменным числом параметров.

# Вариант №6
Написать функцию min с переменным числом параметров, которая находит минимальное из чисел типа int. Написать вызывающую функцию main, которая обращается к функции min не менее трех раз с количеством параметров 5, 10,12.

# Блок-схема
![7_2_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/409c60da-7a0f-43e5-a2ea-1ef5c15899ff)


# Код программы

```cpp
#include <iostream>

using namespace std;


int minn(int m, ...){
    int *p = &m +1;
    int min = *p;
    p+=2;
    for (; m > 1; m--) {
        if (*p < min) min = *p;
        p+=2;
    }
    
    return min;
}

int main()
{
    
    cout << minn(5, 4, 76, 1, 6, 8 ) << endl;
    cout << minn(10, 56, 43, 78, 23, 44, 56, 33, 12, 77, 89) << endl;
    cout << minn(12, 4, 76, 1, 6, 23, 44, 56, 33, 12, 23, 99, 0) << endl;
    
}



```

