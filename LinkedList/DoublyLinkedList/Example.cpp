#include "DoublyLinkedList.h"

int main() {
    // Create a new doubly linked list
    DoublyLinkedList<int> list;

    // Add elements to the start and end
    list.add_start(10);
    list.add_end(20);
    list.add_start(5);
    list.add_end(30);

    // Print the list
    std::cout << "List after adding elements: ";
    list.print();

    // Get and print elements by index
    std::cout << "Element at index 0: " << list.get(0) << std::endl;
    std::cout << "Element at index 2: " << list.get(2) << std::endl;

    // Set a new value at index 1
    list.set(1, 15);
    std::cout << "List after setting new value at index 1: ";
    list.print();

    // Replace elements at index 0 and 2
    list.replace(0, 2);
    std::cout << "List after replacing elements at index 0 and 2: ";
    list.print();

    // Get and print the last element
    std::cout << "Last element in the list: " << list.get_last() << std::endl;

    // Move a node from index 2 to index 1
    list.move_node(2, 1);
    std::cout << "List after moving node from index 2 to index 1: ";
    list.print();

    // Reverse the list (you'll need to implement this)
    list.reverse();
    std::cout << "List after reversing: ";
    list.print();

    // Remove node with value 15
    list.remove_fast(15);
    std::cout << "List after removing node with value 15: ";
    list.print();

    // Remove node at index 1
    list.remove_at(1);
    std::cout << "List after removing node at index 1: ";
    list.print();

    // Free the list (automatically done in the destructor)
    list.free();

    // Print the list after freeing (should be empty)
    std::cout << "List after freeing all nodes: ";
    list.print();

    return 0;
}
