#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;
};

void input_tree(Node *tree, int key) {
    if (tree == nullptr) {
        Node *new_tree = new Node;
        tree           = new_tree;
        tree->key      = key;
        tree->left     = nullptr;
        tree->right    = nullptr;
    }

    Node *current = tree;

    while (current != nullptr) {
        if (current->key == key) return;
        if (current->key > key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    Node *new_element = new Node;
    current           = new_element;
}

int main() { return 0; }