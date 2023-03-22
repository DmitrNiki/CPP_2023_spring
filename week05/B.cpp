#include <iostream>

using namespace std;

int main(){
    short int* arr = new short int [10];
    for (short int i = 0; i < 10; i++){
        arr[i] = i;
        cout << &arr[i] << " ";
    }
    cout << endl;
    for (short int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for (short int i = 0; i < 10; i++){
        if (i % 2 == 0){
            short int s = arr[i] * arr[i];
            short int* c = &s;
            arr[i] = *c;
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;
    return 1;
}