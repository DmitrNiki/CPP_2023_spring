#include <iostream>

// и void destroy_list(Node*& head_ptr)

using std::cout;
using std::endl;

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

void destroy_list(Node *&head_ptr) {
    Node *following = new Node;
    if (head_ptr != nullptr) {
        following = head_ptr->next;
    }

    while (head_ptr != nullptr) {
        delete head_ptr;
        head_ptr = following;
        if (following != nullptr) {
            following = following->next;
        }
    }
}

int main() {
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    destroy_list(HEAD);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }
    return 0;
}