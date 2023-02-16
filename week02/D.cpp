#include <iostream>

using namespace std;

int recursive_power(int base, int power){
    if (power > 0){
        return base * recursive_power(base, power - 1);
    } else if (power == 0){
        return 1;
    } 
    return 0;
}

int main(){
    int a = 0, b = 0;

    cin >> a >> b;

    cout << recursive_power(a, b) << endl;

    return 0;
}