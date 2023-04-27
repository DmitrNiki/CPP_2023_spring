#include <iostream>

using namespace std;

int main(){
    int l;
    cin >> l;

    int money = 0;
    int max_price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};
    int count_rods[10] = {0};

    for(int i = 0; i < 10; i++){

        while(l + i >= 10){
            money += max_price[i];
            l -= 10 - i;
            switch(i){
                case 0: count_rods[9]++; break;
                case 1: count_rods[5]++; count_rods[2]++; break;
                case 2: count_rods[5]++; count_rods[1]++; break;
                case 3: count_rods[5]++; count_rods[0]++; break;
                case 4: count_rods[5]++; break;
                case 5: count_rods[1]++; count_rods[2]++; break;
                case 6: count_rods[1] += 2; break;
                case 7: count_rods[2]++; break;
                case 8: count_rods[1]++; break;
                case 9: count_rods[0]++; break;
            }
        }
    }

    int cnt = 0;
    while(cnt != 10){
        for (int i = count_rods[cnt]; i > 0; i--){
            if (cnt == 9 && i == 1) {
                cout << cnt + 1 << endl;
                count_rods[cnt]--;
                break;
            } 
            count_rods[cnt]--;
            cout << cnt + 1 << ' ';
        }
        cnt++;
    }
    return 0;
}