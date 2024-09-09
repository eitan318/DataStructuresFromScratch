#include "../IBinaryTree.h"
#include <queue>

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;
    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class NodeBasedBinaryTree : public IBinaryTree<T, Node<T>*> {
public:
    NodeBasedBinaryTree();                     // Constructor
    ~NodeBasedBinaryTree();                    // Destructor

    void insert(T value) override;
    void remove(T value) override;

    Node<T>* search(T value) override;
    void in_order_traversal() override;
    void pre_order_traversal() override;
    void post_order_traversal() override;
    void level_order_traversal() override;

    T find_min() override;
    T find_max() override;
    int height() override;
    int size() override;
    bool is_empty() override;

private:
    Node<T>* root;                   // Root node
    int node_count;                 // Number of nodes in the tree

    void clear(Node<T>* node);       // Helper function to clear nodes
    int height(Node<T>* node);       // Helper function to calculate height
    void in_order_traversal(Node<T>* node); // Helper function for in-order traversal
    void pre_order_traversal(Node<T>* node); // Helper function for pre-order traversal
    void post_order_traversal(Node<T>* node); // Helper function for post-order traversal
    void level_order_traversal(Node<T>* node); // Helper function for level-order traversal
    Node<T>* find_min_node(Node<T>* node); // Helper function to find the minimum node
    Node<T>* find_max_node(Node<T>* node); // Helper function to find the maximum node
    Node<T>* remove(Node<T>* node, T value); // Helper function to remove a node
};

// Constructor
template <typename T>
NodeBasedBinaryTree<T>::NodeBasedBinaryTree() : root(nullptr), node_count(0) {}

// Destructor
template <typename T>
NodeBasedBinaryTree<T>::~NodeBasedBinaryTree() {
    clear(root);
}

// Insert a value
template <typename T>
void NodeBasedBinaryTree<T>::insert(T value) {

}

// Remove a value
template <typename T>
void NodeBasedBinaryTree<T>::remove(T value) {

}

// Search for a value
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::search(T value) {

}

// In-order traversal
template <typename T>
void NodeBasedBinaryTree<T>::in_order_traversal() {
    in_order_traversal(root);
}

// Pre-order traversal
template <typename T>
void NodeBasedBinaryTree<T>::pre_order_traversal() {
    pre_order_traversal(root);
}

// Post-order traversal
template <typename T>
void NodeBasedBinaryTree<T>::post_order_traversal() {
    post_order_traversal(root);
}

// Level-order traversal
template <typename T>
void NodeBasedBinaryTree<T>::level_order_traversal() {
    level_order_traversal(root);
}

// Find minimum value
template <typename T>
T NodeBasedBinaryTree<T>::find_min() {
    Node<T>* minNode = find_min_node(root);
    return minNode ? minNode->value : T{};
}

// Find maximum value
template <typename T>
T NodeBasedBinaryTree<T>::find_max() {
    Node<T>* maxNode = find_max_node(root);
    return maxNode ? maxNode->value : T{};
}

// Calculate height
template <typename T>
int NodeBasedBinaryTree<T>::height() {
    return height(root);
}

// Get the size of the tree
template <typename T>
int NodeBasedBinaryTree<T>::size() {
    return node_count;
}

// Check if the tree is empty
template <typename T>
bool NodeBasedBinaryTree<T>::is_empty() {
    return root == nullptr;
}

// Helper functions

// Clear nodes
template <typename T>
void NodeBasedBinaryTree<T>::clear(Node<T>* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Calculate height of a node
template <typename T>
int NodeBasedBinaryTree<T>::height(Node<T>* node) {
    if (!node) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

// In-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::in_order_traversal(Node<T>* node) {
    if (node) {
        in_order_traversal(node->left);
        std::cout << node->value << " ";
        in_order_traversal(node->right);
    }
}

// Pre-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::pre_order_traversal(Node<T>* node) {
    if (node) {
        std::cout << node->value << " ";
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }
}

// Post-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::post_order_traversal(Node<T>* node) {
    if (node) {
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        std::cout << node->value << " ";
    }
}

// Level-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::level_order_traversal(Node<T>* node) {
    if (!node) return;
    std::queue<Node<T>*> q;
    q.push(node);
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        std::cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Find minimum node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::find_min_node(Node<T>* node) {

}

// Find maximum node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::find_max_node(Node<T>* node) {

}

// Remove a node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::remove(Node<T>* node, T value) {

}
