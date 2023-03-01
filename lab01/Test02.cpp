#include <iostream> 
#include <chrono>

#ifndef N
#define N 500000// actual size of the array
#endif

void Nsqr_search(int a[N], int number){ 
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (a[i] + a[j] == number){
                break;
            }
        }
    }    
}

void N_search(int a[N], int number){
    int left = 0;
    int right = N - 1;
    while((a[left] + a[right] != number) && left != right){
        if (a[left] + a[right] < number){
            left += 1;
        } else if(a[left] + a[right] > number){
            right -= 1;
        }
    }
}

int timer(int a[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 1000; cnt > 0; --cnt){
        // Nsqr_search(a, 2*N);
        N_search(a, 2*N);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

int main(){
    int ave = 0;
    int c = 100;
    int a[N] = {};
    for (int i = 0; i < N; i++){
        a[i] = i;
    }
    for (int k = 1; k <= c; k++){
        //b_ave += bin_timer(a);
        ave += timer(a);
        // std::cout << b_ave/k << " ";
    }
    std::cout << ave/c << std::endl;
    return 0;  
}