#include <iostream>

using namespace std;

int main(){
    int l;
    cin >> l;

    int money = 0;
    int max_price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};

    for(int i = 0; i < 10; i++){

        while(l + i >= 10){
            money += max_price[i];
            l -= 10 - i;
        }
    }

    cout << money << endl;
}