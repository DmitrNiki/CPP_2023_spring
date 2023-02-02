#include <iostream>

using namespace std;

int SCM(int n, int m){
    int p = 0, max = n;

    if (m > n){
        max = m;
    }

    for (int i = max; i <= m*n; i += max){
        if (i % m == 0 && i % n == 0){
            p = i;
        }
    }
    return p;
}
int main(){
    int a = 0, b = 0;

    cin >> a >> b;

    if ((a >= 1 && b >= 1) && SCM(a, b) != 0){
        cout << "the SCM of " << a << " and " << b << " is " << SCM(a, b) << endl;
    } else if (a < 1 || b < 1) {
        cout << "Error: both numbers should be positive." << endl;
    }else if (SCM(a, b) == 0){
        cout << "There are none common multiple of numbers in INT." << endl;
    }
    return 0;
}