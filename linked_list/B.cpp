#include <iostream>

using std::cout;
using std::endl;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        head->next = nullptr;
        return;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head;
    head = new_node;
}

int main() {
  Node* HEAD = nullptr;
  push_front(HEAD, 2);
  push_front(HEAD, 1);
  push_front(HEAD, 0);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}
