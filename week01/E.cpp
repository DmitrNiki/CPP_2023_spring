#include <iostream>

using namespace std;

int SCM(int n, int m){
    int p = 0, max = n;

    if (m > n){
        max = m;
    }

    for (int i = max; i <= m*n; i += max){
        if ((i % m == 0 && i % n == 0) && p == 0){
            p = i;
        }
    }
    return p;
}
int main(){
    int a = 0, b = 0;

    cin >> a >> b;

    if ((a >= 1 && b >= 1) && SCM(a, b) != 0){
        cout << SCM(a, b) << endl;
    }
    return 0;
}