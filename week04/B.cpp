#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 10000 // actual size of the array
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int ind_left_base, int ind_right_base)
{
    if (ind_left_base < ind_right_base) {
        int pi = partition(arr, ind_left_base, ind_right_base);

        quickSort(arr, ind_left_base, pi - 1);
        quickSort(arr, pi + 1, ind_right_base);
    }
}

double quick_timer(int (&arr)[N]){
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100; cnt > 0; --cnt){
        quickSort(arr, 0, N);
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
    quickSort(a, 0, N);
    arr_output(a);
    // cout << quick_timer(a) << endl; 
    return 0;
}