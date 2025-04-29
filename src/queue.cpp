// noapatito123@gmail.com

#include "queue.hpp" 
#include <stdexcept>

namespace graph {

Queue::Queue(int capacity) : capacity(capacity), size(0), front(0), rear(0) {
    data = new int[capacity]; // Allocate array for queue
}

Queue::~Queue() {
    delete[] data; // Free allocated memory
}

void Queue::enqueue(int value) {
    if (size >= capacity) throw std::runtime_error("Queue overflow"); // Check overflow
    data[rear] = value; // Add value at rear
    rear = (rear + 1) % capacity; // Advance rear (circular)
    size++; // Increase size
}

int Queue::dequeue() {
    if (isEmpty()) throw std::runtime_error("Queue underflow"); // Check underflow
    int val = data[front]; // Get front value
    front = (front + 1) % capacity; // Advance front (circular)
    size--; // Decrease size
    return val; // Return dequeued value
}

bool Queue::isEmpty() const {
    return size == 0; // Return true if empty
}

} // namespace graph
