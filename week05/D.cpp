#include <iostream>

using namespace std;

void input_array(int* ptr, size_t N){
    for (int i = 0; i < N; i++){
        cin >> ptr[i];
    }
}

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void reverse(int* ptr, size_t N){
    for (int i = 0; i < N/2 + 1; i++){
        swap(ptr[i], ptr[N - 1 - i]);
    }
}
void print(const int* ptr, size_t N){
    for (int i = 0; i < N; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N = 0;
    cin >> N;
    int* ptr = new int [N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    return 0;
}