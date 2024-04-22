#pragma once
#include <iostream>
#include <string>


using namespace std;

class Error{public: virtual void what(){};};

class IndexError : public Error {
protected: string msg;
public:
    IndexError(){msg = "Index Error\n";}
    virtual void what(){cout << msg;}
};

class OverSizeError : public Error{
protected: string msg;
public:
    OverSizeError(){msg = "OverSize Error\n";}
    virtual void what(){cout << msg;}
};
