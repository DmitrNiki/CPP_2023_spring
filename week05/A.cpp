#include <iostream>

#ifndef N
#define N 100
#endif

void arr_output(int (&a)[N]){
    for (int i = 0; i < N - 1; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << a[N - 1] << std::endl;
}

int main(){
    double zero = 0;
    double* ptr = &zero;
    std::cout << *ptr << ' ' << ptr << std::endl;
    std::cout << *(ptr - 3) << ' ' << (ptr - 3) << std::endl;
    std::cout << *(ptr + 5) << ' ' << (ptr + 5) << std::endl;
    return 1;
}