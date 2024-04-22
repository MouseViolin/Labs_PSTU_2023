
# Лабораторная работа №11
>[!IMPORTANT]
>Тема : "Информационные динамические структуры"
>Цель: Знакомство с динамическими информационными структурами на примере одно- и двунаправленных списков.

# Вариант №6
Записи в линейном списке содержат ключевое поле типа int. Сформировать двунаправленный список. Удалить из него элемент с заданным номером, добавить элемент в начало списка.

# Блок-схема

<img src="https://i.giphy.com/wofyg8nxsWEmtR7eOK.webp" width="180" height="150"/>


# НедоБлок-Схемы

## oneWayList.h

![Диаграмма без названия-11 1_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/4a2a96d9-5501-45cb-838d-beb32428be21)

## bidirectionalList.h

![Диаграмма без названия-11 2_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/bbdb6863-5b3b-41cf-a268-c8a94471eb05)

## stack.h

![Диаграмма без названия 11 3](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/7a549f23-9570-4f34-9c2e-fb744c63c681)

## queue.h

![Диаграмма без названия-11 4_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/175c6406-570b-46f0-860e-1b21a1bd73d1)


# Код программы

```cpp
#include "oneWayList.h"
#include "bidirectionalList.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <ctime>

using namespace std;


int main(){
    //OneWayList
    srand((unsigned int)time(0));
    int sizeList, delElIndex;
    cin >> sizeList;
    ListElemO* ptr = createListO(sizeList);
    showListO(ptr, sizeList);
    cin >> delElIndex;
    delElementListO(ptr, delElIndex);
    showListO(ptr, --sizeList);
    newFirstNodeO(ptr);
    showListO(ptr, ++sizeList);
    
    //BidirectionalList
    cin >> sizeList;
    ListElemB* ptrB = createListB(sizeList);
    showListB(ptrB, sizeList);
    cin >> delElIndex;
    delElementListB(ptrB, delElIndex);
    showListB(ptrB, --sizeList);
    newFirstNodeB(ptrB);
    showListB(ptrB, ++sizeList);
    
    //Stack
    stack<int>* x = new stack<int>;
    printf("Количество: ");
    cin >> sizeList;
    for (int i(0); i < sizeList; i++) {
        x -> pushTop(rand()%8);
    }
    x -> showStack();
    cout << '\n';
    x -> popSpecifiedEl(2);
    x -> showStack();
    
    //Queue
    Queue<int>* y = new Queue<int>;
    printf("Количество: ");
    
    cin >> sizeList;
    
    for (int i(0); i < sizeList; i++) {
        y -> pushBack(rand()%8);
    }
    cin >> delElIndex;
    y -> showQueue();
    y -> popSpecifiedEl(delElIndex);
    y -> showQueue();
    y -> newFirstEl();
    y -> showQueue();
}

```

# OneWayList

```cpp
#pragma once
#include <iostream>


using namespace std;

struct ListElemO
{
    int data;
    ListElemO* next;
    ListElemO* prev;
};


ListElemO* createListO(int size)
{
    ListElemO* p, *r;
    ListElemO * start = new ListElemO;
    cin >> start -> data;
    start -> next = nullptr;
    start -> prev = nullptr;
    p = start;
    for (int i(0); i < size-1; i++){
        r = new ListElemO;
        cin >> r -> data;
        r -> prev = p;
        p -> next = r;
        p = r;
    }
    return start;
}

void delElementListO(ListElemO* ptr, int delIndex){
    for (int i(0); i < delIndex-1; i++) {
        ptr = ptr -> next;
    }
    ptr -> next = ptr -> next -> next;
    delete ptr -> next -> prev;
    ptr -> next -> prev = ptr;
    
    
}

void newNodeO(ListElemO* ptr, int size){
    ListElemO *curNode = ptr;
    ListElemO * newNode = new ListElemO;
    for (int i(0); i < size; i++) {
        curNode = curNode->next;
    }
    if (curNode->prev == nullptr) {
        newNode -> prev = curNode -> prev;
        newNode -> next = curNode;
        curNode->prev = newNode;
        cin >> newNode -> data;
        ptr = newNode;
    } else {
        newNode -> prev = curNode -> prev;
        newNode -> next = curNode;
        curNode -> prev -> next = newNode;
        curNode -> prev = newNode;
        cin >> newNode -> data;
    }
    
    
}
void newFirstNodeO(ListElemO*& ptr){
    ListElemO * newNode = new ListElemO;
    newNode -> data = 0;
    newNode -> prev = nullptr;
    newNode -> next = ptr;
    ptr = newNode;
}
void showListO(ListElemO* ptr, int size){
    cout << ptr -> data;
    for (int i(1); i < size; i++) {
        ptr = ptr -> next;
        cout << ' ' << ptr -> data ;
    }
    cout << endl;
}

```

# BidirectionalList

