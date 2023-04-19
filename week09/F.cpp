#include <iostream>

using namespace std;

struct lecture{
    int begin;
    int end;
};

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void heaper(lecture arr[], int i, int size){
    int parent = i;
    int l_child = 2*i + 1;
    int r_child = 2*i + 2;

    if (l_child < size && arr[l_child].end > arr[parent].end){
        parent = l_child;
    }

    if (r_child < size && arr[r_child].end > arr[parent].end){
        parent = r_child;
    }

    if (parent != i){
        swap(arr[parent], arr[i]);
        heaper(arr, parent, size);
    }
}

void cheops_sort(lecture arr[], int N){
    for (int i = N/2 + 1; i >= 0; i--){
        heaper(arr, i, N);
    }
    for (int k = N - 1; k >= 0; k--){
        swap(arr[0], arr[k]);
        heaper(arr, 0, k);
    }
}

int zhadina(lecture a[], int N, int ma_b){
    int cnt = 0;
    int time = 0;
    int idx = 0;

    while (time <= ma_b){
        if (time <= a[idx].begin){
            time = a[idx].end;
            cnt++;
        } 
        idx++;
    }
    return cnt;
}

int main(){
    int N;
    int max_begin = 0;
    cin >> N;

    lecture arr[N];

    for (int i = 0; i < N; i++){
        cin >> arr[i].begin;
        if (arr[i].begin > max_begin) max_begin = arr[i].begin;
        cin >> arr[i].end; 
    }
    
    cheops_sort(arr, N);
    cout << zhadina(arr, N, max_begin) << endl;

    return 0;
}