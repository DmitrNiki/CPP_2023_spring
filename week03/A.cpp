#include <iostream>

#ifndef N
#define N 10  // actual size of the array
#endif

using namespace std;

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void arr_input(int (&arr)[N]){
    int x = 0;
    for (int i = 0; i < N; i++){
        cin >> x;
        arr[i] = x;
    }
}

void arr_swap(int (&arr)[N]){
    int tmp = 0;
    for (int i = 0; i < (N/2) ; i++){
        swap(arr[i], arr[N - 1 -  i]);   
    }
}

 void arr_output(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
 }

int main() {
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // array initialization
    arr_input(a);
    arr_swap(a);
    arr_output(a);
    return 0;
}