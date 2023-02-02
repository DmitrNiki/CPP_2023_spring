#include <iostream>

using namespace std;

int main() {
    int x = 0, f = 1;

    cin >> x;

    if (x >= 0){
        for (int i = 0;  i < x; i++){
            f *= (x - i);
            }
        cout <<"x = " << x << "; x! = " << f << endl;    
    } else if (x < 0){
        cout << "Error: x must be positive." << endl;
    }
    return 0;
}