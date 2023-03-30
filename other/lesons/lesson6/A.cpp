#include <iostream>

using namespace std;

int main(){
    int x = 0;
    for (int i = 0; i < 1000; i++){
        int* ptr = new int[100];
        // жрет память и не освобождает её;
        delete [] ptr;
        ptr = nullptr;
        delete [] ptr;
        // двойное освобождение;
        if (i = 999){
            cin >> x;
        }
    }
    return 0;
}
