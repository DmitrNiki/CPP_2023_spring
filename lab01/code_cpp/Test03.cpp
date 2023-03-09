#include <iostream> 
#include <chrono>
#include <random>

#ifndef N
#define N 160000// actual size of the array
#endif

#ifndef X
#define X 160001// actual size of the array
#endif

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void alg_A(int (&a)[N], int (&b)[X]){
    for(int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
             if (a[j] == b[i]){
                swap(a[1], a[j]);
                break;
             }
        }
    }
}

void alg_B(int (&a)[N], int (&b)[X]){
    for(int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
             if (a[j] == b[i] && j != 0){
                swap(a[j - 1], a[j]);
                break;
             }
        }
    }
}

void alg_C(int (&a)[N], int (&b)[X], int (&d)[N]){
    int c = 0;
    for(int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
            if (a[j] == b[i]){
                d[j] += 1;
                for(int k = 0; k < j; k++){
                    c = j - k;
                    if (d[c - 1] < d[c]){
                        swap(d[c - 1], d[c]);
                        swap(a[c - 1], a[c]); 
                    } else {
                        break;
                    }
                }
                break;
            }  
        }
    }
}

double timer_A(int (&a)[N], int (&b)[X]){
    auto begin = std::chrono::steady_clock::now();
    alg_A(a, b);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}
double timer_B(int (&a)[N], int (&b)[X]){
    auto begin = std::chrono::steady_clock::now();
    alg_B(a, b);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}
double timer_C(int (&a)[N], int (&b)[X], int (&d)[N]){
    auto begin = std::chrono::steady_clock::now();
    alg_C(a, b, d);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

void arr_filler(int (&a)[N], int (&d)[N], int (&b)[X]){
    for (int i = 0; i < N; i++){
        a[i] = i;
        d[i] = 0;
    }
    for (int j = 0; j < X; j++){
        b[j] = rand() % X;
    }
}
int main(){
    double k = 5;
    double ave_A = 0;
    double ave_B = 0;
    double ave_C = 0;
    int a[N] = {};
    int b[X] = {};
    int d[N] = {};
    for (int i = k; i > 0; i--){
        arr_filler(a, d, b);
        ave_A += timer_A(a, b);
        ave_B += timer_B(a, b);
        ave_C += timer_C(a, b, d);
    }
    std::cout << "A:" << ave_A/k << "   " << "B:" << ave_B/k << "   " << "C:" << ave_C/k << std::endl;
    return 0;  
}