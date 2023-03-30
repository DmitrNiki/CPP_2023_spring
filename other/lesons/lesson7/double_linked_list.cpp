#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* next;
    Node* prev;
};

struct List{
    Node* Head;
    Node* Tail;
    Node* NIL;
    size_t size = 0;
};

List* create_empty_List(){
    List* list = new List;
    list->NIL = new Node;
    list->Head = list->NIL;
    list->Tail = list->NIL;
    return list;
}

void push_back();
void push_front();
void insent_after();
void destroy_list();
void destroy_node();
void clear_list();
// Оставляет структуру списка, чтобы им перевоспользоваться
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