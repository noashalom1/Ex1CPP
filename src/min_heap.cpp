// noapatito123@gmail.com 

#include "min_heap.hpp" 
#include <stdexcept> 

namespace graph {

MinHeap::MinHeap(int capacity) // Constructor
    : capacity(capacity), size(0)
{
    data = new Element[capacity]; // Allocate heap array
    positions = new int[capacity]; // Allocate positions array
    for (int i = 0; i < capacity; ++i) {
        positions[i] = -1; // Initialize all positions as empty
    }
}

MinHeap::~MinHeap() {
    delete[] data; // Free data array
    delete[] positions; // Free positions array
}

bool MinHeap::isEmpty() const {
    return size == 0; // Return true if heap is empty
}

void MinHeap::swap(int i, int j) {
    Element temp = data[i]; // Swap heap elements
    data[i] = data[j];
    data[j] = temp;

    positions[data[i].vertex] = i; // Update positions after swap
    positions[data[j].vertex] = j;
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2; // Get parent index
        if (data[parent].priority > data[index].priority) {
            swap(parent, index); // Swap if parent > child
            index = parent;
        } else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    int left, right, smallest;
    while (true) {
        left = 2 * index + 1; // Left child
        right = 2 * index + 2; // Right child
        smallest = index;

        if (left < size && data[left].priority < data[smallest].priority) {
            smallest = left;
        }
        if (right < size && data[right].priority < data[smallest].priority) {
            smallest = right;
        }

        if (smallest != index) {
            swap(index, smallest); // Swap with smallest child
            index = smallest;
        } else {
            break;
        }
    }
}

void MinHeap::insert(int vertex, int priority) {
    if (size >= capacity) throw std::runtime_error("Heap overflow"); // Full heap
    data[size] = {vertex, priority}; // Add new element
    positions[vertex] = size; // Track position
    heapifyUp(size); // Restore heap property
    size++;
}

int MinHeap::extractMin() {
    if (isEmpty()) throw std::runtime_error("Heap underflow"); // Empty heap
    int minVertex = data[0].vertex; // Get min vertex
    data[0] = data[size - 1]; // Move last to root
    positions[data[0].vertex] = 0; // Update position
    positions[minVertex] = -1; // Remove from positions
    size--;
    heapifyDown(0); // Restore heap property
    return minVertex;
}

void MinHeap::decreaseKey(int vertex, int newPriority) {
    int index = positions[vertex]; // Get index of vertex
    if (index == -1 || data[index].priority <= newPriority) return; // Skip if invalid or not lower

    data[index].priority = newPriority; // Update priority
    heapifyUp(index); // Restore heap property
}

bool MinHeap::contains(int vertex) const {
    return positions[vertex] != -1; // True if vertex is in heap
}

int MinHeap::getPriority(int vertex) const {
    int index = positions[vertex]; // Get index
    if (index == -1) throw std::runtime_error("Vertex not found in heap"); // Not found
    return data[index].priority; // Return priority
}

} // namespace graph
