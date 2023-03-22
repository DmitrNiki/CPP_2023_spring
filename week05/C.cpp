#include <iostream>

using namespace std;

int reader(int* a){
    int iter = 1;
    int x1 = 0;
    cin >> *(a + iter - 1);
    cin >> *(a + iter);
    do{ 
        cin >> x1; 
        *(a + ++iter) = x1;
    }while (x1 != 0);
    return iter;
}

void writer(int* a, int iter){
    for (int i = 0; i < iter - 1; i++){
        cout << *(a + i) - *(a + i + 1) << " ";
    } 
    cout << endl;
}
int main(){
    int i = 0;
    int* a = new int;
    i = reader(a);
    writer(a, i);
    
    return 1;
}

