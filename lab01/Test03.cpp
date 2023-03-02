#include <iostream> 
#include <chrono>
#include <random>

#ifndef N
#define N 50000// actual size of the array
#endif

#ifndef X
#define X 5000// actual size of the array
#endif

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void alg_1(int (&a)[N], int (&b)[X]){
    for(int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
             if (a[j] == b[i]){
                swap(a[1], a[j]);
                break;
             }
        }
    }
}

void alg_2(int (&a)[N], int (&b)[X]){
    for(int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
             if (a[j] == b[i] && j != 0){
                swap(a[j - 1], a[j]);
                break;
             }
        }
    }
}

void alg_3(int (&a)[N], int (&b)[X], int (&d)[N]){
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

double timer(int (&a)[N], int (&b)[X], int (&d)[N]){
    auto begin = std::chrono::steady_clock::now();
    // alg_1(a, b);
    // alg_2(a, b);
    alg_3(a, b, d);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

int main(){
    double ave = 0;
    double l_ave = 0;
    int c = 100;
    int a[N] = {};
    int b[X] = {};
    int d[N] = {};
    for (int i = 0; i < N; i++){
        a[i] = i;
        d[i] = 0;
    }
    for (int j = 0; j < X; j++){
        b[j] = rand() % N;
    }
    for (int k = 1; k <= c; k++){
        l_ave = ave;
        ave += timer(a, b, d);
        // std::cout << timer(a, b, d) << " ";
        std::cout << ave - l_ave << " " << k << " " << ave/k << std::endl;
    }
    std::cout << ave/c << std::endl;
    return 0;  
}