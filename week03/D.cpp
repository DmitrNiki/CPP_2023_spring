    #include <iostream>

    #ifndef N
    #define N 10  // actual size of the array
    #endif

    using namespace std;

    void swap(int &lha, int &rha){
        int tmp = lha;
        lha = rha;
        rha = tmp;
    }

    void arr_input(int (&arr)[N]){
        for (int i = 0; i < N; i++){
            cin >> arr[i];
        }
    }

    void arr_changer(int (&arr)[N]){
        for (int i = 0; i < N - 1; i++){
            if (arr[i] < 0 && arr[i + 1] >= 0){
                swap(arr[i], arr[i + 1]);
                i = -1;
            }
        }
    }

    void arr_output(int (&arr)[N]){
        for (int i = 0; i < N; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }

    int main() {
        int a[N] = {};  // array initialization
        arr_input(a);
        arr_changer(a);
        arr_output(a);
        return 0;
    }