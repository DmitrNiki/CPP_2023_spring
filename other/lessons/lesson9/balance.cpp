#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;
};

void input_tree(Node *tree, int key) {
    int flag = 0;
    if (tree == nullptr) {
        Node *new_tree = new Node;
        tree           = new_tree;
        tree->key      = key;
        tree->left     = nullptr;
        tree->right    = nullptr;
        return;
    }

    Node *current = tree;
    Node *prev;

    while (current != nullptr) {
        prev = current;
        if (current->key > key) {
            flag    = 1;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    Node *new_element = new Node;
    current           = new_element;
    current->key      = key;
    current->left     = nullptr;
    current->right    = nullptr;
    if (flag == 1) {
        prev->right = current;
    } else {
        prev->left = current;
    }
}

int main() {
    Node *tree;
    int key;

    std::cin >> key;
    while (key != 0) {
        input_tree(tree, key);
        std::cin >> key;
    }

    return 0;
}