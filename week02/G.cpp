#include <iostream>

using namespace std;

int recursive_power(int base, int power){
    if (power > 0){
        return base * recursive_power(base, power - 1);
    } 
   return 1;
}

int num_len(int k){
    int count = 0;

    do{
        k /= 10;
        count++;
    } while (k >= 1);

    return count;
}

int palindrom(int n){
    int flag = 1;
    int x = 0, y = 0;
    for (int i = 1; i <= (num_len(n) / 2) + 1; i++){
        x = ((n % recursive_power(10, i)) / recursive_power(10, i - 1));
        y = ((n / recursive_power(10, num_len(n) - i)) % 10);
        if (x != y){
            flag = 0;
        }
    }
    return flag;
}   

int main(){
    int x;

    cin >> x;

    cout << num_len(x) << endl;

    if (palindrom(x)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}