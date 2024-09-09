#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <stdbool.h>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr){}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

    static void default_print(T data) {
        std::cout << data << " ";
    }

    Node<T>* find_node_at(int idx);
    std::pair<Node<T>*, Node<T>*> find_nodes_at(int idx1, int idx2);

public:
    int count;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();

    void add_start(T value);
    void add_end(T value);
    void print(void (*print_func)(T) = default_print);
    bool remove_node(T node_data);
    bool remove_fast(T node_data);
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
};

#endif // DOUBLYLINKEDLIST_H

template <typename T>
void DoublyLinkedList<T>::add_start(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (this->head == nullptr) {
        this->head = this->tail = new_node;
    }
    else {
        this->head->prev = new_node;
        new_node->next = this->head;
        this->head = new_node;
    }
    this->count++;
}

template <typename T>
void DoublyLinkedList<T>::add_end(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (this->tail == nullptr) {
        this->head = this->tail = new_node;
    }
    else {
        new_node->prev = this->tail;
        this->tail->next = new_node;
        this->tail = new_node;
    }
    this->count++;
}



template <typename T>
void DoublyLinkedList<T>::print(void (*print_func)(T)) {
    Node<T>* curr = this->head;
    while (curr) {
        print_func(curr->data);
        curr = curr->next;
    }
    std::cout << std::endl;
}


template <typename T>
bool DoublyLinkedList<T>::remove_node(T node_data) {
    if (this->head == nullptr) {
        return false;
    }

    Node<T>* curr = this->head;

    if (curr->data == node_data) {
        this->head = curr->next;
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
    curr->next->prev = prev;
    delete curr;
    this->count--;
    return true;
}

template <typename T>
bool DoublyLinkedList<T>::remove_fast(T node_data) {
    if (this->head == nullptr) {
        return false;  // List is empty
    }

    Node<T>* curr_head = this->head;
    Node<T>* curr_tail = this->tail;

    // Traverse from both ends towards the center
    while (curr_head != curr_tail && curr_head->next != curr_tail && curr_head->data != node_data && curr_tail->data != node_data) {
        curr_head = curr_head->next;
        curr_tail = curr_tail->prev;
    }

    Node<T>* curr = nullptr;

    // Determine which node to remove
    if (curr_head->data == node_data) {
        curr = curr_head;
    }
    else if (curr_tail->data == node_data) {
        curr = curr_tail;
    }
    else {
        return false;  // Node not found
    }

    // Adjust pointers and remove the node
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {  // Node is head
        this->head = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    else {  // Node is tail
        this->tail = curr->prev;
    }

    delete curr;
    this->count--;
    return true;
}


template <typename T>
Node<T>* DoublyLinkedList<T>::find_node_at(int idx) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    if (idx < 0 || idx >= this->count) {
        throw std::out_of_range("Index out of range!");
    }

    Node<T>* curr = nullptr;
    if (idx < this->count / 2) {
        // Start from the head
        curr = this->head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
    }
    else {
        // Start from the tail
        curr = this->tail;
        for (int i = this->count - 1; i > idx; i--) {
            curr = curr->prev;
        }
    }
    return curr;
}

// TODO: fix
template <typename T>
std::pair<Node<T>*, Node<T>*> DoublyLinkedList<T>::find_nodes_at(int idx1, int idx2) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    if (idx1 < 0 || idx1 >= this->count) {
        throw std::out_of_range("Index1 out of range!");
    }
    if (idx2 < 0 || idx2 >= this->count) {
        throw std::out_of_range("Index2 out of range!");
    }
    if (idx1 == idx2) {
        Node<T>* node = this->find_node_at(idx1);
        return std::make_pair(node, node);
    }


    Node<T>* curr_head = this->head;
    Node<T>* curr_tail = this->tail;
    Node<T>* node1 = nullptr;
    Node<T>* node2 = nullptr;

    if (idx1 < this->count / 2 && idx2 < this->count / 2) {
        // Start from the head
        for (int i = 0; i < std::max(idx1,idx2); i++) {
            if (i == std::min(idx1, idx2)) {
                node1 = curr_head;
            }
            curr_head = curr_head->next;
        }
        node2 = curr_head;
    }
    else if (idx1 < this->count / 2 || idx2 < this->count / 2){
        // Start from the head and tail
        int i1 = 0;
        int i2 = count - 1;
        while(i1 != std::min(idx1, idx2) || i2 != std::max(idx1, idx2) ) {
            if (i1 != std::min(idx1, idx2)) {
                i1++;
                curr_head = curr_head->next;
            }
            if (i2 != std::max(idx1, idx2)) {
                i2--;
                curr_tail = curr_tail->prev;
            }
            
        }
        node1 = curr_head;
        node2 = curr_tail;
    }
    else {
        // Start from the tail
        for (int i = this->count - 1; i > std::min(idx1,idx2); i--) {
            if (i == std::max(idx1, idx2)) {
                node2 = curr_tail;
            }
            curr_tail = curr_tail->prev;
        }
        node1 = curr_tail;
    }

    if (!node1 || !node2) {
        throw std::runtime_error("Nodes not found, this should not happen if indices are valid.");
    }

    return idx1 < idx2 ? std::make_pair(node1, node2) : std::make_pair(node2, node1);
}

