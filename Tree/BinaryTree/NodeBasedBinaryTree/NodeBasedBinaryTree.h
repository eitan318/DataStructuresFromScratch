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
    void in_order_traversal(std::function<void(Node<T>*)> func) override;
    void pre_order_traversal(std::function<void(Node<T>*)> func) override;
    void post_order_traversal(std::function<void(Node<T>*)> func) override;
    void level_order_traversal(std::function<void(Node<T>*)> func) override;

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
    void in_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func);
    void pre_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func);
    void post_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func);
    void level_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func);
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

// In-order traversal with a function
template <typename T>
void NodeBasedBinaryTree<T>::in_order_traversal(std::function<void(Node<T>*)> func) {
    in_order_traversal(root, func);
}



// Pre-order traversal with a function
template <typename T>
void NodeBasedBinaryTree<T>::pre_order_traversal(std::function<void(Node<T>*)> func) {
    pre_order_traversal(root, func);
}



// Post-order traversal with a function
template <typename T>
void NodeBasedBinaryTree<T>::post_order_traversal(std::function<void(Node<T>*)> func) {
    post_order_traversal(root, func);
}


// Level-order traversal with a function
template <typename T>
void NodeBasedBinaryTree<T>::level_order_traversal(std::function<void(Node<T>*)> func) {
    if (!root) return;
    
    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        func(current);

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Helper functions



template <typename T>
void NodeBasedBinaryTree<T>::in_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func) {
    if (node) {
        in_order_traversal(node->left, func);
        func(node);
        in_order_traversal(node->right, func);
    }
}

template <typename T>
void NodeBasedBinaryTree<T>::post_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func) {
    if (node) {
        post_order_traversal(node->left, func);
        post_order_traversal(node->right, func);
        func(node);
    }
}


template <typename T>
void NodeBasedBinaryTree<T>::pre_order_traversal(Node<T>* node, std::function<void(Node<T>*)> func) {
    if (node) {
        func(node);
        pre_order_traversal(node->left, func);
        pre_order_traversal(node->right, func);
    }
}

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
