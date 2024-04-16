# Лабораторная работа №24
>[!IMPORTANT]
>Тема : "АТД. Контейнеры"
>Цель: Реализация класса контейнера.

# Вариант №6
1. Определить класс-контейнер.
2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.
3. Перегрузить операции, указанные в варианте.
4. Реализовать класс-итератор. Реализовать с его помощью операции последовательного доступа.
5. Написать тестирующую программу, иллюстрирующую выполнение операций.
6.
>Класс- контейнер МНОЖЕСТВО с элементами типа int. Реализовать операции:
> - `[]` - доступа по индексу;
> - `()` - определение размера множества;
> - `+`  объединение множеств;
> - `++` - переход к следующему элементу ( с помощью класса-итератора).

# UML-диаграмма

<img src="https://media1.tenor.com/m/5BYK-WS0__gAAAAd/cool-fun.gif" width="690" height="1223.03317535545"/>

# Код программы

## main.cpp

```cpp
#include "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/24_Lab/Set.h"
#include <iostream>

using namespace std;



int main(){
    Set one(5);
    one.add(9);
    one.add(9);
    one.add(4);
    one.add(3);
    one.add(0);
    Set two(5);
    two.add(1);
    two.add(9);
    two.add(4);
    two.add(90);
    two.add(0);
    cout << one;
    one++;
    cout << one[] << endl;
    Set th;
    th = one + two;
    cout << th;
    return 0;
}
```

## Set.h

```cpp
#pragma once
#include <iostream>


using namespace std;

class Set{
    int* body;
    int size;
    int curIndx;
    int carriage;
    
public:
    Set(){ body = 0; size = 0; curIndx = 0; carriage = 0;};
    Set(int n){body = new int[n]; curIndx = 0; size = n; carriage = 0;};
    Set(Set&a){
        delete [] body;
        size = a.size;
        curIndx = a.curIndx;
        carriage = 0;
        body = new int[size];
        for (int i(0); i < size; i++) body[i] = a.body[i];
    };
    void add(int p){
        int tmp = 0;
        if (curIndx < size) for (; tmp < curIndx && body[tmp] != p; tmp++);
        if (tmp == curIndx) body[curIndx++] = p;
            
    };
    
    int operator[](int a){
        if (a<curIndx) return body[a];
        else {
            cout << "Error, carriage < curIndx"<< endl;
            return NULL;
        }
    }
    int operator[](){return body[carriage];}
    
    Set& operator+ (const Set&a){
        Set *tmp = new Set;
        tmp -> size = this -> curIndx + a.curIndx;
        tmp -> body = new int[tmp -> size];
        for (int i(0); i < this -> curIndx; i++) tmp -> add(this -> body[i]);
        for (int i(0); i < a.curIndx; i++) tmp -> add(a.body[i]);
        
        return *tmp;
    }
    
    
    void operator++ (int){if (carriage<size) carriage++;}
    
    
//    Set& operator=(const int* a){
//        this -> carriage = 0;
//        return *this;
//    }
    
    
    friend ostream& operator <<(ostream& out,const Set&);
    friend istream& operator >> (istream& in, Set& a);
    
    ~Set(){if (body!=0) delete [] body; body = 0;};
    
    
};

ostream& operator <<(ostream& out, const Set& s){
    if (s.size ==0) out << "Empty" << endl;
    for (int i(0); i<s.curIndx; i++) out << s.body[i] << ' ';
    out << endl;
    return out;
};
istream& operator >> (istream& in, Set& a){
    for (int i(0); i < a.size; i++) {cin >> a.body[i]; a.curIndx++;}
    return in;
}

```



# Контрольные вопросы:
1. Что такое абстрактный тип данных? Привести примеры АТД.
2. Привести примеры абстракции через параметризацию.
3. Привести примеры абстракции через спецификацию.
4. Что такое контейнер? Привести примеры.
5. Какие группы операций выделяют в контейнерах?
6. Какие виды доступа к элементам контейнера существуют? Привести примеры.
7. Что такое итератор?
8. Каким образом может быть реализован итератор?
9. Каким образом можно организовать объединение контейнеров?
10. Какой доступ к элементам предоставляет контейнер, состоящий из элементов «ключ-значение»?
11. Как называется контейнер, в котором вставка и удаление элементов выполняется на одном конце контейнера?
12. Какой из объектов (a,b,c,d) является контейнером?
    a. int mas=10;
    b. 2. int mas;
    c. 3. struct {char name[30]; int age;} mas;
    d. 4. int mas[100];
13. Какой из объектов (a,b,c,d) не является контейнером?
    a. int a[]={1,2,3,4,5};
    b. 2. int mas[30];
    c. 3. struct {char name[30]; int age;} mas[30];
    d. 4. int mas;
14. Контейнер реализован как динамический массив, в нем определена операция доступ по индексу. Каким будет доступ к элементам контейнера?
15. Контейнер реализован как линейный список. Каким будет доступ к элементам контейнера?
