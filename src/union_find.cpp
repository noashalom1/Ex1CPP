// noapatito123@gmail.com

#include "union_find.hpp" 

namespace graph {

UnionFind::UnionFind(int size) : size(size) {
    parent = new int[size]; // Allocate parent array
    rank = new int[size]; // Allocate rank array
    for (int i = 0; i < size; ++i) {
        parent[i] = i; // Initialize parent to self
        rank[i] = 0; // Initialize rank to 0
    }
}

UnionFind::~UnionFind() {
    delete[] parent; // Free parent array
    delete[] rank; // Free rank array
}

int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x]; // Return root
}

void UnionFind::unite(int x, int y) {
    int rootX = find(x); // Find root of x
    int rootY = find(y); // Find root of y

    if (rootX == rootY) return; // Already in same set

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY; // Attach x under y
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX; // Attach y under x
    } else {
        parent[rootY] = rootX; // Attach y under x and increase rank
        rank[rootX]++;
    }
}

} // namespace graph
