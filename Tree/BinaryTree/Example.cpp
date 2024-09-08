#include <iostream>
#include <optional>
#include "ArrayBasedBinaryTree/ArrayBasedBinaryTree.h"
#include "NodeBasedBinaryTree/NodeBasedBinaryTree.h"

// Template function to handle both types of trees
template <typename T, typename SearchResult>
void check(IBinaryTree<T, SearchResult>* tree);

int main() {
    // Create an ArrayBasedBinaryTree with a capacity of 15 nodes
    IBinaryTree<int, int>* arrayTree = new ArrayBasedBinaryTree<int>(15);
    check(arrayTree);
    delete arrayTree;

    // Create a NodeBasedBinaryTree
    IBinaryTree<int, Node<int>*>* nodeTree = new NodeBasedBinaryTree<int>();
    check(nodeTree);
    delete nodeTree;

    return 0;
}

// Template function to check both ArrayBasedBinaryTree and NodeBasedBinaryTree
template <typename T, typename SearchResult>
void check(IBinaryTree<T, SearchResult>* tree) {
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

    // Search for a value
    T value = 7;
    std::optional<SearchResult> searchResult = tree->search(value);

    if (searchResult.has_value()) {
        if constexpr (std::is_same<SearchResult, int>::value) {
            std::cout << "Value " << value << " found at index " << searchResult.value() << std::endl;
        } else if constexpr (std::is_pointer<SearchResult>::value) {
            std::cout << "Value " << value << " found in node with value " << searchResult.value()->data << std::endl;
        }
    } else {
        std::cout << "Value " << value << " not found in the tree." << std::endl;
    }

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
