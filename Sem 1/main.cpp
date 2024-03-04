#include <iostream>
#include <ctime>

using namespace std;

template <typename xyz>
struct node{
    xyz data;
    node<xyz>* next;
};

template <typename xyz>
struct stack{
    node<xyz>* head = nullptr;
    int size = 0;
    
};
template <typename v>
void pushTop(stack<v>& tmp, int data){
    node<v>* newNode = new node<v>;
    newNode -> next = tmp.head;
    newNode->data = data;
    tmp.head = newNode;
    tmp.size++;
    
}
template <typename v>
void pop(stack<v>& tmp, int data){
    node<v> delHead = tmp.head;
    tmp.head = tmp.head -> next;
    delete delHead;
    tmp.size--;
    
}
template <typename v>
void showStack(stack<v>& tmp, int n){
    node<int>* curPtr = tmp.head;
    for (int i(0); i < n; i++) {
        printf("%i ",curPtr -> data);
        curPtr = curPtr -> next;
    }
}

int main(){
    srand((unsigned int)time(0));
    stack<int>* x = new stack<int>;
    
    
    
    printf("Количество: ");
    int cnt;
    cin >> cnt;
    
    for (int i(0); i < cnt; i++) {
        pushTop(*x, rand()%8);
    }
    showStack(*x, cnt);
}

