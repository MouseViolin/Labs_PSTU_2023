
#include <iostream>



int main() {
    int n;
    int* ptr = &n;

    std::cin >> *ptr;

    std::cout << n;
    return 0;
}
