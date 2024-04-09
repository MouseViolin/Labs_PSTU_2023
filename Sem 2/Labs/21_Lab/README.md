# Лабораторная работа №21
>[!IMPORTANT]
>Тема : "Перегрузка операций"
>Цель: Использование перегруженных операций в классах.

# Вариант №6

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Перегрузить операции указанные в варианте.
8. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
9.Создать класс Money для работы с денежными суммами. Число должно бытьпредставлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
- сложение денежных сумм,
- вычитание денежных сумм.


# UML-диаграмма
О.о

# Код программы

```cpp
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
    
    reference_wrapper<Money> operator+(const Money&a){
        Money tmp(this -> rub, this -> kopeck);
        tmp.rub += a.rub;
        tmp.kopeck += a.kopeck;
        return  reference_wrapper<Money>(tmp);
    }
    reference_wrapper<Money> operator-(const Money&a){
        Money tmp(this -> rub, this -> kopeck);
        tmp.rub -= a.rub;
        tmp.kopeck -= a.kopeck;
        return  reference_wrapper<Money>(tmp);
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


int main(){
    Money first;
    Money second;
    Money third;
    
    cin >> first;
    cin >> second;
    
    cout << first << endl;
    
    third = first + second;
    
    cout << third << endl;
    
}


```

# Контрольные вопросы:


1. Для чего используются дружественные функции и классы?

2. Сформулировать правила описания и особенности дружественных функций.

3. Каким образом можно перегрузить унарные операции?

4. Сколько операндов должна иметь унарная функция-операция, определяемая внутри класса?

5. Сколько операндов должна иметь унарная функция-операция, определяемая вне класса?

6. Сколько операндов должна иметь бинарная функция-операция, определяемая внутри класса?

7. Сколько операндов должна иметь бинарная функция-операция, определяемая вне класса?

8. Чем отличается перегрузка префиксных и постфиксных унарных операций?

9. Каким образом можно перегрузить операцию присваивания?

10. Что должна возвращать операция присваивания?

11. Каким образом можно перегрузить операции ввода-вывода?

12. В программе описан класс:
...
15. ...
