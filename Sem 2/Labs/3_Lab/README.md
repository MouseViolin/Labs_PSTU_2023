# Лабораторная работа №3
>[!IMPORTANT]
>Тема : "Работа с рекурсией"
>Цель: Получение навыков использования рекурсии.

# Вариант №6
1. Сумма членов ряда $$S = 1 +\frac{cos(\frac{π}{4})}{1!}x + ... + \frac{cos(n\frac{π}{4})}{n!}x^n$$
2. Числа Фибоначчи (функция, принимающая n, где n — порядковый номер нужного числа Фибоначчи)
3. Ханойские башни
4. Задача о расстановке 8 ферзей

# Блок-схемы
1.
![3_1_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/7155314f-7335-4c72-97b3-962639ff1091)

2. 
![3_2_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/e70fc594-2931-427a-97ad-c86add727607)

3. 
![3_3_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/0858ddae-46a7-4a83-bdb2-830460cc69dd)

4.
![3_4 gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/395070cf-2ab7-4dc3-8d0b-c726145b1d1c)


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
4.
```cpp
#include <iostream>

using namespace std;

bool oneIteration = 1;
int board[8][8]; // Выделение памяти под массив, который будет представлять собой шахматную доску
 
// Вывод доски.
void showBoard()
{
    for(int a = 0; a < 8; ++a){
        for(int b = 0; b < 8; ++b) cout << ((board[a][b]) ? "Q " : ". ");
        cout << endl;
    }
}
 
// Функция проверяет нет ли уже установленных ферзей по вертикали и диагоналям.
// Каждая проверка идет до поступаемой строки, тк заполнение доски происходит сврху вниз и нам не интересно, что находиться снизу
bool tryQueen(int a, int b)
{
//    Проверка происходит, благодаря фиксации столбца и перебору строк
    for(int i = 0; i < a; ++i)
    {
        if(board[i][b])
        {
            return false;
        }
    }
//    Проверка левой верхней диагонали
    for(int i = 1; i <= a && b-i >= 0; ++i)
    {
        if(board[a-i][b-i])
        {
            return false;
        }
    }
//    Проверка правой верхней диагонали
    for(int i = 1; i <= a && b+i < 8; i++)
    {
        if(board[a-i][b+i])
        {
            return false;
        }
    }
    
    return true;
}
 
// Функция пробует найти результаты решений, проверяя строку (а), в которую можно поставить ферзя
void setQueen(int a)
{
//    При проходе всех строк выводим результат, тк расчет доски происходит рекурсивно,
//    чтобы вывести только первый вариант используем флаг.
    if(a == 8 && oneIteration)
    {
        showBoard();
        oneIteration = 0;
    }
    
    for(int i = 0; i < 8; ++i)
    {
//          Проверяем возможность поставить в board ферзя (единицу),
//          Будет ли единственным в этой строке, столбце и диагоналях.
        if(tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a+1);
            board[a][i] = 0;
        }
        
        
    }
}
int main()
{
//    Ручная постановка ферзя в board[i][j] и запуск алгоритма с 0-й строки - setQueen(0)
    int i, j;
    std::cin >> i >> j;
    board[i][j] = 1;
    setQueen(0);
    
    return 0;
}
```
