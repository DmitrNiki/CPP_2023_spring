#include <iostream>

using namespace std;

int Zhadina(int a[6], int m){
    int c = 0; 
    int k = 0;
    while(c != m){
        for (int i = 5; i >= 0; i--){
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
    int money[] = {1, 7, 28, 49, 63, 98};
    int M;

    cin >> M;
    cout << Zhadina(money, M) << endl;
    return 0;
}