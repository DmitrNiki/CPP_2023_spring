#include <iostream>

using namespace std;

int Zhadina(int N, int k, int a[], int S){
    int cnt = 0; 
    int dist = 0;
    int i = 0;

    while(i < S - 1){
        if (a[i] - dist > k) return -1;
        if (a[i] - dist <= k && a[i + 1] - dist > k){
            dist += a[i] - dist;
            cnt++;
        }
        i++;
    }
    
    if (a[S - 1] - dist <= k){
        cnt++;
        dist += a[S - 1];
    } else return -1;

    return cnt;
}
int main(){
    int k;
    int N;

    int S;
    
    cin >> N;
    cin >> k;

    cin >> S;
    int charge[S];

    for (int i = 0; i < S; i++){
        cin >> charge[i];
    }

    cout << Zhadina(N, k, charge, S) << endl;
    return 0;
}