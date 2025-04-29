// noapatito123@gmail.com

#ifndef MIN_HEAP_HPP          
#define MIN_HEAP_HPP

namespace graph {

class MinHeap {
private:
    struct Element {  // Heap element: vertex and its priority
        int vertex;
        int priority;
    };

    Element* data; // Array of heap elements
    int* positions; // Map vertex to its index in the heap
    int capacity; // Max heap size
    int size; // Current number of elements

    void swap(int i, int j); // Swap two elements
    void heapifyUp(int index); // Restore heap upward
    void heapifyDown(int index); // Restore heap downward

public:
    MinHeap(int capacity); // Constructor
    ~MinHeap(); // Destructor

    bool isEmpty() const; // Check if heap is empty
    void insert(int vertex, int priority); // Insert element
    int extractMin(); // Remove min element
    void decreaseKey(int vertex, int newPriority); // Decrease priority
    bool contains(int vertex) const; // Check if vertex is in heap
    int getPriority(int vertex) const; // Get vertex's priority
};

} // namespace graph

#endif  
