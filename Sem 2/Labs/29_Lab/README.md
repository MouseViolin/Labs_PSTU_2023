
# Лабораторная работа №29
>[!IMPORTANT]
>Тема : "STL"
>Цель: Использование стандартных обобщенных алгоритмов из библиотеки STL в 0О программе.

# Вариант №6

>Задача 1
> 1. Контейнер - вектор
> 2. Тип элементов Money (см. лабораторную работу Nº3).

>Задача 2
> - Адаптер контейнера - стек.

>Задача 3
> - Ассоциативный контейнер - множество с дубликатами.


# UML-диаграмма

<img alt="6665c0d187bb358f68daa5418f33de17.gif" src="https://github.com/MouseViolin/Labs_PSTU_2023/blob/main/Sem%202/Labs/29_Lab/6665c0d187bb358f68daa5418f33de17.gif?raw=true" data-hpc="true" class="Box-sc-g0xbh4-0 kzRgrI">

# Код программы

## main.cpp

```cpp
#include "Money.h"
#include "funcForStack.h"
#include "funcForVector.h"
#include "funcForMultiset.h"
#include <set>

#include <iostream>



using namespace std;


int main(){
    
    MVector a = makeVector(3);
    show(a);
    maxInStart(a);
    deleteMin(a);
    show(a);
    meanArith(a);
    show(a);
    
    MStack b = makeStack(3);
    show(b);
    maxInStart(b);
    deleteMin(b);
    show(b);
    meanArith(b);
    show(b);
    
    MMSet c = makeMSet(3);
    show(c);
    deleteMin(c);
    show(c);
    
    
    
    
    return 0;
}

```

## Money.h

```cpp
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Money{
protected:
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
    
    bool operator==(Money&a){
        if (rub == a.rub && kopeck == a.kopeck) return 1;
        else return 0;
    }
    
    friend ostream& operator << (ostream& os,const Money& a);
    friend istream& operator >> (istream& in, Money& a);
    
    friend fstream& operator >> (fstream& fin, Money&a);
    friend fstream& operator << (fstream& fout, const Money&a);
    
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

fstream& operator >> (fstream& fin, Money&a){
    fin >> a.rub;
    fin >> a.kopeck;
    return fin;
}

fstream& operator << (fstream& fout, const Money&a){
    fout << a.rub << '\n' << a.kopeck << endl;
    return fout;
}


```

## funcForVector.h

```cpp
#pragma once
#include "Money.h"

#include <vector>
#include <iostream>



using namespace std;

typedef vector<Money> MVector;

MVector makeVector(int cnt){
    Money a;
    MVector m;
    for (int i(0); i<cnt; i++) {
        cin >> a;
        m.push_back(a);
    }
    return m;
}

void show(MVector& a){
    for (int i(0); i < a.size(); i++) cout << a[i] << endl;
    cout << endl;
}

void maxInStart(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    for (int i(1); i < a.size(); i++)
        if (tmp.getRub() + tmp.getKopeck()/100 < a[i].getRub() + a[i].getKopeck()/100)
            tmp = a[i];
    
    MVector one;
    one.push_back(tmp);
    for (int i(0); i < a.size(); i++){
        one.push_back(a[i]);
    }
    a.clear();
    for (int i(0); i < one.size(); i++){
        a.push_back(one[i]);
    }
}

void deleteMin(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    int pos = 0;
    for (int i(1); i < a.size(); i++)
        if (tmp.getRub() + tmp.getKopeck()/100 > a[i].getRub() + a[i].getKopeck()/100)
        {tmp = a[i]; pos = i;}
    
    MVector one;
    for (int i(pos+1); i < a.size(); i++) one.push_back(a[i]);
    for (int i(pos), size = a.size(); i < size; i++) a.pop_back();
    for (int i(0); i < one.size(); i++) a.push_back(one[i]);
    
}

void meanArith(MVector& a){
    Money tmp(a[0].getRub(), a[0].getKopeck());
    for (int i(1); i < a.size(); i++) tmp = tmp+a[i];
    tmp.setRub(tmp.getRub()/a.size());
    tmp.setKopeck(tmp.getKopeck()/a.size());
    for (int i(0); i < a.size(); i++) a[i] = a[i] + tmp;
}

```

## funcForStack.h

```cpp
#pragma once
#include "Money.h"

#include <stack>
#include <iostream>



using namespace std;

typedef stack<Money> MStack;

MStack makeStack(int cnt){
    Money a;
    MStack m;
    for (int i(0); i<cnt; i++) {
        cin >> a;
        m.push(a);
    }
    return m;
}

void show(MStack a){
    MStack st;
    
    st.push(a.top());
    a.pop();
    for (int i(0), size = a.size(); i < size; i++){
        st.push(a.top());
        a.pop();
    }
    for (int i(0), size = st.size(); i < size; i++) {cout << st.top() << endl; st.pop();}
    cout << endl;
}

void maxInStart(MStack& a){
    MStack st;
    Money tmp(a.top().getRub(), a.top().getKopeck());
    st.push(a.top());
    a.pop();
    for (int i(0), size = a.size(); i < size; i++){
        if (tmp.getRub() + tmp.getKopeck()/100 < a.top().getRub() + a.top().getKopeck()/100)
            tmp = a.top();
        st.push(a.top());
        a.pop();
    }
    
    a.push(tmp);
    for (int i(0), size = st.size(); i < size; i++){
        a.push(st.top());
        st.pop();
    }
}

void deleteMin(MStack& a){
    MStack st;
    Money tmp(a.top().getRub(), a.top().getKopeck());
    st.push(a.top());
    a.pop();
    for (int i(0), size = a.size(); i < size; i++){
        if (tmp.getRub() + tmp.getKopeck()/100 > a.top().getRub() + a.top().getKopeck()/100)
            tmp = a.top();
        st.push(a.top());
        a.pop();
    }
    
    for (int i(0), size = st.size(); i < size; i++){
        if ( st.top() != tmp) a.push(st.top());
        st.pop();
    }
}

void meanArith(MStack& a){
    MStack st;
    Money tmp(a.top().getRub(), a.top().getKopeck());
    st.push(a.top());
    a.pop();
    for (int i(0), size = a.size(); i < size; i++){
        tmp = tmp + a.top();
        st.push(a.top());
        a.pop();
    }
    tmp.setRub(tmp.getRub()/st.size());
    tmp.setKopeck(tmp.getKopeck()/st.size());
    for (int i(0), size = st.size(); i < size; i++){
        a.push(st.top()+tmp);
        st.pop();
    }
}

```

## funcForMultiset.h

```cpp
#pragma once
#include "Money.h"

#include <set>
#include <iostream>



using namespace std;

typedef multiset<Money> MMSet;
typedef MMSet::iterator it;

MMSet makeMSet(int cnt){
    Money a;
    MMSet m;
    for (int i(0); i<cnt; i++) {
        cin >> a;
        m.insert(a);
    }
    return m;
}

void show(MMSet& a){
    for (auto i(a.begin());i != a.end() ;++i) cout<<*i;
    cout << endl;
}



void deleteMin(MMSet& a){
    a.erase(a.begin());
}



```


# Контрольные вопросы:

- Нема

