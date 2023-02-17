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

void arr_input(int (&arr)[2*N]){
    for (int i = 0; i < 2 * N; i++){
        cin >> arr[i];
    }
}

void arr_sort(int (&arr)[2*N]){
    for (int i = 0; i < 2 * N - 1; i++){
        if (arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
            i = -1;
        }
    }
}

 void arr_output(int (&arr)[2*N]){
    for (int i = 0; i < 2*N; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
 }

int main() {
    int a[2*N] = {};  // array initialization
    arr_input(a);
    arr_sort(a);
    arr_output(a);
    return 0;
}