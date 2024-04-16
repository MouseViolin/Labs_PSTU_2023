# Лабораторная работа №23
>[!IMPORTANT]
>Тема : "Наследование. Вирутальные функции. Полифорфизм"
>Цель: Изучение полиморфизма и виртуальных функций.

# Вариант №6

1. Определить абстрактный класс.
2. Определить иерархию классов, в основе которой будет находиться абстрактный класс (см. лабораторную работу Nº4).
3.Определить класс Вектор, элементами которого будут указатели на объекты иерархии классов.
4. Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5. В основной функции продемонстрировать перегруженные операции и полиморфизм Вектора.
6.
>Базовый класс:
> - ПАРА_ЧИСЕЛ ($PAIR$)
> - Первое _число ($first$) - int
> - Второе_число ($second$) - int
> - Определить методы изменения полей и операцию сложения пар `$(a,b) +(c,d)=(a+b,c+d)$`
> - Создать производный класс $ДЛИННОЕ_ЧИСЛО(LONG)$, с полями $Старшая часть_числа$ и $Младшая_ часть числа$.
> - Переопределить операцию сложения и определить операции вычитания и умножения.

# UML-диаграмма

<img src="https://media1.tenor.com/m/I79LXz-U-mwAAAAC/excited-kitten-kitty.gif" width="690" height="981.7714285714286"/>


# Код программы

## main.cpp

```cpp
#include "Pair.h"
#include "LongInt.h"
#include "Vector.h"
#include <iostream>

using namespace std;



int main(){
    Vector v(5);
    Pair one;
    cin >> one;
    LongInt two;
    cin >> two;
    
    v.add(&one);
    v.add(&two);
    
    cout << v;
    
    return 0;
}


```

## Pair.h

```cpp

#pragma once
#include <iostream>

using namespace std;

class Object{
public:
    Object(){};
    ~Object(){};
    virtual void Show() = 0;
};

class Pair : public Object{
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
    void Show(){cout << '1' << endl;};
    
    Pair& operator+(const Pair&a){
        Pair *tmp = new Pair;
        tmp -> setFirst(this -> first); tmp -> setSecond(a.first);
        tmp -> first += this -> second;
        tmp -> second += a.second;
        return  *tmp;
    }

    Pair& operator=(Pair& a){
        this -> first = a.first;
        this -> second = a.second;
        return *this;
    }
    
    
    friend ostream& operator << (ostream& os,const Pair& a);
    friend istream& operator >> (istream& in, Pair& a);
    
    virtual ~Pair(){};
    
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
    void Show(){cout << '2' << endl;};
    
    LongInt& operator+(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second =a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf =a.bigHalf;
        tmp -> first += this -> second;
        tmp -> second += a.second;
        tmp -> bigHalf += this -> litHalf;
        tmp -> litHalf += a.litHalf;
        return  *tmp;
    }
    
    LongInt& operator-(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second =a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf =a.bigHalf;
        tmp -> first -= this -> second;
        tmp -> second -= a.second;
        tmp -> bigHalf -= this -> litHalf;
        tmp -> litHalf -= a.litHalf;
        return  *tmp;
    }
    LongInt& operator*(const LongInt&a){
        LongInt *tmp = new LongInt;
        tmp -> first = this -> first;
        tmp -> second = a.first;
        tmp -> bigHalf = this -> bigHalf;
        tmp -> litHalf = a.bigHalf;
  
        tmp->first *= this -> second;
        tmp->second *= a.second;
        tmp->bigHalf *= this -> litHalf;
        tmp->litHalf *= a.litHalf;
        return  *tmp;
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

## Vector.h

```cpp
#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class Vector{
    Object ** head;
    int size;
    int curIndx;
    
public:
    Vector(){ head = 0; size = 0; curIndx = 0;};
    Vector(int n){head = new Object*[n]; curIndx = 0; size = n;};
    
    void add(Object *p){if (curIndx < size) head[curIndx++] = p;};
    
    friend ostream& operator <<(ostream& out,const Vector&);
    
    ~Vector(){if (head!=0) delete [] head; head = 0;};
    
};

ostream& operator <<(ostream& out, const Vector& v){
    if (v.size ==0) out << "Empty" << endl;
    Object **p = v.head;
    for (int i(0); i<v.curIndx; i++) (*p++) -> Show();
    return out;
};

```

# Контрольные вопросы:

1. Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?
2. Какой класс называется абстрактным?
3. Для чего предназначены абстрактные классы?
4. Что такое полиморфные функции?
5. Чем полиморфизм отличается от принципа подстановки?
6. Привести примеры иерархий с использованием абстрактных классов.
7.Привести примеры полиморфных функций.В каких случаях используется механизм позднего связывания?
