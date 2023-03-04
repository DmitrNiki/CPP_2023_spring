#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 10 // actual size of the array
#endif

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void arr_output(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

void arr_input(int (&arr)[N]){
    int x = 0;
    for (int i = 0; i < N; i++){
        cin >> x;
        arr[i] = x;
    }
}

void heaper(int (&arr)[N], int i, int size){
    int parent = i;
    int l_child = 2*i + 1;
    int r_child = 2*i + 2;

    if (l_child < size && arr[l_child] > arr[parent]){
        parent = l_child;
    }

    if (r_child < size && arr[r_child] > arr[parent]){
        parent = r_child;
    }

    if (parent != i){
        swap(arr[parent], arr[i]);
        heaper(arr, parent, size);
    }
}

void cheops_sort(int (&arr)[N]){
    for (int i = N/2 + 1; i >= 0; i--){
        heaper(arr, i, N);
    }
    for (int k = N - 1; k >= 0; k--){
        swap(arr[0], arr[k]);
        heaper(arr, 0, k);
    }
}

double cheops_timer(int (&arr)[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100; cnt > 0; --cnt){
        cheops_sort(arr);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count ();
}

int main(){
    int a[N] = {};
    
    arr_input(a);
    /*for (int k = 0; k < N; k++){
        a[k] = rand() % 1000;
    }*/
    // arr_output(a);
    // cout << cheops_timer(a) << endl; 
    cheops_sort(a);
    arr_output(a);
    return 0;
}