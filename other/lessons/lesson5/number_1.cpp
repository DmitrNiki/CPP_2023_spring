#include <iostream>

int main() {
    double first = 1, first_and_half = 100, second = 2;
    double* ptr1 = &first;
    double* ptr2 = &second;
    first_and_half *= 100;
    std::cout << first << ' ' << second << std::endl;
    std::cout << ptr1 << ' ' << &first_and_half << ' ' << ptr2 << std::endl;
    std::cout << *ptr1 << ' ' << *&first_and_half << ' ' << *ptr2 << std::endl;
    std::cout << ptr1 << ' ' << ptr1 + 1 << ' ' << *(ptr1 + 1) << std::endl;
    return 1;
}
// &: int --> int*
// *: int* --> int
