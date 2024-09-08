#pragma once
#ifndef QUEUESLL_H
#define QUEUESLL_H

#include "SinglyLinkedList.h"

template <typename T>
class Queue {
private:
    SinglyLinkedList<T>* list;  // Pointer to the singly linked list

public:
    Queue();
    ~Queue();

    void enqueue(T data);  // Add element to the end of the queue
    T dequeue();           // Remove and return element from the front of the queue
    void display();        // Display the elements in the queue
    T front();             // Return the element at the front of the queue
    T rear();              // Return the element at the rear of the queue
    bool isEmpty();        // Check if the queue is empty
    int size();            // Return the size of the queue
};

#endif // !QUEUESLL_H

template <typename T>
Queue<T>::Queue() {
    this->list = new SinglyLinkedList<T>();
}

template <typename T>
Queue<T>::~Queue() {
    delete this->list;
}

template <typename T>
void Queue<T>::enqueue(T data) {
    this->list->add_end(data);  // Add element to the end of the queue
}

template <typename T>
T Queue<T>::dequeue() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T frontData = this->list->get(0);  // Get the front element
    this->list->remove_at(0);          // Remove the front element
    return frontData;
}

template <typename T>
T Queue<T>::front() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return this->list->get(0);  // Return the front element
}

template <typename T>
T Queue<T>::rear() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return this->list->get_last();  // Return the rear element
}

template <typename T>
bool Queue<T>::isEmpty() {
    return this->list->Count() == 0;  // Check if the queue is empty
}

template <typename T>
int Queue<T>::size() {
    return this->list->Count();  // Return the size of the queue
}

template <typename T>
void Queue<T>::display() {
    this->list->print();  // Display the elements in the queue
}
