// noapatito123@gmail.com

#ifndef ALGORITHMS_HPP           
#define ALGORITHMS_HPP

#include "graph.hpp"             

namespace graph {

class Algorithms {
public:

    static Graph bfs(const Graph& g, int start); // Breadth-First Search

    static Graph dfs(const Graph& g, int start); // Depth-First Search

    static Graph dijkstra(const Graph& g, int start); // Dijkstra's algorithm

    static Graph prim(const Graph& g, int start); // Prim's MST

    static Graph kruskal(const Graph& g); // Kruskal's MST

private:

    static void dfsVisit(const Graph& g, int v, Color* color, Graph& tree); // DFS helper
};

} // namespace graph

#endif 
