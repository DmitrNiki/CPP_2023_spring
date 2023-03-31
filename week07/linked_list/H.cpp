#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

void push_back(Node *&head, int new_key) {
    if (head == nullptr) {
        head      = new Node;
        head->key = new_key;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next      = new Node;
    current->next->key = new_key;
}

void remove_key(Node *&head_ptr, int key) {
    if (head_ptr == nullptr) {
        return;
    }

    Node *current = head_ptr;
    Node *Next    = current->next;

    if (head_ptr->key == key) {
        delete head_ptr;
        head_ptr = Next;
        return;
    }

    while (Next != nullptr) {
        if (Next->key == key) {
            Next = Next->next;
            delete current->next;
            current->next = Next;
        } else {
            current = Next;
            Next    = Next->next;
        }
    }
}

using std::cout;
using std::endl;

int main() {
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    remove_key(HEAD, 0);
    remove_key(HEAD, 1);
    remove_key(HEAD, 2);
    remove_key(HEAD, 3);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }
    return 0;
}