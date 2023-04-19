#include <iostream>

int main() {
    double* ptr = nullptr;
    ptr = new double;
    *ptr = 12.5;
    std::cout << ptr << ' ' << *ptr << std::endl;
    delete ptr;
    return 0;
}
