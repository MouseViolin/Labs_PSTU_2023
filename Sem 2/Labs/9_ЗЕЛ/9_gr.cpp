#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int check(string st){
    const char* pt = st.c_str();
    int cons = 0;
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if(tmp > 65 && tmp<123 && tmp !=69 && tmp !=73 && tmp !=79 && tmp !=85 && tmp !=89 && tmp !=97 && tmp !=101 && tmp !=105 && tmp !=111 && tmp !=117 && tmp !=121 )
            cons++;
        pt++;
    }
    return cons;
}

int main() {
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string str;
    int n,k, line = 1, sumCons = 0;
    cin >> n >> k;
    while (getline(F1, str) && line!=n-1) line++;
    while (getline(F1, str) && n!=k+1) {
        F2 << str << endl;
        cout << str << endl;
        sumCons += check(str);
        n++;
    }
    cout << sumCons << endl;
    F1.close();
    F2.close();
    
    return 0;
}

