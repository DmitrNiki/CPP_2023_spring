#include <iostream>
#include <new>

using namespace std;

bool reserve_memory(size_t N, int *&dst){
    dst = (int*) operator new (N, nothrow);
    if (dst == nullptr){
        return false;
    }
    return true;
}
void free_memory(int* ptr){
    if (ptr != nullptr){
        delete []ptr;
    }
}

// HERE your code


int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(N, ptr) << endl;
    free_memory(ptr);
    return 0;
}