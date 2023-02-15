#include <iostream>
#include <cmath>

using namespace std; 

int main() {
    float a = 0, b = 0, c = 0;
    float x_1 = 0, x_2 = 0, D = 0;
    
    cin >> a >> b >> c;

    D = sqrt(b*b - 4*a*c);
    if (D > 0 && a != 0) {
        x_1 = (-b + D)/(2*a);
        x_2 = (-b - D)/(2*a);
        cout << x_1 << ' ' << x_2 << endl;
    } else if (D == 0 && a != 0) {
        x_1 = (-b)/(2*a);
        cout << x_1 << endl;
    } else if (a == 0) {
        x_1 = (-c)/(b);
        cout << x_1 << endl;
    } else {
        cout << '\n' << endl;
    }
    return 0;
}