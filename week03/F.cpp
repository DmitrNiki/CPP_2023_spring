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
    int k = N / 2;
    int l = N / 4;
    do{
        if(arr[k] == 0){
            k += l;
        } else {
            k -= l;
        }
        l /= 2;
    } while(!(arr[k] == 0 && arr[k + 1] == 1));
    return k;
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