#include "BinaryTree.h"


template <typename T>
struct Node {
    T data;       // Data held by the node
    Node* left;   // Pointer to the left child
    Node* right;  // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};



template <typename T>
class BinaryTree
{
    private:
        Node<T>* root;
        addRecursieve(Node<T>* current, T value) {
            if (current == NULL) {
                return new Node(value);
            }

            if(current->data < )
        }

    public:
        BinaryTree() : root(nullptr) {}

        add(T value) {
            root = addRecursive(root, value);
        }
	    

    

};
