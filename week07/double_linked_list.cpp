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
    list->NIL->next = NIL;
    list->NIL->prev = NIL;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

List* push_back(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        create_empty_list();
    }
    Node *NEW = new Node;
    NEW->key  = new_key;
    if (list_ptr->HEAD == list_ptr->NIL && list_ptr->TAIL == list_ptr->NIL){
        NEW->next = list_ptr->NIL;
        NEW->prev = list_ptr->NIL;
        list_ptr->HEAD = NEW;
        list_ptr->TAIL = NEW;
    } else {
        NEW->prev = list_ptr->TAIL;
        NEW->next = list_ptr->NIL;
        list_ptr->TAIL->next = NEW;
        list_ptr->TAIL = NEW;
    }
    list_ptr->size++;
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    if (list_ptr == nullptr || prev_ptr == nullptr){
        return list_ptr;
    }
    Node *NEW = new Node;
    NEW->key  = new_key;
    if (list_ptr->HEAD == list_ptr->NIL && list_ptr->TAIL == list_ptr->NIL){
        NEW->next = list_ptr->NIL;
        NEW->prev = list_ptr->NIL;
        list_ptr->HEAD = NEW;
        list_ptr->TAIL = NEW;
    } else{
        Node *Next = prev_ptr->next;
        prev_ptr->next = NEW;
        NEW->next = Next;
    } 
    if (prev_ptr == list_ptr->TAIL){
        list_ptr->TAIL = NEW;
    }    
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    if (list_ptr->HEAD == list_ptr->TAIL){
        std::cout << list_ptr->HEAD->key << std::endl;
        return;
    }
    Node* current = list_ptr->HEAD;
    while(current->next != list_ptr->NIL){
        std::cout<< current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
}

void clear_list(List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    
    Node* current = list_ptr->HEAD;

    while (current != list_ptr->TAIL){
        Node* Next = current->next;
        delete current;
        list_ptr->size--;
        current = Next;
    }

    delete current;
    list_ptr->size--;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
}

void destroy_list(List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    
    Node* current = list_ptr->HEAD;

    while (current != list_ptr->TAIL){
        Node* Next = current->next;
        delete current;
        list_ptr->size--;
        current = Next;
    }

    delete current;
    list_ptr->size--;
    delete list_ptr->NIL;
    delete list_ptr;
}

Node* find_key(List* list_ptr, int key){
    Node* current = list_ptr->HEAD;

    while(current != list_ptr->NIL){
        if(current->key == key){
            return current;
        }
        current=current->next;
    }
    return current;
}

void remove_key(List* list_ptr, int key){
    if (list_ptr == nullptr){
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL){
        return;
    }
    int flag = 0;
    if (list_ptr->HEAD->key == key){
        if (list_ptr->HEAD->next == list_ptr->NIL){
            delete list_ptr->HEAD;
            list_ptr->size--;
            list_ptr->HEAD = list_ptr->NIL;
            list_ptr->TAIL = list_ptr->NIL;
            return;
        }
        Node* New_Head = list_ptr->HEAD->next;
        delete list_ptr->HEAD;
        list_ptr->size--;
        New_Head->prev = list_ptr->NIL;
        list_ptr->HEAD = New_Head;
        return;
    }
    Node* current = list_ptr->HEAD;

    while(current != list_ptr->NIL){
        if(current->key == key){
            if(current == list_ptr->TAIL){
                flag = 1;
            }
            Node* Prev = current->prev;
            Node* Next = current->next;
            delete current;
            list_ptr->size--;
            Prev->next = Next;
            Next->prev = Prev;
            if (flag == 1){
                list_ptr->TAIL = Prev;
            }
            return;
        }
        current=current->next;
    }
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  Node* ptr = nullptr;
  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  ptr = find_key(list, 2);
  if (ptr == list->TAIL) {
    cout << "OK" << endl;
  }
  destroy_list(list);
  return 0;
}