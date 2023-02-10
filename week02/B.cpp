#include <iostream>

using namespace std;

int main(){
    int cnt = 0;
    int x = 0;

    do {
        cin >> x;

        if (x % 2 == 0){
            cnt++;
        }
    }while (x != 0);

    cout << cnt - 1 << endl;

    return 0;
}