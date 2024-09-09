#include <iostream>
#include "ArrayBasedBinaryTree/ArrayBasedBinaryTree.h"
#include "NodeBasedBinaryTree/NodeBasedBinaryTree.h"

// Template function to handle both types of trees
template <typename T, typename NodeType>
void check(IBinaryTree<T, NodeType>* tree);
template <typename T>
void check_node_search(IBinaryTree<int, Node<int>*>* nodeTree, T value);
template <typename T>
void check_idx_search(IBinaryTree<int, int>* arrayTree, T value) ;

int main() {
    // Create an ArrayBasedBinaryTree with a capacity of 15 nodes
    IBinaryTree<int, int>* arrayTree = new ArrayBasedBinaryTree<int>(15);
    check(arrayTree);
    check_idx_search(arrayTree, 7);
    delete arrayTree;

    // Create a NodeBasedBinaryTree
    IBinaryTree<int, Node<int>*>* nodeTree = new NodeBasedBinaryTree<int>();
    check(nodeTree);
    check_node_search(nodeTree, 7);
    delete nodeTree;

    return 0;
}

// Template function to check both ArrayBasedBinaryTree and NodeBasedBinaryTree
template <typename T, typename NodeType>
void check(IBinaryTree<T, NodeType>* tree) {
    std::cout << "----------------------------------" << std::endl;
    // Insert some values
    tree->insert(10);
    tree->insert(5);
    tree->insert(15);
    tree->insert(3);
    tree->insert(7);
    tree->insert(12);
    tree->insert(18);

    std::cout << "In-Order Traversal: ";
    tree->in_order_traversal();
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal: ";
    tree->pre_order_traversal();
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    tree->post_order_traversal();
    std::cout << std::endl;
    
   


    // Find minimum and maximum values
    std::cout << "Minimum value in the tree: " << tree->find_min() << std::endl;
    std::cout << "Maximum value in the tree: " << tree->find_max() << std::endl;

    // Get the height of the tree
    std::cout << "Height of the tree: " << tree->height() << std::endl;

    // Check if the tree is empty
    std::cout << "Is the tree empty? " << (tree->is_empty() ? "Yes" : "No") << std::endl;

    // Remove a value
    tree->remove(15);
    std::cout << "After removing 15, In-Order Traversal: ";
    tree->in_order_traversal();
    std::cout << std::endl;
}

template <typename T>
void check_idx_search(IBinaryTree<int, int>* arrayTree, T value) {
    int searchResult = arrayTree->search(value);
    if (searchResult != -1) {
        std::cout << "Value " << value << " found at index " << searchResult << std::endl;
    } else {
        std::cout << "Value " << value << " not found in the tree." << std::endl;
    }
}

template <typename T>
void check_node_search(IBinaryTree<int, Node<int>*>* nodeTree, T value) {
    Node<int>* searchResult = nodeTree->search(value);

    if (searchResult != nullptr) {
        std::cout << "Value " << value << " found at node: \nvalue:" << searchResult->value << "   left: "<< searchResult->left <<"   right: "<<searchResult->right <<  std::endl;
    } else {
        std::cout << "Value " << value << " not found in the tree." << std::endl;
    }
}
