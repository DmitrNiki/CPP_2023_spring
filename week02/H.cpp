#include <iostream>

using namespace std;

int eratosfen(int n){
    int flag = 0;
    for (int i = n - 1; i > 1; i--){
        if (n % i == 0){
            flag = 1;
        }
    }
    return flag;
}
int main(){
    int x;

    cin >> x;

    if (!eratosfen(x)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}