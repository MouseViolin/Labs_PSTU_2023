# Лабораторная работа №26
>[!IMPORTANT]
>Тема : "Программа управляемая событиями"
>Цель: Разработка программы управляемой событиями.

# Вариант №6


1. Определить иерархию пользовательских классов (см. лабораторную работу Nº5).Во главе иерархии должен стоять абстрактный класс с чисто виртуальными методами для ввода и вывода информации об атрибутах объектов.
2. Реализовать конструкторы, деструктор, операцию присваивания, селекторы и модификаторы.
3. Определить класс-группу на основе структуры, указанной в варианте.
4. Для группы реализовать конструкторы, деструктор, методы для добавления и удаления элементов в грушу, метод для просмотра группы, перегрузить операцию для получения информации о размере группы.
5. Определить класс Диалог - наследника группы, в котором реализовать методы для обработки событий.
6. Добавить методы для обработки событий групой и объектами пользовательских
классов.
7. Написать тестирующую программу.
8. Нарисовать диаграмму классов и диаграмму объектов.
9. 
>Базовый класс:
>> - ЧЕЛОВЕК (Person)
>> - Имя - string
>> - Возраст - int

>Производный класс
>> - СТУДЕНТ (Student)
>> - Рейтинг - float
>> - Группа - Список (List).

>Команды:
>> - Создать группу (формат команды: `m` количество элементов группы).
>> - Добавить элемент в группу (формат команды: `+`)
>> - Удалить элемент из группы (формат команды `-`)
>> - Вывести информацию об элементах группы (формат команды: `s`)
>> - Вывести информацию об элементе группы (формат команды :`? номер объекта в группе`)
>> - Конец работы (формат команды: `q`)


# UML-диаграмма

<img src="https://media1.tenor.com/m/KjyDoVIomkcAAAAd/social-credit-social-credit-score.gif" width="690" height="387.9518072289157"/>

# Код программы

## main.cpp

```cpp

#include "Person.h"
#include "Student.h"
#include "List.h"
#include "Dialog.h"

#include <iostream>

using namespace std;



int main(){
    Dialog d;
    d.execute();
    
    return 0;
}
```

## Person.h

```cpp
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Object{
public:
    Object(){};
    virtual void Show() = 0;
    virtual void Input() = 0;
    
    ~Object(){};
};

class Person : public Object{
protected:
    string name;
    int age;
public:
    Person(){name = ""; age = 0;};
    Person(string a, int b){name = a; age = b;};
    Person(Person&a){name = a.name; age = a.age;};
    
    string getName(){return name;};
    int getAge(){return age;};
    void setName(string a){name = a;};
    void setAge(int a){age = a;};
    
    Person& operator= (Person&a){
        if (&a == this) return *this;
        name = a.name;
        age = a.age;
        return *this;
    };
    
    
    void Show(){cout << name << ' ' << age<< endl;};
    void Input(){cout << "Name: "; cin >> name;
                 cout << "Age: "; cin >> age;};
    virtual ~Person(){};
};


```

## Student.h

```cpp
#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class Student : public Person{
protected:
    float socRating;
public:
    Student(): Person(){};
    Student(string a, int b, float c):Person(a,b){socRating = c;};
    Student(const Student&a){name = a.name; age = a.age; socRating = a.socRating;};
    
    float getRating(){return socRating;};
    void setRating(float a){socRating = a;};
    
    
    void Show(){cout << "Name: " << name << ' ' << "Age: "<< age<< ' '<< "Social Rating: " << socRating<< endl;};
    void Input(){
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Social Rating: "; cin >> socRating;};
    
    ~Student(){};
};

```

## List.h

