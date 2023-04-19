#include <iostream>

using namespace std;

int Zhadina(int N, int a[], int m){
    int c = 0; 
    int k = 0;
    while(c != m){
        for (int i = N - 1; i >= 0; i--){
            if (c + a[i] <= m){
                c += a[i];
                k++;
                break;
            }
        }
    }

    return k;
}
int main(){
    int M;
    int N;

    cin >> N;
    int money[N];

    for (int i = 0; i < N; i++){
        cin >> money[i];
    }
    cin >> M;
    cout << Zhadina(N, money, M) << endl;
    return 0;
}