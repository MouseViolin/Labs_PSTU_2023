#include "chainMethod.h"
#include "openAddressing.h"

#include <iostream>
#include <string>

using namespace std;


int main(){
    cout << "Какой способ сортировки:\n"
    << "1 - open addressing\n"
    << "2 - the chain method\n";
    int number;
    cin >> number;
    switch (number) {
        case 1:{
            hashTableOpAdr* people = new hashTableOpAdr;
            people -> setHashTable(100);
            people -> showTable();
            break;
        }
        case 2:{
            hashTableChain* people = new hashTableChain;
            people -> setHashTable(100);
            people -> showTable();
            break;
        }
        default:{
            cout << "1 OR 2 -_-" << endl;
            break;
        }
    }
    
}
