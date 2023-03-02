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

void gnome_sort(int (&arr)[N]){
    int i = 1;
    int j = 2;
    while(i < N){
        if(arr[i - 1] < arr[i]){
            i = j;
            j = j + 1;
        }else{
            swap(arr[i - 1], arr[i]);
            i = i - 1;
            if (i == 0){
                i = j;
                j = j + 1;
            }
        }
    }
}

double gnome_timer(int (&arr)[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100; cnt > 0; --cnt){
        gnome_sort(arr);
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
    gnome_sort(a);
    arr_output(a);
    // cout << gnome_timer(a) << endl; 
    return 0;
}