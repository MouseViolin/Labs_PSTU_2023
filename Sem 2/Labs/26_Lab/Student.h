#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class Student : public Person{
protected:
    float socRating;
public:
    Student(): Person(){};
    Student(string a, int b, float c):Person(a,b){socRating = c;};
    Student(const Student&a){name = a.name; age = a.age; socRating = a.socRating;};
    
    float getRating(){return socRating;};
    void setRating(float a){socRating = a;};
    
    
    void Show(){cout << "Name: " << name << ' ' << "Age: "<< age<< ' '<< "Social Rating: " << socRating<< endl;};
    void Input(){
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Social Rating: "; cin >> socRating;};
    
    ~Student(){};
};
