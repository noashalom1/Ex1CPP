// noapatito123@gmail.com

#include <iostream>
#include "graph.hpp"
#include "algorithms.hpp"

using namespace graph;

int main() {
    std::cout << "\n== Example Graph 1 ==\n";
    Graph g1(6);

    // Adding edges
    g1.addEdge(0, 1, 0);
    g1.addEdge(0, 2, 0);
    g1.addEdge(1, 2, 0);
    g1.addEdge(1, 3, 0);
    g1.addEdge(2, 3, 0);
    g1.addEdge(3, 4, 0);
    g1.addEdge(4, 5, 0);    

    std::cout << "\nOriginal Graph:\n";
    g1.print_graph();

    // BFS from vertex 0
    std::cout << "\n== BFS from vertex 0 ==\n";
    Graph bfsTree1 = Algorithms::bfs(g1, 0);
    bfsTree1.print_graph();

     // BFS from vertex 2
     std::cout << "\n== BFS from vertex 2 ==\n";
     Graph bfsTree11 = Algorithms::bfs(g1, 2);
     bfsTree11.print_graph();

    // DFS from vertex 0
    std::cout << "\n== DFS from vertex 0 ==\n";
    Graph dfsTree1 = Algorithms::dfs(g1, 0);
    dfsTree1.print_graph();

    // DFS from vertex 2
    std::cout << "\n== DFS from vertex 2 ==\n";
    Graph dfsTree11 = Algorithms::dfs(g1, 2);
    dfsTree11.print_graph();

    // Dijkstra from vertex 0
    std::cout << "\n== Dijkstra from vertex 0 ==\n";
    Graph dijkstraTree1 = Algorithms::dijkstra(g1, 0);
    dijkstraTree1.print_graph();

    // Dijkstra from vertex 2
    std::cout << "\n== Dijkstra from vertex 2 ==\n";
    Graph dijkstraTree11 = Algorithms::dijkstra(g1, 2);
    dijkstraTree11.print_graph();

    // Prim
    std::cout << "\n== Prim (Minimum Spanning Tree) ==\n";
    Graph primTree1 = Algorithms::prim(g1, 0);
    primTree1.print_graph();

    // Kruskal
    std::cout << "\n== Kruskal (Minimum Spanning Tree) ==\n";
    Graph kruskalTree1 = Algorithms::kruskal(g1);
    kruskalTree1.print_graph();


    std::cout << "\n== Example Graph 2 ==\n";
    Graph g2(8);

    // Adding edges
    g2.addEdge(0, 1, 1);
    g2.addEdge(0, 2, 1);
    g2.addEdge(1, 2, 2);
    g2.addEdge(1, 3, 3);
    g2.addEdge(2, 3, 2);
    g2.addEdge(4, 5, 4);
    g2.addEdge(5, 6, 3);
    g2.addEdge(6, 7, 2); 
    // Graph g2(6);

    // // Adding edges 
    // g2.addEdge(0, 1, 1);
    // g2.addEdge(0, 2, 1);
    // g2.addEdge(1, 2, 2);
    // g2.addEdge(1, 3, 3);
    // g2.addEdge(2, 3, 2);
    // g2.addEdge(3, 4, 5);
    // g2.addEdge(4, 5, 4);

    std::cout << "\nOriginal Graph:\n";
    g2.print_graph();

    // BFS
    std::cout << "\n== BFS from vertex 0 ==\n";
    Graph bfsTree2 = Algorithms::bfs(g2, 0);
    bfsTree2.print_graph();

    // DFS
    std::cout << "\n== DFS from vertex 0 ==\n";
    Graph dfsTree2 = Algorithms::dfs(g2, 0);
    dfsTree2.print_graph();

    // Dijkstra
    std::cout << "\n== Dijkstra from vertex 0 ==\n";
    Graph dijkstraTree2 = Algorithms::dijkstra(g2, 0);
    dijkstraTree2.print_graph();

    // Prim
    std::cout << "\n== Prim (MST) ==\n";
    Graph primTree2 = Algorithms::prim(g2, 0);
    primTree2.print_graph();

    // Kruskal
    std::cout << "\n== Kruskal (MST) ==\n";
    Graph kruskalTree2 = Algorithms::kruskal(g2);
    kruskalTree2.print_graph();


    std::cout << "\n== Example Graph 3 ==\n";
    Graph g3(9);

    // Adding edges
    g3.addEdge(0, 1, 9);
    g3.addEdge(0, 3, 1);
    g3.addEdge(1, 4, 4);
    g3.addEdge(1, 2, 3);
    g3.addEdge(1, 5, 3);
    g3.addEdge(2, 5, 12);
    g3.addEdge(2, 4, 1);
    g3.addEdge(2, 3, 5);
    g3.addEdge(3, 6, 8);
    g3.addEdge(5, 6, 5);
    g3.addEdge(7, 5, 2);
    g3.addEdge(7, 6, 2);
    g3.addEdge(7, 8, 1);
    g3.addEdge(4, 8, 6);

    std::cout << "\nOriginal Graph:\n";
    g3.print_graph();

    // BFS
    std::cout << "\n== BFS from vertex 0 ==\n";
    Graph bfsTree3 = Algorithms::bfs(g3, 0);
    bfsTree3.print_graph();

    // DFS
    std::cout << "\n== DFS from vertex 0 ==\n";
    Graph dfsTree3 = Algorithms::dfs(g3, 0);
    dfsTree3.print_graph();

    // Dijkstra
    std::cout << "\n== Dijkstra from vertex 0 ==\n";
    Graph dijkstraTree3 = Algorithms::dijkstra(g3, 0);
    dijkstraTree3.print_graph();

    // Prim
    std::cout << "\n== Prim (Minimum Spanning Tree) ==\n";
    Graph primTree3 = Algorithms::prim(g3,0);
    primTree3.print_graph();

    // Kruskal
    std::cout << "\n== Kruskal (Minimum Spanning Tree) ==\n";
    Graph kruskalTree3 = Algorithms::kruskal(g3);
    kruskalTree3.print_graph();


    return 0;
}
