#include <iostream>

using namespace std;

long long int grasshopper(int n){
    long long int jump[3] = {1, 1, 2};

    if (n <= 2) return jump[n];

    for (int i = 3; i <= n; i++)
        jump[i % 3] = jump[i%3] + jump[(i + 1)%3] + jump[(i + 2)%3];

    return jump[n % 3];
}

int main(){
    int n;
    cin >> n;

    if (n >= 1 && n <= 60) cout << grasshopper(n) << endl;
    return 0;
}