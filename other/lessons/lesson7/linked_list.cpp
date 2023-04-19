#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* next;
};

void push_back(Node* head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
}

void push_front(Node* head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head;
}

void insent_after();
void destroy_list();
void destroy_node();
void print_list();
Node find_index();
Node find_key();

int main(){
    Node* head = new Node;
    head -> key = 0;
    head -> next = nullptr;
    delete[] head; 
    return 1;
}