# Лабораторная работа №10
>[!IMPORTANT]
>Тема : "Динамические массивы"
>Цель:  Организация динамических массивов.

# Вариант №6
1. Сформировать двумерный массив. Удалить из него строку с заданным номером
# Блок-схема
<img src="https://i.giphy.com/wofyg8nxsWEmtR7eOK.webp" width="180" height="150"/>
# Код программы
```cpp
#include <iostream>
#include <ctime>

using namespace std;

int ** makeArr(int n)
{
    int **matr;
    int i,j;
    matr=new int*[n];
    for (i=0;i<n;i++)
    {
        matr[i]=new int[n];
        for (j=0;j<n;j++)
            matr[i][j]=rand()%8 + 11;
    }
    return matr;
}

void showArr(int **ptr, int k, int v){
    for (int i(0); i < k; cout<<endl, i++) for (int j(0); j< v; j++) cout << ptr[i][j] << ' ';
}

void shiftArr(int **ptr, int k, int n){
    for (int i(n); i<k-1; i++) {
        ptr[i] = ptr[i+1];
    }
}
void freeArr(int **ptr, int n){
    for (int i(0); i<n; i++) {
        delete ptr[i];
        
    }
    delete [] ptr;
}

int main(){
    srand((unsigned int)time(0));
    int k, n;
    
    cin >> k;
    int **ptr = makeArr(k);
    showArr(ptr, k,k);
    
    cin >> n;
    delete ptr[n];
    shiftArr(ptr, k, n);
    showArr(ptr, k-1 , k);
    freeArr(ptr, k-1);
    return 0;
    
}

```