```cpp
#pragma once
#include <iostream>


using namespace std;

struct ListElemB
{
    int data;
    ListElemB* next;
    ListElemB* prev;
};


ListElemB* createListB(int size)
{
    ListElemB* p, *r;
    ListElemB * start = new ListElemB;
    cin >> start -> data;
    start -> next = nullptr;
    start -> prev = nullptr;
    p = start;
    for (int i(0); i < size-1; i++){
        r = new ListElemB;
        cin >> r -> data;
        r -> prev = p;
        p -> next = r;
        p = r;
    }
    return start;
}

void delElementListB(ListElemB* ptr, int delIndex){
    for (int i(0); i < delIndex-1; i++) {
        ptr = ptr -> next;
    }
    ptr -> next = ptr -> next -> next;
    delete ptr -> next -> prev;
    ptr -> next -> prev = ptr;
    
    
}

void newNodeB(ListElemB* ptr, int size){
    ListElemB *curNode = ptr;
    ListElemB * newNode = new ListElemB;
    for (int i(0); i < size; i++) {
        curNode = curNode->next;
    }
    if (curNode->prev == nullptr) {
        newNode -> prev = curNode -> prev;
        newNode -> next = curNode;
        curNode->prev = newNode;
        cin >> newNode -> data;
        ptr = newNode;
    } else {
        newNode -> prev = curNode -> prev;
        newNode -> next = curNode;
        curNode -> prev -> next = newNode;
        curNode -> prev = newNode;
        cin >> newNode -> data;
    }
    
    
}
void newFirstNodeB(ListElemB*& ptr){
    ListElemB * newNode = new ListElemB;
    newNode -> data = 0;
    newNode -> prev = nullptr;
    newNode -> next = ptr;
    ptr = newNode;
}
void showListB(ListElemB* ptr, int size){
    cout << ptr -> data;
    for (int i(1); i < size; i++) {
        ptr = ptr -> next;
        cout << ' ' << ptr -> data ;
    }
    cout << endl;
}
```

# Stack

```cpp
#pragma once
#include <iostream>


using namespace std;

template <typename xyz>
struct node{
    xyz data;
    node<xyz>* next;
};

template <typename v>
struct stack{
    node<v>* head = nullptr;
    int size = 0;
    
    void pushTop(int data){
        node<v>* newNode = new node<v>;
        newNode -> next = head;
        newNode->data = data;
        head = newNode;
        size++;
        
    }
    int pop()
    {
        int value = head->data;
        node<v>* tmp = head;
        head = head->next;
        size--;
        delete tmp;
        return value;
    }
    void popSpecifiedEl(int specifIndex){
        stack<v> *partStack = new stack<int>;
        for (int i(0); i< specifIndex; i++) {
            partStack -> pushTop(pop());// head ->data
            //head = head -> next;
            //size--;
        }
        pop();
        for (int i(0); i<=partStack -> size; i++) {
            pushTop(partStack -> pop());
        }
        delete partStack;
        
    }
    void showStack(){
        node<int>* curPtr = head;
        for (int i(0); i < size; i++) {
            printf("%i ",curPtr -> data);
            curPtr = curPtr -> next;
        }
    }
    
};

```

# Queue

```cpp
#pragma once
#include <iostream>


using namespace std;

template <typename xyz>
struct QueueElem{
    xyz data;
    QueueElem<xyz>* next;
};

template <typename v>
struct Queue{
    QueueElem<v>* front = nullptr;
    QueueElem<v>* back = front;
    int size = 0;
    
    void pushBack(int data)
    {
        QueueElem<v>* newNode = new QueueElem<v>;
        newNode->data = data;
        newNode->next = nullptr;
        if (size == 0)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }
    int pop()
    {
        int value = front->data;
        QueueElem<v>* tmp = front;
        if (size == 1) { back = nullptr; }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }
    void popSpecifiedEl(int specifIndex){
        Queue<v> *partQueue = new Queue<int>;
        for (int i(0); i< specifIndex; i++) {
            partQueue -> pushBack(pop());
        }
        pop();
        for (int i(0); i< size; i++) {
            partQueue -> pushBack(pop());
        }
        for (int i(0); i<=partQueue -> size; i++) {
            pushBack(partQueue -> pop());
        }
        
        delete partQueue;
        
    }
    void newFirstEl(){
        Queue<v> *partQueue = new Queue<int>;
        for (int i(0); i<= size; i++) {
            partQueue -> pushBack(pop());
        }
        pushBack(rand()%8);
        for (int i(0); i<=partQueue -> size; i++) {
            pushBack(partQueue -> pop());
        }
        
        delete partQueue;
        
    }
    void showQueue(){
        QueueElem<int>* curPtr = front;
        for (int i(0); i < size; i++) {
            printf("%i ",curPtr -> data);
            curPtr = curPtr -> next;
        }
        cout << endl;
    }
    
};

```

