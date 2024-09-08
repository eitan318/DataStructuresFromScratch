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

    void insert(T value) override;
    void remove(T value) override;
    void in_order_traversal() override;
    void pre_order_traversal() override;
    void post_order_traversal() override;
    void level_order_traversal() override;

    T find_min() override;
    T find_max() override;
    int height() override;
    int size() override;
    bool is_empty() override;
    std::optional<int> search(T value) override;

private:
    void in_order_traversal(int index);
    void pre_order_traversal(int index);
    void post_order_traversal(int index);
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
void ArrayBasedBinaryTree<T>::insert(T value) {
    if (currentSize < capacity) {
        tree[currentSize++] = value;
    } else {
        std::cout << "Tree is full\n";
    }
}

template <typename T>
void ArrayBasedBinaryTree<T>::remove(T value) {
    int index = -1;
    for (int i = 0; i < currentSize; i++) {
        if (tree[i] == value) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        tree[index] = tree[--currentSize];
    } else {
        std::cout << "Value not found in the tree.\n";
    }
}

template <typename T>
void ArrayBasedBinaryTree<T>::in_order_traversal(int index) {
    if (index >= currentSize) return;
    in_order_traversal(2 * index + 1);
    std::cout << tree[index] << " ";
    in_order_traversal(2 * index + 2);
}

template <typename T>
void ArrayBasedBinaryTree<T>::pre_order_traversal(int index) {
    if (index >= currentSize) return;
    std::cout << tree[index] << " ";
    pre_order_traversal(2 * index + 1);
    pre_order_traversal(2 * index + 2);
}

template <typename T>
void ArrayBasedBinaryTree<T>::post_order_traversal(int index) {
    if (index >= currentSize) return;
    post_order_traversal(2 * index + 1);
    post_order_traversal(2 * index + 2);
    std::cout << tree[index] << " ";
}

template <typename T>
void ArrayBasedBinaryTree<T>::in_order_traversal() {
    in_order_traversal(0);
    std::cout << "\n";
}

template <typename T>
void ArrayBasedBinaryTree<T>::pre_order_traversal() {
    pre_order_traversal(0);
    std::cout << "\n";
}

template <typename T>
void ArrayBasedBinaryTree<T>::post_order_traversal() {
    post_order_traversal(0);
    std::cout << "\n";
}

template <typename T>
void ArrayBasedBinaryTree<T>::level_order_traversal() {
    for (int i = 0; i < currentSize; i++) {
        std::cout << tree[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
T ArrayBasedBinaryTree<T>::find_min() {
    // Assuming Binary Search Tree property
    int index = 0;
    while (2 * index + 1 < currentSize) {
        index = 2 * index + 1;
    }
    return tree[index];
}

template <typename T>
T ArrayBasedBinaryTree<T>::find_max() {
    // Assuming Binary Search Tree property
    int index = 0;
    while (2 * index + 2 < currentSize) {
        index = 2 * index + 2;
    }
    return tree[index];
}

template <typename T>
int ArrayBasedBinaryTree<T>::height() {
    return std::floor(std::log2(currentSize));
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
std::optional<int> ArrayBasedBinaryTree<T>::search(T value) {
    for (int i = 0; i < treeSize; ++i) {
        if (tree[i] == value) {
            return i;
        }
    }
    return std::nullopt;  // Return an empty optional if the value is not found
}