#include "../IBinaryTree.h"

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class NodeBasedBinaryTree : public IBinaryTree<T, Node<T>*>{
public:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    NodeBasedBinaryTree();                     // Constructor
    ~NodeBasedBinaryTree();                    // Destructor

    void insert(T value) override;
    void remove(T value) override;
    
    std::optional<Node<T>*> search(T value) override
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
    Node* root;                   // Root node
    int node_count;                   // Number of nodes in the tree
    void clear(Node* node);       // Helper function to clear nodes
    int height(Node* node);       // Helper function to calculate height
    void in_order_traversal(Node* node); // Helper function for in-order traversal
    // Other private utility methods...
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
    // Empty implementation
}

// Remove a value
template <typename T>
void NodeBasedBinaryTree<T>::remove(T value) {
    // Empty implementation
}

// Search for a value
template <typename T>
std::optional<Node<T>*> NodeBasedBinaryTree<T>::search(T value) {
    // Empty implementation
    return std::nullopt;
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
    // Empty implementation
    return T{};
}

// Find maximum value
template <typename T>
T NodeBasedBinaryTree<T>::find_max() {
    // Empty implementation
    return T{};
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
    // Empty implementation
    return 0;
}

// In-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::in_order_traversal(Node<T>* node) {
    // Empty implementation
}

// Pre-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::pre_order_traversal(Node<T>* node) {
    // Empty implementation
}

// Post-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::post_order_traversal(Node<T>* node) {
    // Empty implementation
}

// Level-order traversal of a node
template <typename T>
void NodeBasedBinaryTree<T>::level_order_traversal(Node<T>* node) {
    // Empty implementation
}

// Find minimum node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::find_min_node(Node<T>* node) {
    // Empty implementation
    return nullptr;
}

// Find maximum node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::find_max_node(Node<T>* node) {
    // Empty implementation
    return nullptr;
}

// Remove a node
template <typename T>
Node<T>* NodeBasedBinaryTree<T>::remove(Node<T>* node, T value) {
    // Empty implementation
    return nullptr;
}
