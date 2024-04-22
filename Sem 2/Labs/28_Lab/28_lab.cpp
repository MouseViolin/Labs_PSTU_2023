#include "Money.h"
#include "fileWork.h"
#include <iostream>



using namespace std;



int main(){
    Money m;
    int k,c,num,count;
    char fName[30];
    do {
        printf("1. Make File\n2. Print File\n3.Delete Element\n4.Increase All Elemnts\n5.Additional Elements\n0. Exit\n");
        cin >> c;
        switch (c) {
            case 1:
                printf("File name: "); cin >> fName;
                k = fileMake(fName);
                if (k<0) printf("Can't make file");
                break;
            case 2:
                printf("File name: "); cin >> fName;
                k = printFile(fName);
                if (k==0) printf("Empty file\n");
                if (k<0) printf("Can't read file\n");
                break;
            case 3:
                printf("File name: "); cin >> fName;
                printf("Number: "); cin >> num;
                k = delElem(fName, num);
                if (k<0) printf("Can't make file");
                break;
            case 4:
                printf("File name: "); cin >> fName;
                k = increaseElemFile(fName);
                if (k<0) printf("Can't make file");
                break;
            case 5:
                printf("File name: "); cin >> fName;
                printf("Number: "); cin >> num;
                printf("Count: "); cin >> count;
                k = additionalElem(fName, num, count);
                if (k<0) printf("Can't make file");
                break;
        }
    } while (c != 0);
    
    
    
    return 0;
}


