
#include <iostream>
#include <string>

int main() {
    char one, two;
    int cnt_one = 0, cnt_two = 0;
    
    std::cin >> one;
    std::cin >> two;
//    Если попытаться запрашивать char после строки, в которой присутсвует пробел("Hi World"),
//    то принимается в учет только первые два символа ("Hi"). И исчезает возможность ввода char
//    †-†
    std::string st;
    std::cout<<"Введите строку, после два символа"<<std::endl;
    std::cin>>st;
    
    
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if(tmp == one)
        { cnt_one++; }
        else if (tmp == two) { cnt_two++; }
        pt++;
    }
    
    std::cout<<"Количество one:  "<<cnt_one<<std::endl;
    std::cout<<"Количество two:  "<<cnt_two<<std::endl;
    std::cout<<"Количество all:  "<<st.length()<<std::endl;
    return 0;
}
