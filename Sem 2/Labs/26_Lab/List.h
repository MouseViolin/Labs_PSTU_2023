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
