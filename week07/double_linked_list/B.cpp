#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct List
{
    Node *HEAD  = nullptr;
    Node *TAIL  = nullptr;
    Node *NIL   = nullptr;
    size_t size = 0;
};

List *create_empty_list() {
    List *list = new List;
    Node *NIL  = new Node;
    list->NIL  = NIL;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

using std::cout;
using std::endl;

int main() {
    List *list = create_empty_list();
    if ((list->HEAD == list->NIL) and (list->TAIL == list->NIL) and (list->NIL != nullptr)) {
        cout << "OK" << endl;
    }
    delete list->NIL;
    delete list;
    return 0;
}