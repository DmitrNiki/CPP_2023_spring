#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

void push_front(Node *&head, int new_key) {
    if (head == nullptr) {
        head       = new Node;
        head->key  = new_key;
        head->next = nullptr;
        return;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    new_node->next = head;
    head           = new_node;
}

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
    current->next       = new Node;
    current->next->key  = new_key;
    current->next->next = nullptr;
}

void insert_after(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        return;
    }
    Node *new_el   = new Node;
    new_el->next   = head_ref->next;
    new_el->key    = new_key;
    head_ref->next = new_el;
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

void print_list(Node *head_ptr) {
    if (head_ptr == nullptr) {
        std::cout << std::endl;
        return;
    }
    Node *current = head_ptr;
    while (current->next != nullptr) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
}

Node *find(Node *head_ref, int key) {
    if (head_ref == nullptr) {
        return head_ref;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    if (current->key == key) {
        return current;
    } else {
        return nullptr;
    }
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