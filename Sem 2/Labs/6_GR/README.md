# Лабораторная работа №6
>[!IMPORTANT]
>Тема : "Строки"
>Цель: Изучение символьных и строковых переменных и способов их обработки в языке С++.

# Вариант №6
Преобразовать строку таким образом, чтобы сначала в ней были напечатаны только буквы, а потом только цифры, не меняя порядка следования символов в строке.

# Блок-схема
![6_gr](https://github.com/MouseViolin/Labs_PSTU_2023/assets/129219043/4a4fa669-63ef-4a30-88a1-2501f069608f)


# Код программы

```cpp
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


```

