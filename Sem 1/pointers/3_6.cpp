
#include <iostream>
#include <string>

int main() {
//  Попытки сделать с русским языком не увенчались успехом, тк не воспринимает корректно кириллицу
//  Широкий ввод и char, setlocale и попытка смены кодировки для консоли - не помогли †-†
    int countC = 0;
    int countV = 0;
    std::string st;
    std::cout<<"Введите строку"<<std::endl;
    std::cin>>st;
    const char* pt = st.c_str();
    
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        std::cout << *pt << std::endl;
        if(tmp==L'a' || tmp==L'e' || tmp==L'y' || tmp==L'u' || tmp==L'i' || tmp==L'o')
        { countV++; }
        else { countC++; }
        pt++;
    }
    
    std::cout <<"Количество гласных:  " <<countV << std::endl;
    std::cout <<"Количество согласных:  " << countC << std::endl;
    return 0;
}
