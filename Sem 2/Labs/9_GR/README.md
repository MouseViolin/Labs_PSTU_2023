# Лабораторная работа №9
>[!IMPORTANT]
>Тема : "Строковый ввод-вывод"
>Цель: Работа с текстовыми файлами, ввод-вывод текстовой информации и ее хранение на внешних носителях.

# Вариант №6
1. Скопировать из файла F1 в файл F2 строки, начиная с N до K.
2. Подсчитать количество согласных букв в файле F2.
# Блок-схема
![9_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/a9c94235-8e68-4c46-833c-9bf7641499ca)


# Код программы

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int check(string st){
    const char* pt = st.c_str();
    int cons = 0;
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if(tmp > 65 && tmp<123 && tmp !=69 && tmp !=73 && tmp !=79 && tmp !=85 && tmp !=89 && tmp !=97 && tmp !=101 && tmp !=105 && tmp !=111 && tmp !=117 && tmp !=121 )
            cons++;
        pt++;
    }
    return cons;
}

int main() {
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string str;
    int n,k, line = 1, sumCons = 0;
    cin >> n >> k;
    while (getline(F1, str) && line!=n-1) line++;
    while (getline(F1, str) && n!=k+1) {
        F2 << str << endl;
        cout << str << endl;
        sumCons += check(str);
        n++;
    }
    cout << sumCons << endl;
    F1.close();
    F2.close();
    
    return 0;
}


```
