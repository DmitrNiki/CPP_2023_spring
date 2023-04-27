#include <iostream>

using namespace std;

unsigned long long recur(unsigned long long fib[], int n){
    if (n == 0 || n == 1) return 1;
    else if (n == 2) return 4;

    for (int i = 3; i <= n; i++)
        fib[i % 3] = 2*fib[(i - 1) % 3] + 2*fib[(i - 2) % 3] - fib[i % 3];

    return fib[n % 3];
}

int main(){
    int N;

    cin >> N;
    unsigned long long fib[3] = {1, 1, 4};
    if (0 <= N && N <= 41) cout << recur(fib, N) << endl;
    return 0;
}