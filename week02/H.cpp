#include <iostream>

using namespace std;

/*
int eratosfen(int n){
    int flag = 0;
    for (int i = n - 1; i > n/2 ; i--){
        if (n % i == 0){
            flag = 1;
        }
    }
    return flag;
}
*/

int eratosfen_2(int k){

    if ((k * k) % 24 == 1 || (k == 2 || k == 3)){
        return 0;
    }
    return 1;
}

int main(){
    int x;

    cin >> x;

    if ((!eratosfen_2(x))){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}