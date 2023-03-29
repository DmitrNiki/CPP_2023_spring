#include <cstring>
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int mark;
};

int main() {
    int M = 0;

    Student *students = new Student[10];
    for (int i = 0; i < 10; i++) {
        cin >> students[i].name;
        cin >> students[i].mark;
    }
    cin >> M;
    for (int i = 0; i < 10; i++) {
        if (students[i].mark > M) {
            cout << students[i].name << ' ';
        }
    }
    cout << endl;
    delete[] students;
}