```cpp
#pragma once
#include <string>
#include <iostream>

using namespace std;

class List{
protected:
    Object * data;
    List * prev;
    List * next;
    int size;
public:
    List(){data = nullptr; prev = nullptr; next = nullptr; size = 0;};
    
    void pushBackNode(Object *dat){
        if (data == nullptr) data = dat;
        else {
            List *newNode = new List;
            newNode->data = dat;
            if (next != nullptr){
                List *tmp = next;
                for (; tmp -> next!= nullptr;) tmp = tmp -> next;
                newNode->prev = tmp;
                tmp -> next = newNode;
                tmp = nullptr;
            } else if (next == nullptr){
                next = newNode;
                newNode->prev = this;
            }
        }
        size++;
    }
    void delNode(int a){
        List *tmp = new List;
        tmp = this;
        for (int i(1); i < a; i++) tmp = tmp -> next;
        List *pr, *nx;
        pr = tmp -> prev;
        nx = tmp -> next;
        if (pr == nullptr){
            next = nx;
            nx -> prev = pr;
            size--;
        }
        if (nx == nullptr){
            pr -> next = nx;
            size--;
        }
        delete tmp;
    };
    void Showw(){
        if (data != nullptr){
            data -> Show();
            List *tmp = new List;
            tmp = next;
            for (; tmp != nullptr;) {
                tmp -> data -> Show();
                tmp = tmp -> next;
            }
            delete tmp;
        } else cout << "Empty" << endl;
        
    }
    void ShowOne(int a){
        List *tmp = new List;
        tmp = this;
        for (int i(1); i < a; i++) tmp = tmp -> next;
        tmp -> data -> Show();
        tmp = nullptr;
        delete tmp;
    }
    
    
    ~List(){data = 0; prev = 0; next = 0;};
};

```

## Dialog.h

```cpp
#pragma once
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent{
    int what;
    union {
        int command;
        struct {
            int message;
            int parametr;
        };
    };
};

class Dialog : public List{
protected:
    int EndState;
public:
    Dialog(){EndState = 0;};
    virtual ~Dialog(){};
    virtual void getEvent(TEvent&event){
        string opInt = "m+-s?q";
        string s;
        string param;
        
        char code;
        cout << '>'; cin >> s;  code = s[0];
        if (opInt.find(code) >= 0) {
            event.what = evMessage;
            switch (code) {
                case 'm': event.command = cmMake;break;
                case '+': event.command = cmAdd; break;
                case '-': event.command = cmDel; break;
                case 's': event.command = cmShow; break;
                case '?': event.command = cmGet; break;
                case 'q': event.command = cmQuit; break;
            }
            if (s.length()>1){
                param = s.substr(1,s.length()-1);
                int A = atoi(param.c_str());
                event.parametr = A;
            }
        }else event.message = evNothing;
    };
    virtual int execute(){
        TEvent event;
        do {
            EndState = 0;
            getEvent(event);
            handleEvent(event);
        } while (!valid());
        return EndState;
    };
    
    virtual void handleEvent(TEvent&event){
        if (event.what == evMessage){
            switch (event.command) {
                case cmAdd:{
                    Student *data = new Student;
                    data -> Input();
                    pushBackNode(data);
                    clearEvent(event);
                    break;
                }
                case cmDel: delNode(event.parametr); size--; break;
                case cmGet: ShowOne(event.parametr);clearEvent(event); break;
                case cmShow: Showw(); clearEvent(event); break;
                case cmQuit: endExec(); clearEvent(event); break;
            }
        }
    };
    virtual void clearEvent(TEvent&event){
        event.what = evNothing;
    };
    int valid(){
        if (EndState == 0) return 0;
        else return 1;
    };
    void endExec(){EndState = 1;}
};


```

# Контрольные вопросы:


1. Что такое класс-группа? Привести примеры таких классов.
2. Привести пример описания класса-группы Список (List).
3. Привести пример конструктора (с параметром, без параметров, копирования) для класса-группы Список.
4. Привести пример деструктора для класса-группы Список.
5. Привести пример метода для просмотра элементов для класса-группы Список.
6. Какой вид иерархии дает группа?
7. Почему во главе иерархии классов, содержащихся в груше объектов должен находиться абстрактный класс?
8. Что такое событие? Для чего используются события?
9. Какие характеристики должно иметь событие-сообщение?
10. Привести пример структуры, описывающей событие.
11. Задана структура события
...

14. Какие методы необходимы для организации обработки сообщений?
15. Какой вид имеет главный цикл обработки событий-сообщений?
16. Какую функцию выполняет метод ClearEvent? Каким образом?
17. Какую функцию выполняет метод HandleEvent (?Каким образом?
18. Какую функцию выполняет метод GetEvent (?
19. Для чего используется поле EndState? Какой класс (объект) содержит это поле?
20. Для чего используется функция Valid?
