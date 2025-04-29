// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.hpp"
#include "algorithms.hpp"

using namespace graph;

// ==============================
//          BFS TESTS
// ==============================

TEST_CASE("BFS throws on invalid start vertex") {
    Graph g(3);                 

    CHECK_THROWS_AS(Algorithms::bfs(g, -1), std::invalid_argument);

    CHECK_THROWS_AS(Algorithms::bfs(g, 3), std::invalid_argument);

    CHECK_THROWS_AS(Algorithms::bfs(g, 10), std::invalid_argument);
}

TEST_CASE("BFS on single-node graph") {
    Graph g(1);
    Graph tree = Algorithms::bfs(g, 0);
    CHECK(tree.getV() == 1);
    CHECK(tree.getNumEdges() == 0);
}

TEST_CASE("BFS on graph with no edges") {
    Graph g(4);
    Graph tree = Algorithms::bfs(g, 0);
    for (int i = 0; i < 4; ++i)
        CHECK(tree.getAdjSize(i) == 0);
}

TEST_CASE("BFS on disconnected graph") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(3, 4, 1);
    Graph tree = Algorithms::bfs(g, 0);
    CHECK(tree.getAdjSize(0) == 1);
    CHECK(tree.getAdjSize(1) == 1);
    CHECK(tree.getAdjSize(3) == 0);
    CHECK(tree.getAdjSize(4) == 0);
}

TEST_CASE("BFS on connected graph") {
    Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 0);
    Graph tree = Algorithms::bfs(g, 0);
    CHECK(tree.getAdjSize(0) == 2);
    CHECK(tree.getAdjSize(1) == 2);
    CHECK(tree.getAdjSize(2) == 1);
    CHECK(tree.getAdjSize(3) == 2);
    CHECK(tree.getAdjSize(4) == 2);
    CHECK(tree.getAdjSize(5) == 1);
}                                                                

// ==============================
//          DFS TESTS
// ==============================
TEST_CASE("DFS throws on invalid start vertex") {
    Graph g(3);                 

    CHECK_THROWS_AS(Algorithms::dfs(g, -1), std::invalid_argument);

    CHECK_THROWS_AS(Algorithms::dfs(g, 3), std::invalid_argument);

    CHECK_THROWS_AS(Algorithms::dfs(g, 10), std::invalid_argument);
}

TEST_CASE("DFS on single-node graph") {
    Graph g(1);
    Graph tree = Algorithms::dfs(g, 0);
    CHECK(tree.getV() == 1);
    CHECK(tree.getNumEdges() == 0);
}

TEST_CASE("DFS on graph with cycle") {
    Graph g(3);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 0, 2);
    Graph tree = Algorithms::dfs(g, 0);
    int edges = 0;
    for (int i = 0; i < 3; ++i) edges += tree.getAdjSize(i);
    CHECK(edges == 4);
}

TEST_CASE("DFS on disconnected graph") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(3, 4, 1);
    Graph tree = Algorithms::dfs(g, 0);
    CHECK(tree.getAdjSize(0) == 1);
    CHECK(tree.getAdjSize(2) == 0);
    CHECK(tree.getAdjSize(3) == 0);
}

TEST_CASE("DFS on connected graph") {
    Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 0);
    Graph tree = Algorithms::dfs(g, 0);
    CHECK(tree.getAdjSize(0) == 1);
    CHECK(tree.getAdjSize(1) == 2);
    CHECK(tree.getAdjSize(2) == 2);
    CHECK(tree.getAdjSize(3) == 2);
    CHECK(tree.getAdjSize(4) == 2);
    CHECK(tree.getAdjSize(5) == 1);
}

TEST_CASE("DFS on graph with no edges") {
    Graph g(4);
    Graph tree = Algorithms::dfs(g, 0);
    for (int i = 0; i < 4; ++i)
        CHECK(tree.getAdjSize(i) == 0);
}

// ==============================
//       DIJKSTRA TESTS
// ==============================

TEST_CASE("Dijkstra on disconnected graph") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    Graph tree = Algorithms::dijkstra(g, 0);
    CHECK(tree.getAdjSize(0) == 1);
    CHECK(tree.getAdjSize(1) == 2);
    CHECK(tree.getAdjSize(2) == 1);
    CHECK(tree.getAdjSize(3) == 0);
}

