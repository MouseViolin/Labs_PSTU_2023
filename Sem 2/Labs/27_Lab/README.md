# Лабораторная работа №27
>[!IMPORTANT]
>Тема : "Обработка исключеных ситуаций"
>Цель: Разработка программы, обрабатывающей исключительные ситуации.

# Вариант №6
1. Реализовать класс, перегрузить для него операции, указанные в варианте.
2. Определить исключительные ситуации.
3. Предусмотреть генерацию исключительных ситуаций.
4. 
>Класс-контейнер МНОЖЕСТВО с элементами типа int. Реализовать операции:
> - `[]` - доступа по индексу;
> - `()` - определение размера множества; 
> - `+` - объединение множеств;
> - `++` - добавление элемента в множество

# UML-диаграмма

![Video conversion](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/9fa84181-619f-4180-9575-0b5769d2aa14)
# Код программы
 
## main.cpp

```cpp
#include "Set.h"
#include "error.h"
#include <iostream>


using namespace std;



int main(){
    try {
        Set one(3);
        one.add(4);
        one.add(5);
        one++;
        one++;  //Исключение №1 - попытка добавить элемент сверх размерности множества
        cout << one[-1] << endl; // Исключение №2.1 - попытка обратиться к отрицательному элементу множества. Формально можно просто реализовать обращение "с конца" на подобии python.
        cout << one[35] << endl; // Исключение №2.2 - попытка обратиться к элементу сверх размености множества
        Set th;
        th = one + 3; // Не вижу смысла прописывать исключения, тк программа не знает таких действий и произойдет просто присваивание, а "3" просто проигнорируется.
        cout << th;
//        Если поступают просто числа --> catch (int) можно просто прописать обработку каждого случая через switch
    } catch (Error &e) {
        e.what();
//        cout << "Error"<< endl;
    }
    return 0;
}



```

## Set.h

```cpp
#pragma once
#include "error.h"
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
        if (a<curIndx && a>=0) return body[a];
//        else throw 1;
        else throw IndexError();
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
    
    
    void operator++ (int){if (curIndx<size) {cout << '>';cin >> body[curIndx]; curIndx++;} /*else throw 2;*/ else throw OverSizeError();}
    
    
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

## error.h

```cpp
#pragma once
#include <iostream>
#include <string>


using namespace std;

class Error{public: virtual void what(){};};

class IndexError : public Error {
protected: string msg;
public:
    IndexError(){msg = "Index Error\n";}
    virtual void what(){cout << msg;}
};

class OverSizeError : public Error{
protected: string msg;
public:
    OverSizeError(){msg = "OverSize Error\n";}
    virtual void what(){cout << msg;}
};

```

# Контрольные вопросы:

1. Что представляет собой исключение в С++?
2. На какие части исключения позволяют разделить вычислительный процесс? Достоинства такого подхода?
3. Какой оператор используется для генерации исключительной ситуации?
4. Что представляет собой контролируемый блок? Для чего он нужен?
5. Что представляет собой секция-ловушка? Для чего она нужна?
6. Какие формы может иметь спецификация исключения в секции ловушке? В каких ситуациях используются эти формы?
7. Какой стандартный класс можно использовать для создания собственной иерархии исключений?
8. Каким образом можно создать собственную иерархию исключений?
9. Если спецификация исключений имеет вид: void fl (throw(int,double); то какие исключения может прождать функция f10?
10. Если спецификация исключений имеет вид: void f1()throw(); то какие исключения может прождать функция f10?
11. В какой части программы может генерироваться исключение?
12. Написать функцию, которая вычисляет площадь треугольника по трем сторонам (формула Герона).
- Функцию реализовать в 4 вариантах:
- без спецификации исключений; со спецификацией throw);
- с конкретной спецификацией с подходящим стандартным исключением; спецификация с собственным реализованным исключением.
