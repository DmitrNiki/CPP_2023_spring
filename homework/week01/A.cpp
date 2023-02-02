#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 0, b = 0;
    cin >> a; 
    cin >> b; 
    cout << "a = " << a
         << "; b = " << b
         << "; c = " << sqrt(a*a + b*b) << endl;
    return 0;
} 