template <typename T>
T DoublyLinkedList<T>::remove_at(int idx) {
    if (idx < 0 || idx >= this->count) {
        throw std::out_of_range("Index out of range!");
    }

    Node<T>* curr = this->find_node_at(idx);
    if (curr == nullptr) {
        throw std::runtime_error("Node not found!");
    }

    T data = curr->data;

    // Update previous node's next pointer, or head if removing the head
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {
        // Removing the head
        this->head = curr->next;
    }

    // Update next node's previous pointer, or tail if removing the tail
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    else {
        // Removing the tail
        this->tail = curr->prev;
    }

    delete curr;
    this->count--;
    return data;
}

template <typename T>
void DoublyLinkedList<T>::insert_at(T data, int idx) {
    Node<T>* curr = this->find_node_at(idx);

    Node<T>* new_node = new Node<T>(data);
    new_node->next = curr->next;
    new_node->prev = curr;
    curr->next->prev = new_node;
    curr->next = new_node;
    this->count++;
}


template <typename T>
T DoublyLinkedList<T>::get(int idx) {
    Node<T>* curr = this->find_node_at(idx);

    return curr->data;
}

template <typename T>
T DoublyLinkedList<T>::get_last() {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    return this->tail->data;
}


template <typename T>
void DoublyLinkedList<T>::set(int idx, T new_value) {
    Node<T>* curr = this->find_node_at(idx);

    curr->data = new_value;
}



template <typename T>
void DoublyLinkedList<T>::set_last(T new_value) {
    if (this->head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    this->tail->data = new_value;
}


//todo
template <typename T>
void DoublyLinkedList<T>::reverse() {
    if (this->count <= 1) {
        return;  // List is empty
    }
    Node<T>* temp_head = this->head;
    Node<T>* temp_tail = this->tail;
    Node<T>* curr_head = this->head;
    Node<T>* curr_tail = this->tail;

    // Traverse from both ends towards the center
    while (curr_head != curr_tail && curr_head->next != curr_tail) {
        std::swap(curr_head->prev, curr_head->next);
        std::swap(curr_tail->prev, curr_tail->next);
        curr_head = curr_head->prev;
        curr_tail = curr_tail->next;
    }
    if (curr_head != curr_tail) {
        std::swap(curr_head->prev, curr_head->next);
    }
    std::swap(curr_tail->prev, curr_tail->next);

    this->head = temp_tail;
    this->tail = temp_head;
}



//todo
template <typename T>
void DoublyLinkedList<T>::move_node(int idx_from, int idx_to) {
    if (idx_from == idx_to) {
        return;
    }
    auto nodes = this->find_nodes_at(idx_from, idx_to);
    Node<T>* node_to_move = nodes.first;
    //move from origen
    node_to_move->prev->next = node_to_move->next;
    node_to_move->next->prev = node_to_move->prev;

    if (idx_from < idx_to) {
        Node<T>* prev_target = nodes.second;
        //insert after
        prev_target->next->prev = node_to_move;
        node_to_move->next = prev_target->next;
        node_to_move->prev = prev_target;
        prev_target->next = node_to_move;
    }
    else {
        Node<T>* target = nodes.second;
        //insert before
        target->prev->next = node_to_move;
        node_to_move->prev = target->prev;
        node_to_move->next = target;
        target->prev = node_to_move;
    }

}


template <typename T>
void DoublyLinkedList<T>::replace(int idx1, int idx2) {
    if (idx1 == idx2) {
        return; // No need to swap if indices are the same
    }

    auto nodes = this->find_nodes_at(idx1, idx2);
    Node<T>* after_first = nodes.first->next;
    Node<T>* before_first = nodes.first->prev;
    Node<T>* after_second = nodes.second->next;
    Node<T>* before_second = nodes.second->prev;

    // Update pointers of adjacent nodes
    if (after_first != nullptr) {
        after_first->prev = nodes.second;
    }
    else {
        this->tail = nodes.second; // If nodes.first was the tail
    }

    if (before_first != nullptr) {
        before_first->next = nodes.second;
    }
    else {
        this->head = nodes.second; // If nodes.first was the head
    }

    if (after_second != nullptr) {
        after_second->prev = nodes.first;
    }
    else {
        this->tail = nodes.first; // If nodes.second was the tail
    }

    if (before_second != nullptr) {
        before_second->next = nodes.first;
    }
    else {
        this->head = nodes.first; // If nodes.second was the head
    }

    // Finalize swapping nodes
    nodes.first->prev = before_second;
    nodes.second->prev = before_first;
    nodes.first->next = after_second;
    nodes.second->next = after_first;
}



template <typename T>
void DoublyLinkedList<T>::free() {
    Node<T>* temp = this->head;
    while (this->head) {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}



template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    free();
}





