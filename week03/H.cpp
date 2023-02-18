#include <iostream>

#ifndef N
#define N 10  // actual size of the array
#endif

#ifndef M
#define M 10 // actual size of the array
#endif

using namespace std;

void arr_input(int (&arr)[N][M]){
    for (int k = 0; k < M; k++){
        for (int i = 0; i < N; i++){
            cin >> arr[i][k];
        }
    }
}

 void arr_output(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int k = 0; k < M; k++){
            cout << arr[i][k] << " "; 
        }
        cout << '\n';
    }
    cout << endl;
 }

int main() {
    int a[N][M] = {};  // array initialization
    arr_input(a);
    arr_output(a);
    return 0;
}