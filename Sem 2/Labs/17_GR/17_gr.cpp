#include "boyerMooreSearch.h"
#include "knuthMorrisPrattSearch.h"


int main(){
    cout << "Какой способ сортировки:\n"
    << "1 - boyerMooreSearch\n"
    << "2 - knuthMorrisPrattSearch\n";
    int number;
    cin >> number;
    switch (number) {
        case 1:{
            boyerMooreSearch("aa3araatchukua.aa", "huku");
            break;
        }
        case 2:{
            knuthMorrisPrattSearch("aa3araatchukua.aa", "chuku");
            break;
        }
        default:{
            cout << "1 OR 2 -_-" << endl;
            break;
        }
    }
    return 0;
}
