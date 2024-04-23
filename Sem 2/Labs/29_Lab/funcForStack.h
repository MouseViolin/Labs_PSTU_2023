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
