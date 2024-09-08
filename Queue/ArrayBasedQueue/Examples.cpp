#include <iostream>
#include "QueueArray.h"

int main() {
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    // Display the queue
    std::cout << "Queue elements: ";
    queue.display();

    // Front and rear elements
    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Rear element: " << queue.rear() << std::endl;

    // Dequeue an element
    std::cout << "Dequeue element: " << queue.dequeue() << std::endl;

    // Display the queue after dequeue
    std::cout << "Queue elements after dequeue: ";
    queue.display();

    // Check if queue is empty
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // Queue size
    std::cout << "Queue size: " << queue.size() << std::endl;

    return 0;
}
