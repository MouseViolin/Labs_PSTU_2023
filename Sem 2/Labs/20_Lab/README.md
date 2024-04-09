# Лабораторная работа №20
>[!IMPORTANT]
>Тема : "Классы и объекты. Использование конструкторов"
>Цель: Создание объектов с использованием конструкторов.

# Вариант №6
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Написать демонстрационную программу, в которой продемонстрировать все три случая вызова конструктора-копирования, вызов конструктора с параметрами и конструктора без параметров.
6. Пользовательский класс СТРАНА:
- Столица - string
- Количество жителей - int
- Площадь - double


# UML-диаграмма
О.о

# Код программы

```cpp
#include <iostream>

using namespace std;

class Country{
    string capital;
    int countPeoples;
    double area;
    
public:
    Country(){
        capital = "You";
        countPeoples = 'I';
        area = 0;
    }
    Country(string str, int cnt, double ar){
        capital = str;
        countPeoples = cnt;
        area = ar;
    }
    Country(const Country&NoName){
        capital = NoName.capital;
        countPeoples = NoName.countPeoples;
        area = NoName.area;
    }
    void showClass(){
        printf("Capital: %s, Size: %i, Area: %f\n", capital.c_str(), countPeoples, area);
    }
    
    string getCapital(){return capital;}
    int getSize(){return countPeoples;}
    double getArea(){return area;}
    void setCapital(string tmp){capital= tmp;}
    void setSize(int tmp){countPeoples = tmp;}
    void setArea(double tmp){area = tmp;}
    
    
    ~Country(){}
    
};



int main(){
    Country first;
    first.showClass();
    
    Country second("Jopa", 100, 1000);
    second.showClass();
    
    Country third = second;
    third.setCapital("Xyz");
    third.setSize(1);
    third.setArea(55.55);
    
    printf("Capital: %s, Size: %i, Area: %f\n", third.getCapital().c_str(),third.getSize(), third.getArea());
    
    
    
    
    
}



```

# Контрольные вопросы:


1. Для чего нужен конструктор? Сколько типов конструкторов существует в С++?

3. Для чего используется деструктор? В каких случаях деструктор описывается явно?

4. Для чего используется конструктор без параметров? Конструктор с параметрами? Конструктор копирования?

5. В каких случаях вызывается конструктор копирования?

6. Перечислить свойства конструкторов.

7. Перечислить свойства деструкторов.

8. К каким атрибутам имеют доступ методы класса?

9. Что представляет собой указатель this?

10. Какая разница между методами определенными внутри класса и вне класса?

11. Какое значение возвращает конструктор?

12. Какие методы создаются по умолчанию?

13. Какое значение возвращает деструктор?

14. Дано описание класса
...
20. ...
