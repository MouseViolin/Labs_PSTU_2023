# Лабораторная работа №28
>[!IMPORTANT]
>Тема : "Сохранение данных в файле с использованием потоков"
>Цель: Разработка программы, в которой данные сохраняются в файле, корректируются и выводятся из файла на печать. Работа с файлом осуществляется с использованием потоковых классов.

# Вариант №6



1. Создать пользовательский класс с минимальной функциональностью.
2. Написать функцию для создания объектов пользовательского класса (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).
3. Написать функцию для чтения и просмотра объектов из потока.
4. Написать функцию для удаления объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
5. Написать функцию для добавления объектов в поток в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
6. Написать функцию для изменения объектов в потоке в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
7. Для вызова функций в основной программе предусмотреть меню.
8. 
>Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
> - сложение денежных сумм, вычитание денежных сумм,

>Задание:
> - Удалить все записи равные заданному значению.
> - Увеличить все записи с заданным значением на 1 рубль 50 копеек.
> - Добавить К записей после элемента с заданным номером.

# UML-диаграмма

![c052c7a93cb7946ff579d2b69560fee2](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/318ec7f4-d27b-4bca-8f82-991e182ed9b0)

# Код программы

## main.cpp

```cpp
#include "Money.h"
#include "fileWork.h"
#include <iostream>



using namespace std;



int main(){
    Money m;
    int k,c,num,count;
    char fName[30];
    do {
        printf("1. Make File\n2. Print File\n3.Delete Element\n4.Increase All Elemnts\n5.Additional Elements\n0. Exit\n");
        cin >> c;
        switch (c) {
            case 1:
                printf("File name: "); cin >> fName;
                k = fileMake(fName);
                if (k<0) printf("Can't make file");
                break;
            case 2:
                printf("File name: "); cin >> fName;
                k = printFile(fName);
                if (k==0) printf("Empty file\n");
                if (k<0) printf("Can't read file\n");
                break;
            case 3:
                printf("File name: "); cin >> fName;
                printf("Number: "); cin >> num;
                k = delElem(fName, num);
                if (k<0) printf("Can't make file");
                break;
            case 4:
                printf("File name: "); cin >> fName;
                k = increaseElemFile(fName);
                if (k<0) printf("Can't make file");
                break;
            case 5:
                printf("File name: "); cin >> fName;
                printf("Number: "); cin >> num;
                printf("Count: "); cin >> count;
                k = additionalElem(fName, num, count);
                if (k<0) printf("Can't make file");
                break;
        }
    } while (c != 0);
    
    
    
    return 0;
}



```

## Money.h

```cpp
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Money{
    long rub;
    int kopeck;
    
public:
    Money(){
        rub = 'I';
        kopeck = 0;
    }
    Money(long cnt, int ar){
        rub = cnt;
        kopeck = ar;
    }
    Money(const Money&NoName){
        rub = NoName.rub;
        kopeck = NoName.kopeck;
    }
    void showClass(){
        printf("Price: %li,%i\n", rub, kopeck);
    }
    
    long getRub(){return rub;}
    int getKopeck(){return kopeck;}
    void setRub(long tmp){rub = tmp;}
    void setKopeck(int tmp){kopeck = tmp;}
    
    Money& operator+(const Money&a){
        Money *tmp = new Money;
        tmp ->setRub(this -> rub); tmp -> setKopeck(this -> kopeck);
        tmp -> rub += a.rub;
        tmp ->kopeck += a.kopeck;
        return  *tmp;
    }
    Money& operator-(const Money&a){
        Money *tmp = new Money;
        tmp -> setRub(this -> rub); tmp -> setKopeck(this -> kopeck);
        tmp -> rub -= a.rub;
        tmp -> kopeck -= a.kopeck;
        return  *tmp;
    }
    Money& operator=(Money& a){
        this -> rub = a.rub;
        this -> kopeck = a.kopeck;
        return *this;
    }
    
    
    friend ostream& operator << (ostream& os,const Money& a);
    friend istream& operator >> (istream& in, Money& a);
    
    friend fstream& operator >> (fstream& fin, Money&a);
    friend fstream& operator << (fstream& fout, const Money&a);
    
    ~Money(){}
    
};

ostream& operator << (ostream& os,const Money& a){
    os << "Price: " << a.rub;
    os << "." << a.kopeck;
    return  os;
}
istream& operator >> (istream& in, Money& a){
    cout << "Rub: "; in >> a.rub;
    cout << "Kopeck: "; in >> a.kopeck;
    return in;
}

fstream& operator >> (fstream& fin, Money&a){
    fin >> a.rub;
    fin >> a.kopeck;
    return fin;
}

fstream& operator << (fstream& fout, const Money&a){
    fout << a.rub << '\n' << a.kopeck << endl;
    return fout;
}

```

