#include <iostream>

using namespace std;

struct palka{
    int len;
    int cost;
    double cpl;
};

int easy_money(palka tabl[], int len){
    int money = 0;
    int alen = len;
    // alen - actual lenght 
    while (alen >= 20){
        if (alen >= tabl[9].len){
            alen -= tabl[9].len;
            money += tabl[9].cost;
        }
    }

    return money;
}

int main(){
    int l;
    cin >> l;

    palka table[10];
    table[0].cost = 1;
    table[1].cost = 5;
    table[2].cost = 8;
    table[3].cost = 9;
    table[4].cost = 10;
    table[5].cost = 17;
    table[6].cost = 17;
    table[7].cost = 20;
    table[8].cost = 24;
    table[9].cost = 30;
    for (int i = 0; i < 10; i++) {
        table[i].len = i + 1;
        table[i].cpl = table[i].cost/table[i].len;
    }

    if (l <= 500 && l >= 0) cout << easy_money(table, l) << endl;
    return 0;
}