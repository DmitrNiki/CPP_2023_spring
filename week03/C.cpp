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
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void arr_ringRmove(int (&arr)[N]){
    int tmp = 0;
    for (int i = 0; i < N - 1 ; i++){
        swap(arr[N - 2 - i], arr[N - 1 - i]);   
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
    int k = 0;
    arr_input(a);
    cin >> k;
    for (int i = 1; i <= k; i++){
        arr_ringRmove(a);
    }
    arr_output(a);
    return 0;
}