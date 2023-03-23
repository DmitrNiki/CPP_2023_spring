#include <iostream> 
#include <chrono>

#ifndef N
#define N 500  // actual size of the array
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


void forward_step(unsigned (&arr)[N], unsigned const begin_idx, unsigned const end_idx){
    for (int i = begin_idx; i < end_idx; i++){
        if (arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
    }
}

void backward_step(unsigned (&arr)[N], unsigned const begin_idx, unsigned const end_idx){
    for (int i = end_idx; i > begin_idx; i--){
        if (arr[i - 1] > arr[i]){
            swap(arr[i - 1], arr[i]);
        }
    }
}

void snaker_sort(unsigned (&arr)[N]){
    int begin_idx = 0;
    int end_idx = N - 1;

    while (begin_idx <= end_idx) {
        forward_step(arr, begin_idx, end_idx);

        --end_idx;

        backward_step(arr, begin_idx, end_idx);

        ++begin_idx;
    }
}

int main(){
    unsigned a[N] = {};

    for (int i = 0; i < N; i++){
        a[i] = rand();
    }

    snaker_sort(a);
    arr_output(a);

    return 0;
}