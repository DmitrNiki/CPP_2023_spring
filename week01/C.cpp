#include <iostream>

using namespace std;

int main() {
    int x = 0, f = 1;

    cin >> x;

    if (x >= 0){
        for (int i = 0;  i < x; i++){
            f *= (x - i);
            }
        cout << f << endl;    
    } 
    return 0;
}