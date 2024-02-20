# Лабораторная работа №3
>[!IMPORTANT]
>Тема : "Работа с рекурсией"
>Цель: Получение навыков использования рекурсии.

# Вариант №6
1. Сумма членов ряда $$S = 1 +\frac{cos(\frac{π}{4})}{1!}x + ... + \frac{cos(n\frac{π}{4})}{n!}x^n$$
2. Числа Фибоначчи (функция, принимающая n, где n — порядковый номер нужного числа Фибоначчи)
3. Ханойские башни
4. Задача о расстановке 8 ферзей

# Блок-схема
О.о
# Код программ

1.
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int fact(double n){
    if (n <= 1) return 1;
    else return n * fact(n-1);
}

double sum(double n, double x){
    const double PI = 3.141592653589793;
    if (n == 0) return 1;
    else return  ((cos((n*PI/4))/fact(n)) * pow(x, n)) + sum(n-1, x);
}

int main(){
    double n, x, k = 0;
    cin >> n >> x;
    cout <<  sum(n , x) << endl;
}
```

2.
```cpp
#include <iostream>

using namespace std;

int fib(int n){
    if (n <= 1) return n;
    else return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; cout << fib(i) ,i++);
    
}
```

3.
```cpp
void hanoi_towers(int cnt_disk, int i, int k){
    if (cnt_disk ==  1)
        printf("Move disk 1 from pin %d to %d \n" , i , k);
    else {
        int tmp = 6 - i - k;
        hanoi_towers(cnt_disk-1, i, tmp);
        printf("Move disk %d from pin %d to %d \n" , cnt_disk, i , k);
        hanoi_towers(cnt_disk-1, tmp, k);
    }
}

int main()
{
    int cnt_disk, i, k;
    cin >> cnt_disk >> i >> k;
    hanoi_towers(cnt_disk, i, k);
    
}
```

