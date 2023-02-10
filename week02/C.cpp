#include <iostream>

using namespace std;

int definer_rec(int x){
    if (x % 2 == 0 && x > 0){
        x = x / 2;
        definer_rec(x);
    } else if (x == 1){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int y = 0;

    cin >> y;

    if (definer_rec(y)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}