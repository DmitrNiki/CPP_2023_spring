#include <iostream> 
#include <chrono>

#ifndef N
#define N 60000  // actual size of the array
#endif

void swap(unsigned &lha, unsigned &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void arr_output(unsigned (&arr)[N]){
    for (int i = 0; i < N; i++){
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
}

int comb(unsigned (&arr)[N], int step){
    int sorted = 1;
    for (int i = 0; i < N - step; i++) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
            sorted = 0;
        }
    }

    return sorted;
}
void comb_sort(unsigned (&arr)[N]) {
    int del_step = 2;
    int step = N;
    int sorted = 0;

    while (!sorted) {
        step /= del_step;
        if (step <= 1) {
            sorted = 1;
            step = 1;
        }
        sorted = comb(arr, step);
    }
}

double timer(unsigned (&a)[N]){
    auto begin = std::chrono::steady_clock::now();
    comb_sort(a);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

void filler_arr(unsigned (&arr)[N]){
    for (int i = 0; i < N; i++){
        arr[i] = rand();
    }
}

int main(){
    unsigned a[N] = {};
    double time = 0;
    double c = 10;

    for (int k = c; k > 0; k--){
        filler_arr(a);
        time += timer(a);
    }
    std::cout << time/c << std::endl;

    return 0;
}