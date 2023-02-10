#include <iostream>

using namespace std;

int V_year(int x){
    if ((x % 4 == 0  && x % 100 != 0) || (x % 400 == 0)){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int y = 0;

    cin >> y;

    if (V_year(y)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}