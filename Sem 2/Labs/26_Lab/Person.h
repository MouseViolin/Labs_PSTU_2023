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

