#include <iostream>

using std::cout;
using std::endl;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

void insert_after(Node*& head_ref, int new_key){
    if (head_ref == nullptr){
        return;
    }
    Node* new_el = new Node;
    new_el->next = head_ref->next;
    new_el->key = new_key;
    head_ref->next = new_el;
}

int main() {
  Node* HEAD = new Node;
  insert_after(HEAD, 0);
  insert_after(HEAD, 1);
  insert_after(HEAD, 2);
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