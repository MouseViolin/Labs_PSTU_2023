# Лабораторная работа №22
>[!IMPORTANT]
>Тема : "Простое наследование. Принципы подстановки"
>Цель: Создание иеархии классов с использованием простого наследования. Изучение принципа подстановки.

# Вариант №6
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
9. Реализовать функции, получающие и возвращающие объект базового класса. Продемонстрировать принцип подстановки.
10. Базовый класс: ПАРА_ЧИСЕЛ (PAIR)
- Первое_число (first) - int
- Второе_число (second) - int
- Определить методы изменения полей и операцию сложения пар (a,b)+(c,d)=(a+b,c+d)
- Создать производный класс ДЛИННОЕ _ЧИСЛО(LONG), с полями. Старшая часть числа и Младшая часть числа. Переопределить операцию сложения и определить операции вычитания и умножения.

# UML-диаграмма
![45e929d2b1e8842d5b4c81cfbcd47f9b](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/0d53394e-af63-41f2-954f-3fb7e227dd22)


# Код программы

## main.cpp

```cpp
#include <iostream>
#include "Pair.h"
#include "LongInt.h"

using namespace std;



int main(){
    Pair one(1,2);
    Pair one1(1,2);
    one = one+one1;
    cout << one << endl;
    LongInt two(1,2,3,4);
    LongInt three(1,2,3,4);
    LongInt th(1,1,1,1);


    two = two + three;
    two = two*th;
    cout << two << endl;
    
}

```

## Pair.h

```cpp
#pragma once
#include <iostream>

using namespace std;

class Pair{
protected:
    int first;
    int second;
    
public:
    Pair(){
        first = 0;
        second = 0;
    }
    Pair(int cnt, int ar){
        first = cnt;
        second = ar;
    }
    Pair(const Pair&NoName){
        first = NoName.first;
        second = NoName.second;
    }
    void showClass(){
        printf("Price: %i,%i\n", first, second);
    }
    
    int getFirst(){return first;}
    int getSecond(){return second;}
    void setFirst(int tmp){first = tmp;}
    void setSecond(int tmp){second = tmp;}
    
    reference_wrapper<Pair> operator+(const Pair&a){
        Pair tmp(this -> first, a.first);
        tmp.first += this -> second;
        tmp.second += a.second;
        return  reference_wrapper<Pair>(tmp);
    }

    Pair& operator=(Pair& a){
        this -> first = a.first;
        this -> second = a.second;
        return *this;
    }
    
    
    friend ostream& operator << (ostream& os,const Pair& a);
    friend istream& operator >> (istream& in, Pair& a);
    
    virtual ~Pair(){}
    
};

ostream& operator << (ostream& os,const Pair& a){
    os << "First: " << a.first;
    os << "\nSecond: " << a.second;
    return  os;
}
istream& operator >> (istream& in, Pair& a){
    cout << "First: "; in >> a.first;
    cout << "Second: "; in >> a.second;
    return in;
}

```

## LongInt.h

```cpp
#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class LongInt:public Pair{
protected:
    int bigHalf, litHalf;
    
public:
    LongInt():Pair(){
        bigHalf = 0;
        litHalf = 0;
    }
    LongInt(int cnt, int ar, int big, int lit):Pair(cnt, ar){
        bigHalf = big;
        litHalf = lit;
    }
    LongInt(const LongInt&NoName){
        first = NoName.first;
        second = NoName.second;
        bigHalf = NoName.bigHalf;
        litHalf = NoName.litHalf;
    }
    
    reference_wrapper<LongInt> operator+(const LongInt&a){
        LongInt tmp(this -> first, a.first,this -> bigHalf, a.bigHalf);
        tmp.first += this -> second;
        tmp.second += a.second;
        tmp.bigHalf += this -> litHalf;
        tmp.litHalf += a.litHalf;
        return  reference_wrapper<LongInt>(tmp);
    }
    
    reference_wrapper<LongInt> operator-(const LongInt&a){
        LongInt tmp(this -> first, a.first,this -> bigHalf, a.bigHalf);
        tmp.first -= this -> second;
        tmp.second -= a.second;
        tmp.bigHalf -= this -> litHalf;
        tmp.litHalf -= a.litHalf;
        return  reference_wrapper<LongInt>(tmp);
    }
    reference_wrapper<LongInt> operator*(const LongInt&a){
        LongInt tmp(this -> first, a.first,this -> bigHalf, a.bigHalf);
        tmp.first *= this -> second;
        tmp.second *= a.second;
        tmp.bigHalf *= this -> litHalf;
        tmp.litHalf *= a.litHalf;
        return  reference_wrapper<LongInt>(tmp);
    }
    
    LongInt& operator=(LongInt& a){
        this -> first = a.first;
        this -> second = a.second;
        this -> bigHalf = a.bigHalf;
        this -> litHalf = a.litHalf;
        return *this;
    }
    

    friend ostream& operator << (ostream& os,const LongInt& a);
    friend istream& operator >> (istream& in, LongInt& a);
    
    ~LongInt(){}
};

ostream& operator << (ostream& os,const LongInt& a){
    os << "First: " << a.first;
    os << "\nSecond: " << a.second;
    os << "\nBigHalf: " << a.bigHalf;
    os << "\nLitHalf: " << a.litHalf;
    return  os;
}
istream& operator >> (istream& in, LongInt& a){
    cout << "First: "; in >> a.first;
    cout << "Second: "; in >> a.second;
    cout << "BigHalf: "; in >> a.second;
    cout << "LitHalf: "; in >> a.second;
    return in;
}

```

# Контрольные вопросы:


1. Для чего используется механизм наследования?

2. Каким образом наследуются компоненты класса, описанные со спецификатором public?

3. Каким образом наследуются компоненты класса, описанные со спецификатором private?

4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?

5. Каким образом описывается производный класс?

6. Наследуются ли конструкторы?

7. Наследуются ли деструкторы?

8. В каком порядке конструируются объекты производных классов? В каком порядке уничтожаются объекты производных классов?

10. Что представляют собой виртуальные функции и механизм позднего связывания?

11. Могут ли быть виртуальными конструкторы? Деструкторы?

12. Наследуется ли спецификатор virtual?

13. Какое отношение устанавливает между классами открытое наследование?

14. Какое отношение устанавливает между классами закрытое наследование?

15. В чем заключается принцип подстановки?

16. Имеется иерархия классов:
...
20. ...
