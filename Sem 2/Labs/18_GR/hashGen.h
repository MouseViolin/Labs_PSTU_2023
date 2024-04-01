#pragma once

#include <iostream>
#include <string>

using namespace std;


// H(k)= [M (kAmod1)], 0<A<1, mod1 – получение дробной части, [] – получение целой части
int hashGen(int size, string str){
    unsigned int key = 0;
    for (int i(0); i < str.size(); key+=str[i], i++);
    return  static_cast<int>(key*0.2)%size;
}
