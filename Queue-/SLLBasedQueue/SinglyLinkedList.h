#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdexcept>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
    Node<T>* reverse_recursive(Node<T>* curr);

    static void default_print(T data) {
        std::cout << data << " ";
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~SinglyLinkedList();

    void add_start(T value);
    void add_end(T value);
    void print(void (*print_func)(T) = default_print);
    bool remove_node(T node_data);
    T remove_at(int idx);
    void insert_at(T data, int idx);
    void reverse();
    T get(int idx);
    T get_last();
    void set(int idx, T new_value);
    void set_last(T new_value);
    void move_node(int idxFrom, int idxTo);
    void replace(int one_idx, int second_idx);
    void free();
    int Count();
    bool is_empty();
};

#endif // LINKEDLIST_H

template <typename T>
Node<T>* SinglyLinkedList<T>::reverse_recursive(Node<T>* curr) {
    if (curr == nullptr || curr->next == nullptr) {
        return curr;
    }
    Node<T>* new_head = reverse_recursive(curr->next);
    curr->next->next = curr;
    curr->next = nullptr;
    return new_head;
}

template <typename T>
void SinglyLinkedList<T>::add_start(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (this->head == nullptr) {
        this->head = this->tail = new_node;
    }
    else {
        new_node->next = this->head;
        this->head = new_node;
    }
    this->count++;
}

template <typename T>
void SinglyLinkedList<T>::add_end(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (this->tail == nullptr) {
        this->head = this->tail = new_node;
    }
    else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    this->count++;
}

template <typename T>
void SinglyLinkedList<T>::print(void (*print_func)(T)) {
    Node<T>* curr = this->head;
    while (curr) {
        print_func(curr->data);
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool SinglyLinkedList<T>::remove_node(T node_data) {
    if (this->head == nullptr) {
        return false;
    }

    Node<T>* curr = this->head;

    if (curr->data == node_data) {
        this->head = curr->next;
        if (curr == this->tail) {
            this->tail = nullptr;
        }
        delete curr;
        this->count--;
        return true;
    }

    Node<T>* prev = nullptr;

    while (curr != nullptr && !(curr->data == node_data)) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false;
    }

    prev->next = curr->next;
    if (curr == this->tail) {
        this->tail = prev;
    }
    delete curr;
    this->count--;
    return true;
}

template <typename T>
T SinglyLinkedList<T>::remove_at(int idx) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    if (idx < 0 || idx >= this->count) {
        throw std::out_of_range("Index out of range!");
    }

    Node<T>* curr = this->head;
    T curr_data;

    if (idx == 0) {
        this->head = curr->next;
        curr_data = curr->data;
        if (curr == this->tail) {
            this->tail = nullptr;
        }
        delete curr;
        this->count--;
        return curr_data;
    }

    Node<T>* prev = nullptr;

    for (int i = 0; i < idx && curr; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr_data = curr->data;
    if (curr == this->tail) {
        this->tail = prev;
    }
    delete curr;
    this->count--;
    return curr_data;
}

template <typename T>
void SinglyLinkedList<T>::insert_at(T data, int idx) {
    Node<T>* new_node = new Node<T>(data);

    if (this->head == nullptr && idx > 0) {
        delete new_node;
        throw std::runtime_error("An error occurred!");
    }

    Node<T>* curr = this->head;
    Node<T>* prev = nullptr;

    if (idx == 0) {
        new_node->next = this->head;
        this->head = new_node;
        if (this->tail == nullptr) {
            this->tail = new_node;
        }
        this->count++;
        return;
    }

    int i;
    for (i = 0; i < idx && curr != nullptr; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (i != idx) {
        delete new_node;
        throw std::runtime_error("Error: Index out of bounds.");
    }

    prev->next = new_node;
    new_node->next = curr;
    if (new_node->next == nullptr) {
        this->tail = new_node;
    }
    this->count++;
}

template <typename T>
T SinglyLinkedList<T>::get(int idx) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }

    Node<T>* curr = this->head;

    for (int i = 0; i < idx && curr; i++) {
        curr = curr->next;
    }

    if (!curr) {
        throw std::runtime_error("Index is out of bounds!");
    }

    return curr->data;
}

