#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void heaper(int (&arr)[], int i, int size){
    int parent = i;
    int l_child = 2*i + 1;
    int r_child = 2*i + 2;

    if (l_child < size && arr[l_child] > arr[parent]){
        parent = l_child;
    }

    if (r_child < size && arr[r_child] > arr[parent]){
        parent = r_child;
    }

    if (parent != i){
        swap(arr[parent], arr[i]);
        heaper(arr, parent, size);
    }
}

void cheops_sort(int (&arr)[], int N){
    for (int i = N/2 + 1; i >= 0; i--){
        heaper(arr, i, N);
    }
    for (int k = N - 1; k >= 0; k--){
        swap(arr[0], arr[k]);
        heaper(arr, 0, k);
    }
}

int effectivness(int num) {
    int a[num];
    int sort[num];
    int max    = 0;
    int min    = num;
    int r      = num - 1;
    int l      = 0;
    int idx_ma = r;
    int idx_mi = 0;

    for (int i = 0; i < num; i++) {
        cin >> a[i];
        sort[i] = a[i];
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    cheops_sort(sort, num);

    while (a[r] == min || a[l] == min || a[r] == max || a[l] == max) {
        if (r <= l) return 0;
        if (a[r] == min){
            r--;
            min = sort[++idx_mi];
        }
        if (a[r] == max){
            r--;
            max = sort[--idx_ma];
        }
        if (a[l] == min){
            l++;
            min = sort[++idx_mi];
        }
        if (a[l] == max){
            l++;
            max = sort[--idx_ma];
        }
    }

    return r - l;
}

int main() {
    int cnt = 0;
    int num = 0;

    cin >> cnt;
    int N = cnt;

    int a[cnt];

    while (cnt > 0) {
        cin >> num;
        a[N - cnt] = effectivness(num);
        cnt--;
    }

    for (int i = 0; i < N; i++)
        cout << a[i] << endl;

    return 0;
}