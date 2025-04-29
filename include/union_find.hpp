// noapatito123@gmail.com

#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

namespace graph {

class UnionFind {
private:
    int* parent; // Parent array
    int* rank; // Rank array (tree depth)
    int size; // Number of elements

public:
    UnionFind(int size); // Constructor
    ~UnionFind(); // Destructor

    int find(int x); // Find with path compression
    void unite(int x, int y); // Union by rank
};

} // namespace graph

#endif                        