TEST_CASE("Dijkstra on connected graph") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 1);
    g.addEdge(1, 3, 5);
    Graph tree = Algorithms::dijkstra(g, 0);
    CHECK(tree.getAdjSize(0) == 1);
    CHECK(tree.getAdjSize(1) == 2);
    CHECK(tree.getAdjSize(2) == 2);
    CHECK(tree.getAdjSize(3) == 1);
}

TEST_CASE("Dijkstra on single-node graph") {
    Graph g(1);
    Graph tree = Algorithms::dijkstra(g, 0);
    CHECK(tree.getAdjSize(0) == 0);
}

TEST_CASE("Dijkstra throws on negative edge") {
    Graph g(3);
    g.addEdge(0, 1, -5);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Dijkstra throws on invalid start node") {
    Graph g(3);
    g.addEdge(0, 1, 2);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 3), std::invalid_argument);
}

// ==============================
//         PRIM TESTS
// ==============================

TEST_CASE("Prim on fully connected graph") {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 6);
    Graph mst = Algorithms::prim(g, 0);
    CHECK(mst.getNumEdges() == 3);
    CHECK(mst.getAdjSize(0) == 1);
    CHECK(mst.getAdjSize(1) == 2);
    CHECK(mst.getAdjSize(2) == 2);
    CHECK(mst.getAdjSize(3) == 1);
}

TEST_CASE("Prim on graph with no edges") {
    Graph g(3);
    Graph tree = Algorithms::prim(g, 0);
    for (int i = 0; i < 3; ++i)
        CHECK(tree.getAdjSize(i) == 0);
}

TEST_CASE("Prim on single-node graph") {
    Graph g(1);
    Graph tree = Algorithms::prim(g, 0);
    CHECK(tree.getAdjSize(0) == 0);
}

TEST_CASE("Prim on connected graph builds MST of size V-1") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 5);

    Graph mst = Algorithms::prim(g, 0);
    CHECK(mst.getNumEdges() == 3);
}

TEST_CASE("Prim handles equal weights consistently") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);

    Graph mst = Algorithms::prim(g, 0);
    CHECK(mst.getAdjSize(0) == 2);
    CHECK(mst.getAdjSize(1) == 1);
    CHECK(mst.getAdjSize(2) == 1);
}

TEST_CASE("Prim on disconnected graph") {
    Graph g(8);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(5, 6, 3);
    g.addEdge(6, 7, 2);    

    Graph mst = Algorithms::prim(g, 0);
    CHECK(mst.getAdjSize(0) == 2);
    CHECK(mst.getAdjSize(1) == 1);
    CHECK(mst.getAdjSize(2) == 2);
    CHECK(mst.getAdjSize(3) == 1);
    CHECK(mst.getAdjSize(4) == 0);
    CHECK(mst.getAdjSize(5) == 0);
    CHECK(mst.getAdjSize(6) == 0);
    CHECK(mst.getAdjSize(7) == 0);
}

TEST_CASE("Prim throws on invalid start vertex") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(Algorithms::prim(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(Algorithms::prim(g, 3),  std::invalid_argument);
}

// ==============================
//       KRUSKAL TESTS
// ==============================

TEST_CASE("Kruskal on graph with no edges") {
    Graph g(3);
    Graph tree = Algorithms::kruskal(g);
    for (int i = 0; i < 3; ++i)
        CHECK(tree.getAdjSize(i) == 0);
}

TEST_CASE("Kruskal on single-node graph") {
    Graph g(1);
    Graph tree = Algorithms::kruskal(g);
    CHECK(tree.getAdjSize(0) == 0);
}

TEST_CASE("Kruskal builds MST on simple graph") {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(0, 3, 15);
    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getNumEdges() == 3); 
    CHECK(mst.getAdjSize(0) == 1);
    CHECK(mst.getAdjSize(1) == 2);
    
    CHECK(mst.getAdjSize(2) == 2);
    CHECK(mst.getAdjSize(3) == 1);
}

TEST_CASE("Kruskal on disconnected graph builds minimum spanning forest") {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(4, 5, 3);
    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getAdjSize(0) == 1);
    CHECK(mst.getAdjSize(1) == 1);
    CHECK(mst.getAdjSize(2) == 1);
    CHECK(mst.getAdjSize(3) == 1);
    CHECK(mst.getAdjSize(4) == 1);
    CHECK(mst.getAdjSize(5) == 1);
}
