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


