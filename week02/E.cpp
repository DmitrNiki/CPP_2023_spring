#include <iostream>

using namespace std;

int fibonacci(int i){
    if (i == 0 || i == 1){
        return 1;
    } else if (i > 1){
        return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(){
    int x = 0;
    cin >> x;
    cout << fibonacci(x) << endl;
    return 0;
}