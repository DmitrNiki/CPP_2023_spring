#include <iostream>

using namespace std;

void Zhadina(int m, int n){
    int up = 0;
    int down = 1;
    int a = 2;

    while(n * up != m * down){
        if (n * (a * up + down) <= m * a * down){
            up = a * up + down;
            down *= a;
            cout << a << ' ';
        }
        a++;
    }

    cout << endl;
}

int main(){
    int M;
    int N;

    cin >> M;
    cin >> N;
    Zhadina(M, N);
    return 0;
}