#include <iostream> 
#include <chrono>

#ifndef N
#define N 500000  // actual size of the array
#endif

int bin_search(int a[N], int number){
    int left = -1; // a[left] <= number && a[right] > number
    int right = N - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= number) {
            left = mid;
        } else {
            right = mid;
        } 
    }
    if (left > -1 && a[left] == number) {
        return left;
    } else {
        return -1;
    }
}

void lin_search(int a[N], int number){
    int left = 0; 
    for (int i = 0; i < N; i++){
        if (a[i] == number){
            break;
        }
    }    
}

int bin_timer(int a[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 10000000; cnt > 0; --cnt){
        bin_search(a, 2*N);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

int lin_timer(int a[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 2000; cnt > 0; --cnt){
        lin_search(a, 2*N);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

int main(){
    int b_ave = 0;
    int l_ave = 0;
    int c = 10;
    int a[N] = {};
    for (int i = 0; i < N; i++){
        a[i] = i;
    }
    for (int k = 1; k <= c; k++){
        //b_ave += bin_timer(a);
        l_ave += lin_timer(a);
        // std::cout << b_ave/k << " ";
    }
    std::cout << l_ave/c << std::endl;
    return 0;  
}