// noapatito123@gmail.com

#include "algorithms.hpp"          
#include "queue.hpp"               
#include "min_heap.hpp"            
#include "union_find.hpp"          
#include <stdexcept>               
#include <limits>                 

namespace graph {

// ---------- BFS ----------
Graph Algorithms::bfs(const Graph& g, int start) {
    int V = g.getV(); // Get number of vertices
    if (!g.isValidVertex(start)) throw std::invalid_argument("Invalid start vertex for BFS");

    Graph tree(V); // Tree to store BFS result
    Color* color = new Color[V]; // Visited status array

    for (int i = 0; i < V; ++i) color[i] = WHITE; // Initialize all as unvisited
    color[start] = GRAY; // Start vertex is discovered

    Queue q(V); // Initialize queue
    q.enqueue(start);  // Enqueue starting vertex

    while (!q.isEmpty()) {
        int u = q.dequeue(); // Dequeue current node
        Graph::Node* curr = g.getAdjList(u); // Traverse its neighbors

        while (curr) {
            int v = curr->vertex;
            if (color[v] == WHITE) { // If neighbor not visited
                color[v] = GRAY;
                tree.addEdge(u, v, curr->weight); // Add edge to tree
                q.enqueue(v); // Enqueue neighbor
            }
            curr = curr->next;
        }

        color[u] = BLACK; // Mark as fully explored
    }

    delete[] color;
    return tree;
}

// ---------- DFS ----------
void Algorithms::dfsVisit(const Graph& g, int u, Color* color, Graph& tree) {
    color[u] = GRAY; // Mark node as discovered
    Graph::Node* curr = g.getAdjList(u); // Traverse neighbors
    while (curr) {
        int v = curr->vertex;
        if (color[v] == WHITE) { // If not visited
            tree.addEdge(u, v, curr->weight);  // Add to DFS tree
            dfsVisit(g, v, color, tree); // Recurse
        }
        curr = curr->next;
    }
    color[u] = BLACK;  // Mark as finished
}

Graph Algorithms::dfs(const Graph& g, int start) {
    int V = g.getV(); // Get number of vertices
    if (!g.isValidVertex(start)) throw std::invalid_argument("Invalid start vertex for DFS");

    Color* color = new Color[V];  // Visited status
    for (int i = 0; i < V; ++i) color[i] = WHITE;
    Graph tree(V); // DFS tree

    dfsVisit(g, start, color, tree); // Start DFS

    delete[] color;
    return tree;
}

// ---------- Dijkstra ----------
Graph Algorithms::dijkstra(const Graph& g, int start) {
    if (g.hasNegativeEdge()) {
        throw std::invalid_argument("Dijkstra cannot run on graphs with negative weight edges");
    }

    int V = g.getV();
    if (!g.isValidVertex(start)) throw std::invalid_argument("Invalid start vertex for Dijkstra");

    const int INF = std::numeric_limits<int>::max(); // Infinity constant
    int* d = new int[V]; // Distance array
    int* pi = new int[V]; // Parent array
    for (int i = 0; i < V; ++i) {
        d[i] = INF;
        pi[i] = -1;
    }
    d[start] = 0;

    MinHeap Q(V); // Priority queue
    for (int i = 0; i < V; ++i) {
        Q.insert(i, d[i]); // Insert all vertices
    }

    while (!Q.isEmpty()) {
        int u = Q.extractMin(); // Get closest vertex

        Graph::Node* edge = g.getAdjList(u); // Traverse neighbors
        while (edge) {
            int v = edge->vertex;
            int w = edge->weight;

            if (Q.contains(v) && d[u] != INF && d[v] > d[u] + w) {
                d[v] = d[u] + w;  // Relax edge
                pi[v] = u;
                Q.decreaseKey(v, d[v]); // Update priority
            }

            edge = edge->next;
        }
    }

    Graph tree(V);   // Build shortest path tree
    for (int v = 0; v < V; ++v) {
        if (pi[v] != -1) {
            Graph::Node* n = g.getAdjList(v);
            while (n) {
                if (n->vertex == pi[v]) {
                    tree.addEdge(v, pi[v], n->weight);
                    break;
                }
                n = n->next;
            }
        }
    }

    delete[] d;
    delete[] pi;
    return tree;
}

// ---------- Prim ----------
Graph Algorithms::prim(const Graph& g, int start) {
    int V = g.getV();
    if (!g.isValidVertex(start))
        throw std::invalid_argument("Invalid start vertex for Prim");

    const int INF = std::numeric_limits<int>::max();

    int*  key    = new int [V]; // Minimum edge weight
    int*  parent = new int [V]; // Parent array
    bool* inMST  = new bool[V]; // MST inclusion

    for (int i = 0; i < V; ++i) {
        key[i]    = INF;
        parent[i] = -1;
        inMST[i]  = false;
    }

    key[start] = 0;

    MinHeap pq(V);  // Min-priority queue
    pq.insert(start, 0);

    while (!pq.isEmpty()) {
        int u = pq.extractMin(); // Pick min edge
        inMST[u] = true;

        for (Graph::Node* e = g.getAdjList(u); e; e = e->next) {
            int v = e->vertex;
            int w = e->weight;

            if (!inMST[v] && w < key[v]) {
                key[v]    = w;
                parent[v] = u;

                if (pq.contains(v))
                    pq.decreaseKey(v, w);
                else
                    pq.insert(v, w);
            }
        }
    }

    Graph mst(V); // Build MST
    for (int v = 0; v < V; ++v) {
        if (parent[v] != -1) {
            mst.addEdge(v, parent[v], key[v]);
        }
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
    return mst;
}

// ---------- Kruskal ----------
Graph Algorithms::kruskal(const Graph& g) {
    int V = g.getV();
    Graph mst(V); // Output MST
    UnionFind uf(V); // Disjoint set

    struct Edge {
        int u, v, weight;
    };

    int maxEdges = V * (V - 1) / 2;
    Edge* edges = new Edge[maxEdges]; // Edge array
    int edgeCount = 0;

    for (int u = 0; u < V; ++u) {
        Graph::Node* curr = g.getAdjList(u);
        while (curr) {
            int v = curr->vertex;
            if (u < v) { // Avoid duplicates
                edges[edgeCount++] = {u, v, curr->weight};
            }
            curr = curr->next;
        }
    }

    // Selection sort on edge weights
    for (int i = 0; i < edgeCount - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < edgeCount; ++j) {
            if (edges[j].weight < edges[minIdx].weight) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = temp;
        }
    }

    // Add edges to MST if they connect disjoint sets
    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (uf.find(u) != uf.find(v)) {
            mst.addEdge(u, v, edges[i].weight);
            uf.unite(u, v);
        }
    }

    delete[] edges;
    return mst;
}

} // namespace graph
