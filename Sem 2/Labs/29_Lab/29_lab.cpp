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