## fileWork.h

```cpp
#pragma once

#include "Money.h"
#include <iostream>
#include <fstream>

using namespace std;

int fileMake(const char* fName){
    fstream stream(fName, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    Money tmp;
    cout << "quantity: "; cin >> n;
    for (int i(0); i < n; i++){
        cin >> tmp;
        stream << tmp << '\n' ;
    }
    stream.close();
    return n;
}

int printFile(const char* fName){
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    Money tmp; int i(0);
    while (stream >> tmp) {
        cout << tmp << '\n';
        i++;
    }
    stream.close();
    return i;
    
}

int delElem(const char* fName, int k){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m;
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        if (i != k) tmp << m;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}

int increaseElemFile(const char* fName){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m; Money a(1,50);
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        tmp << m+a;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}

int additionalElem(const char* fName,int k, int n){
    fstream tmp("tmp", ios::out);
    fstream stream(fName, ios::in);
    if (!stream) return -1;
    int i(0); Money m;
    while (stream>>m && i != k) {
        if (stream.eof()) break;
        i++;
        tmp << m;
    }
    for(; n!=0;n--) { 
        cin >> m;
        tmp << m << '\n' ;
    }
    while (stream>>m) {
        if (stream.eof()) break;
        i++;
        tmp << m;
    }
    stream.close(); tmp.close();
    remove(fName);
    rename("tmp", fName);
    return i;
}

```

# Контрольные вопросы:

1. Что такое поток?
2. Какие типы потоков существуют?
3. Какую библиотеку надо подключить при использовании стандартных потоков?
4. Какую библиотеку надо подключить при использовании файловых потоков?
5. Какую библиотеку надо подключить при использовании строковых потоков?
6. Какая операция используется при выводе в форматированный поток?
7. Какая операция используется при вводе из форматированных потоков?
8. Какие методы используются при выводе в форматированный поток?
9. Какие методы используется при вводе из форматированного потока?
10. Какие режимы для открытия файловых потоков существуют?
11. Какой режим используется для добавления записей в файл?
12. Какой режим (комбинация режимов) используется в конструкторе
ifstream file("f.txt")?
13. Какой режим (комбинация режимов) используется в конструкторе
fstream file("f.txt")?
14. Какой режим (комбинация режимов) используется в конструкторе
ofstream file("f.txt")?
15. Каким образом открывается поток в режиме ios::out|ios::app?
16. Каким образом открывается поток в режиме ios::out |ios:trunc?
17. Каким образом открывается поток в режиме ios:out ios: in|ios::trunk?. Каким образом можно открыть файл для чтения?
19. Каким образом можно открыть файл для записи?
20. Привести примеры открытия файловых потоков в различных режимах.
21. Привести примеры чтения объектов из потока.
22. Привести примеры записи объектов в поток.
23. Сформулировать алгоритм удаления записей из файла.
24. Сформулировать алгоритм добавления записей в файл.
25. Сформулировать алгоритм изменения записей в файле.
