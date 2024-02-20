#include <iostream>
#include <string>

int main() {

    std::string st;
    std::cout<<"Введите строку"<<std::endl;
    getline(std::cin, st);
    const char* pt = st.c_str();
    
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if(tmp > 64 && tmp<123)
            std::cout << tmp << ' ';
        pt++;
    }
    pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if((tmp > 47 && tmp<58) || tmp == 46)
            std::cout << tmp << ' ';
        pt++;
    }
    
    return 0;
}


