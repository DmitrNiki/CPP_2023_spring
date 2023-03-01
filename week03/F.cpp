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

int binsearch(int (&arr)[N]){
    int left = -1;
    int right = N - 1;
    int mid = 0; 
    do{
        mid = (left + right)/2;
        if(arr[mid] == 0){
            left = mid;
        } else {
            right = mid;
        }
    } while(!(arr[mid] == 0 && arr[mid + 1] == 1));
    return mid;
}

 void arr_output(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
 }

int main() {
    int a[N] = {};  // array initialization
    arr_input(a);
    cout << binsearch(a) << endl;
    arr_output(a);
    return 0;
}