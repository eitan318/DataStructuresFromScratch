#include <iostream>
#include <cmath>
#include <queue>
#include "../IBinaryTree.h"

template <typename T>
class ArrayBasedBinaryTree : public IBinaryTree<T, int>  {
private:
    T* tree;
    int currentSize;
    int capacity;

public:
    ArrayBasedBinaryTree(int capacity);
    ~ArrayBasedBinaryTree();

    void depth_first_insert(T value) override;
    void level_order_insert(T value) override;
    void remove(T value) override;
    void in_order_traversal(std::function<bool(int)> func) override;
    void pre_order_traversal(std::function<bool(int)> func) override;
    void post_order_traversal(std::function<bool(int)> func) override;
    void level_order_traversal(std::function<void(int)> func) override;

    T find_min() override;
    T find_max() override;
    int height() override;
    int size() override;
    bool is_empty() override;
    int search(T value) override;

private:
    void in_order_traversal(int index, std::function<bool(int)> func);
    void pre_order_traversal(int index, std::function<bool(int)> func);
    void post_order_traversal(int index, std::function<bool(int)> func);
};

template <typename T>
ArrayBasedBinaryTree<T>::ArrayBasedBinaryTree(int capacity) {
    this->capacity = capacity;
    this->currentSize = 0;
    this->tree = new T[capacity];
}

template <typename T>
ArrayBasedBinaryTree<T>::~ArrayBasedBinaryTree() {
    delete[] this->tree;
}


template <typename T>
void ArrayBasedBinaryTree<T>::remove(T value) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::in_order_traversal(int index, std::function<bool(int)> func) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::pre_order_traversal(int index, std::function<bool(int)> func) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::post_order_traversal(int index, std::function<bool(int)> func) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::in_order_traversal(std::function<bool(int)> func) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::pre_order_traversal(std::function<bool(int)> func) {

}

template <typename T>
void ArrayBasedBinaryTree<T>::post_order_traversal(std::function<bool(int)> func) {
}

template <typename T>
void ArrayBasedBinaryTree<T>::level_order_traversal(std::function<void(int)> func) {

}

template <typename T>
T ArrayBasedBinaryTree<T>::find_min() {

}

template <typename T>
T ArrayBasedBinaryTree<T>::find_max() {

}

template <typename T>
int ArrayBasedBinaryTree<T>::height() {

}

template <typename T>
int ArrayBasedBinaryTree<T>::size() {
    return currentSize;
}

template <typename T>
bool ArrayBasedBinaryTree<T>::is_empty() {
    return currentSize == 0;
}

template <typename T>
void depth_first_insert(T value){

}

template <typename T>
void level_order_insert(T value){

}

template <typename T>
int ArrayBasedBinaryTree<T>::search(T value) {
    for (int i = 0; i < currentSize; ++i) {
        if (tree[i] == value) {
            return i;
        }
    }
    return -1; 
}
