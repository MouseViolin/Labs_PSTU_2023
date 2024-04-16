# Лабораторная работа №25
>[!IMPORTANT]
>Тема : "Щаблоны классов"
>Цель: Реализация шаблона класса-контейнера

# Вариант №6

1. Определить шаблон класса-контейнера (см. лабораторную работу Nº6).
Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.
3. Перегрузить операции, указанные в варианте.
4. Инстанцировать шаблон для стандартных типов данных (int, float, double).
5. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы стандартных типов данных.
6. Реализовать пользовательский класс (см. лабораторную работу Nº3).
7. Перегрузить для пользовательского класса операции ввода-вывода.
8. Перегрузить операции необходимые для выполнения операций контейнерного класса.
9. Инстанцировать шаблон для пользовательского класса.
10. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы пользовательского класса.
11.
>Класс-контейнер МНОЖЕСТВО с элементами типа int. Реализовать операции:
> - `[]` - доступа по индексу;
> - `()` - определение размера множества; 
> - `+` - объединение множеств;
> - Пользовательский класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа `long` для рублей и типа `int` для копеек.Дробная часть числа при выводе на экран должна быть отделена от целой части запятой.

# UML-диаграмма

<img src="https://media1.tenor.com/m/hcKIwOSXPfcAAAAC/ecenaztrip1.gif" width="690" height="624.0666666666667" />

# Код программы

## main.cpp

```cpp
#include "Set.h"
#include "Money.h"
#include <iostream>

using namespace std;



int main(){
    Money m;
    cout << "Money" << endl;
    cin >> m;
    cout << m;
    
    cout << "Set 1" << endl;
    Set<Money> A(m, 2);
    cin >> A;
    cout << A;
    
    cout << "Set 2" << endl;
    Set<Money> B(m, 3);
    cin >> B;
    cout << B;
    
    B = A;
    cout << "Set 3" << endl;
    cout << B;
    cout << "1(1)" << endl;
    cout << A[0] << endl;
    cout << "Size 3" << endl;
    cout << B() << endl;
    
    return 0;
}

```

## Money.h

```cpp
#pragma once
#include <iostream>

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

```

## Set.h

```cpp
#pragma once
#include <iostream>


using namespace std;




template <class Type>
class Set{
    Type* body;
    int size;
    int curIndx;
    int carriage;
    
public:
    Set(){ body = 0; size = 0; curIndx = 0; carriage = 0;};
    Set(Type k, int n){body = new Type[n]; curIndx = 0; size = n; carriage = 0;};
    
    void add(Type p){
        int tmp = 0;
        if (curIndx < size) for (; tmp < curIndx && body[tmp] != p; tmp++);
        if (tmp == curIndx) body[curIndx++] = p;
            
    };
    
    Type operator[](int a){
        if (a<curIndx) return body[a];
        else {
            cout << "Error, carriage < curIndx"<< endl;
            return body[a];
        }
    }
    int operator[](){return body[carriage];}
    int operator()(){return size;}
    
    Set& operator+ (const Set&a){
        Set *tmp = new Set;
        tmp -> size = this -> curIndx + a.curIndx;
        tmp -> body = new int[tmp -> size];
        for (int i(0); i < this -> curIndx; i++) tmp -> add(this -> body[i]);
        for (int i(0); i < a.curIndx; i++) tmp -> add(a.body[i]);
        
        return *tmp;
    }
    void operator++ (int){if (carriage<size) carriage++;}
    
    
    template <class T>
    friend ostream& operator << (ostream& out,const Set<T>&);
    template <class T>
    friend istream& operator >> (istream& in, Set<T>& a);
    ~Set(){if (body!=0 &&
               (typeid(body) == typeid(int)  ||
                typeid(body) == typeid(float) ||
                typeid(body) == typeid(double) )) delete [] body; body = 0;};
    
};

template <class T>
ostream& operator <<(ostream& out, const Set<T>& s){
    if (s.size ==0) out << "Empty" << endl;
    for (int i(0); i<s.curIndx; i++) out << s.body[i];
    out << endl;
    return out;
};
template <class T>
istream& operator >> (istream& in, Set<T>& a){
    for (int i(0); i < a.size; i++) {cin >> a.body[a.curIndx]; a.curIndx++;}
    return in;
}

```



# Контрольные вопросы:

1. В чем смысл использования шаблонов?
2. Каковы синтаксис/семантика шаблонов функций?
3. Каковы синтаксис/семантика шаблонов классов?
4. Что такое параметры шаблона функции?
5. Перечислите основные свойства параметров шаблона функции.
6. Как записывать параметр шаблона?
7. Можно ли перегружать параметризованные функции?
8. Перечислите основные свойства параметризованных классов.
9. Все ли компонентные функции параметризованного класса являются параметризованными?
10. Являются ли дружественные функции, описанные в параметризованном классе, параметризованными?
11. Могут ли шаблоны классов содержать виртуальные компонентные функции?
12. Как определяются компонентные функции параметризованных классов вне определения шаблона класса?
13. Что такое инстанцирование шаблона?
14. На каком этапе происходит генерирование определения класса по шаблону?
