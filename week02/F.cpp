#include <iostream>

using namespace std;

int recursive_factorial(int n){
    if (n > 0){
        return n * recursive_factorial(n - 1);
    } else {
        return 1;
    }
}

int main(){
    int x = 0;

    cin >> x;
    cout << recursive_factorial(x) << endl;
    return 0;
}