// noapatito123@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

// Node colors for BFS/DFS
enum Color {
    WHITE,
    GRAY,
    BLACK
};

class Graph {
public:
    // Linked list node in adjacency list
    struct Node {
        int vertex, weight;
        Node* next;
    };

private:
    const int V;          // Number of vertices
    Node** adjList;       // Array of adjacency lists

    bool isValidEdge(int src, int dst);  // Checks if edge is valid

public:
    Graph(int vertices);         // Constructor
    ~Graph();                    // Destructor

    void addEdge(int src, int dest, int weight = 1);    // Add undirected edge
    void removeEdge(int src, int dest);                 // Remove edge
    void print_graph() const;                           // Print graph
    void addDirectedEdge(int src, int dest, int weight);// Add one-way edge

    int getV() const;             // Get number of vertices
    int getNumEdges() const;      // Get number of edges
    int getAdjSize(int v) const;  // Number of neighbors of v
    Node* getAdjList(int v) const;// Get adjacency list of v
    bool isValidVertex(int v) const; // Check vertex bounds
    bool hasNegativeEdge() const;    // Check for negative weights
    bool isEdgeExist(int src, int dst); // Check if edge exists
};

} // namespace graph

#endif
