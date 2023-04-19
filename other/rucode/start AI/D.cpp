#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int price;
    int quality;
    int n;
};

int checker(Node* a, int num, int p, int q){
    int cnt = 0;
    for (int i = 0; i < num; i++){
        cin >> a[i].n;
        cin >> a[i].price;
        cin >> a[i].quality;
        if (a[i].price < p && a[i].quality > q) cnt += a[i].n;
    }
    return cnt;
}

int main(){
    int num = 0;
    int pric = 0;
    int qual = 0;

    cin >> num;
    cin >> pric;
    cin >> qual;

    Node* a[num + 1];


    cout << checker(a, num, pric, qual) << endl;

    return 0;
}