template <typename T>
T SinglyLinkedList<T>::get_last() {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    return tail->data;
}

template <typename T>
void SinglyLinkedList<T>::set(int idx, T new_value) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }

    Node<T>* curr = this->head;

    for (int i = 0; i < idx && curr; i++) {
        curr = curr->next;
    }

    if (!curr) {
        throw std::runtime_error("Index is out of bounds!");
    }

    curr->data = new_value;
}

template <typename T>
void SinglyLinkedList<T>::set_last(T new_value) {
    if (this->tail == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    this->tail->data = new_value;
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    this->head = reverse_recursive(this->head);
    if (this->head != nullptr) {
        Node<T>* curr = this->head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        this->tail = curr;
    }
}

template <typename T>
void SinglyLinkedList<T>::move_node(int idxFrom, int idxTo) {
    if (idxFrom == idxTo || idxFrom < 0 || idxTo < 0 || idxFrom >= this->count || idxTo >= this->count) {
        return;
    }

    Node<T>* prevFrom = nullptr;
    Node<T>* nodeFrom = this->head;

    for (int i = 0; i < idxFrom; i++) {
        prevFrom = nodeFrom;
        nodeFrom = nodeFrom->next;
    }

    // Remove nodeFrom from its position
    if (prevFrom != nullptr) {
        prevFrom->next = nodeFrom->next;
    }
    else {  // nodeFrom is head
        this->head = nodeFrom->next;
    }
    if (nodeFrom == this->tail) {
        this->tail = prevFrom;
    }

    if (idxTo == 0) {
        // Insert at the head
        nodeFrom->next = this->head;
        this->head = nodeFrom;
    }
    else {
        Node<T>* prevTo = nullptr;
        Node<T>* nodeTo = this->head;
        for (int i = 0; i < idxTo; i++) {
            prevTo = nodeTo;
            nodeTo = nodeTo->next;
        }
        prevTo->next = nodeFrom;
        nodeFrom->next = nodeTo;
        if (nodeTo == nullptr) {
            this->tail = nodeFrom;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::replace(int one_idx, int second_idx) {
    if (one_idx == second_idx || one_idx < 0 || second_idx < 0 || one_idx >= this->count || second_idx >= this->count) {
        return;
    }

    Node<T>* prev_one = nullptr;
    Node<T>* node_one = this->head;

    for (int i = 0; i < one_idx; i++) {
        prev_one = node_one;
        node_one = node_one->next;
    }

    Node<T>* prev_two = nullptr;
    Node<T>* node_two = this->head;

    for (int i = 0; i < second_idx; i++) {
        prev_two = node_two;
        node_two = node_two->next;
    }

    if (prev_one != nullptr) {
        prev_one->next = node_two;
    }
    else {  // node_one is head
        this->head = node_two;
    }

    if (prev_two != nullptr) {
        prev_two->next = node_one;
    }
    else {  // node_two is head
        this->head = node_one;
    }

    // Swap next pointers
    Node<T>* temp = node_one->next;
    node_one->next = node_two->next;
    node_two->next = temp;

    // Handle tail pointer if needed
    if (node_one->next == nullptr) {
        this->tail = node_one;
    }
    else if (node_two->next == nullptr) {
        this->tail = node_two;
    }
}

template <typename T>
void SinglyLinkedList<T>::free() {
    Node<T>* curr = this->head;
    Node<T>* temp;
    while (curr) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    this->head = this->tail = nullptr;
    this->count = 0;
}

template <typename T>
int SinglyLinkedList<T>::Count() {
    return this->count;
}

template <typename T>
bool SinglyLinkedList<T>::is_empty() {
    return this->count == 0;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    free();
}


