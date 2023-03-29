#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Student
{
    string name;
    int mark;
};

void swap(Student &lha, Student &rha) {
    Student tmp = lha;
    lha         = rha;
    rha         = tmp;
}

void sort(Student *arr, int len) {
    int i = 1;
    int j = 0;
    while (i < len) {
        j = i;
        while ((j >= 1) and (arr[j].mark < arr[j - 1].mark)) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
        j = i;
        while ((j >= 1) and (arr[j].mark == arr[j - 1].mark) and (arr[j].name < arr[j - 1].name)) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
        i++;
    }
}

int main() {
    int M   = 0;
    int N   = 0;
    int cnt = 0;

    cin >> N;

    Student *students = new Student[N];
    for (int i = 0; i < N; i++) {
        cin >> students[i].name;
        cin >> students[i].mark;
    }
    cin >> M;
    for (int i = 0; i < N; i++) {
        if (students[i].mark > M) {
            cnt++;
        }
    }

    Student *good_marked = new Student[cnt];
    for (int i = 0; i < cnt; i++) {
        if (students[i].mark > M) {
            good_marked[i] = students[i];
        }
    }
    sort(good_marked, cnt);
    for (int i = 0; i < N; ++i) {
        cout << good_marked[i].name << ' ';
    }
    cout << endl;
    delete[] good_marked;
    delete[] students;
    return 0;
}