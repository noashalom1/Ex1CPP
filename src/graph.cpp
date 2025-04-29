// noapatito123@gmail.com

#include "graph.hpp" 
#include <iostream> 
#include <stdexcept> 

namespace graph {

bool Graph::isValidVertex(int v) const { return (v >= 0 && v < V); } // Check if vertex index is valid

bool Graph::isValidEdge(int src, int dst) { return (isValidVertex(src) && isValidVertex(dst) && src != dst); } // Valid edge check

// construct
Graph::Graph(int vertices) : V(vertices) {
    if(vertices <= 0) throw std::invalid_argument("Graph has no vertices"); // Throw if invalid size
    adjList = new Node*[V](); // Allocate adjacency list
}

// destruct
Graph::~Graph() {
    for(int i=0; i<V; i++){ // Free each adjacency list
        Node* curr = adjList[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp; // Delete each node
        }
    }
    delete[] adjList; // Delete the array
}

// adding edge
void Graph::addEdge(int src, int dest, int weight) {
    if(!isValidEdge(src, dest)) throw std::runtime_error("Invalid edge (either bad vertices or src==dest)."); // Invalid edge
    if(isEdgeExist(src, dest) || isEdgeExist(dest, src)) throw std::invalid_argument("Edge already exists!"); // Duplicate check
    addDirectedEdge(src, dest, weight); // Add edge src → dest
    addDirectedEdge(dest, src, weight); // Add edge dest → src
}

void Graph::addDirectedEdge(int src, int dest, int weight) {
    Node* new_node = new Node; // Create new node
    new_node->vertex = dest; // Set destination
    new_node->weight = weight; // Set weight
    new_node->next = nullptr; // End of list

    if (adjList[src] == nullptr) { // First node
        adjList[src] = new_node;
        return;
    }

    Node* curr = adjList[src]; // Traverse to end
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = new_node; // Append new node
}

// remove edge
void Graph::removeEdge(int src, int dest) {
    if(!isValidVertex(src) || !isValidVertex(dest)) {
        throw std::runtime_error("Invalid vertex index!"); // Invalid vertex
    }

    bool foundSrc = false; // Track removal of src → dest
    {
        Node* curr = adjList[src];
        Node* prev = nullptr;
        while(curr){
            if(curr->vertex == dest){
                foundSrc = true;
                if(prev == nullptr){ adjList[src] = curr->next; } // Remove head
                else { prev->next = curr->next; } // Remove middle/end
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool foundDest = false; // Track removal of dest → src
    {
        Node* curr = adjList[dest];
        Node* prev = nullptr;
        while(curr){
            if(curr->vertex == src){
                foundDest = true;
                if(prev == nullptr){ adjList[dest] = curr->next; }
                else { prev->next = curr->next; }
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    if(!foundSrc || !foundDest) {
        throw std::runtime_error("Edge not found!"); // Edge missing
    }
}

// print graph
void Graph::print_graph() const {
    for(int i = 0; i < V; i++){
        std::cout << i << ": ";
        Node* curr = adjList[i];
        while(curr){
            std::cout << "(" << curr->vertex << ", w=" << curr->weight << ") "; // Print neighbor
            curr = curr->next;
        }
        std::cout << "\n";
    }
}

int Graph::getV() const { return V; } // Return number of vertices

int Graph::getNumEdges() const {
    int counter = 0;
    for (int i = 0; i < V; i++) {
        Node* curr = adjList[i];
        while (curr) {
            if (curr->vertex > i) counter++; // Count unique edges once
            curr = curr->next;
        }
    }
    return counter;
}

int Graph::getAdjSize(int v) const {
    if(!isValidVertex(v)) {
        throw std::runtime_error("Invalid vertex index in getAdjSize."); // Check bounds
    }
    int count = 0;
    Node* curr = adjList[v];
    while(curr){
        count++; // Count neighbors
        curr = curr->next;
    }
    return count;
}

Graph::Node* Graph::getAdjList(int v) const {
    if(!isValidVertex(v)) {
        throw std::runtime_error("Invalid vertex index in getAdjList."); // Check bounds
    }
    return adjList[v]; // Return head of list
}

bool Graph::hasNegativeEdge() const {
    for (int i = 0; i < V; ++i) {
        Node* curr = adjList[i];
        while (curr) {
            if (curr->weight < 0) return true; // Found negative edge
            curr = curr->next;
        }
    }
    return false; // No negative edges
}

bool Graph::isEdgeExist(int src, int dst) {
    Node* curr = adjList[src];
    while (curr) {
        if (curr->vertex == dst) {
            return true; // Found edge
        }
        curr = curr->next;
    }
    return false; // Edge not found
}

} // namespace graph
