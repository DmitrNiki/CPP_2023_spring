#include <iostream>
 
using namespace std;

int LCD(int n, int m){
    int p = 1;

    for (int i = 1; i <= n && i <= m; i++){
        if (n % i == 0 && m % i == 0){
            p = i;
        }
    }
    return p;
}

int main() {
    int a = 0, b = 0;
    
    cin >> a >> b;

    if (a >= 1 && b >= 1){
        cout << "the LCD of " << a
        << " and " << b
        << " is " << LCD(a, b) << endl;
    } else {
        cout << "Error: both numbers should be positive." << endl;
    }
    return 0;
}