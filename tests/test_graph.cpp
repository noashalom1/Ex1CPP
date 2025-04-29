// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.hpp"

using namespace graph;

TEST_CASE("Creating graph with 0 vertices throws") {
    CHECK_THROWS_AS(Graph g(0), std::invalid_argument);
}

TEST_CASE("Graph with one vertex has no edges") {
    Graph g(1);
    CHECK(g.getAdjSize(0) == 0);
    CHECK_NOTHROW(g.print_graph());
}

TEST_CASE("addEdge throws on invalid vertices") {
    Graph g(3);
    CHECK_THROWS_AS(g.addEdge(-1, 2, 1), std::runtime_error);
    CHECK_THROWS_AS(g.addEdge(0, 3, 1), std::runtime_error);
}

TEST_CASE("addEdge throws on self-loop") {
    Graph g(3);
    CHECK_THROWS_AS(g.addEdge(1, 1, 1), std::runtime_error);
}

TEST_CASE("addEdge throws on duplicate edge") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(g.addEdge(1, 0, 1), std::invalid_argument);
}

TEST_CASE("removeEdge works correctly") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.removeEdge(0, 1);
    CHECK(g.getAdjSize(0) == 0);
    CHECK(g.getAdjSize(1) == 0);
}

TEST_CASE("removeEdge throws if edge doesn't exist") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(g.removeEdge(1, 2), std::runtime_error);
}

TEST_CASE("removeEdge throws on invalid vertices") {
    Graph g(2);
    CHECK_THROWS_AS(g.removeEdge(0, 5), std::runtime_error);
}

TEST_CASE("print_graph does not crash on empty graph") {
    Graph g(3);
    CHECK_NOTHROW(g.print_graph());
}

TEST_CASE("print_graph works after several additions and deletions") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.removeEdge(1, 2);
    CHECK_NOTHROW(g.print_graph());
}

TEST_CASE("isValidVertex returns correct results") {
    Graph g(4);
    CHECK( g.isValidVertex(0) );
    CHECK( g.isValidVertex(3) );
    CHECK_FALSE( g.isValidVertex(-1) );
    CHECK_FALSE( g.isValidVertex(4) );
}

TEST_CASE("isEdgeExist detects existing and non-existing edges") {
    Graph g(3);
    g.addEdge(0, 1, 2);
    CHECK(g.isEdgeExist(0, 1));
    CHECK(g.isEdgeExist(1, 0));   
    CHECK_FALSE( g.isEdgeExist(0, 2) );
}

TEST_CASE("getAdjSize counts neighbors correctly after modifications") {
    Graph g(4);
    CHECK(g.getAdjSize(2) == 0);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 1, 7);
    CHECK(g.getAdjSize(2) == 2);
    g.removeEdge(2, 3);
    CHECK(g.getAdjSize(2) == 1);
}

TEST_CASE("getAdjList throws on invalid vertex") {
    Graph g(2);
    CHECK_THROWS_AS(g.getAdjList(-1), std::runtime_error);
    CHECK_THROWS_AS(g.getAdjList(2),  std::runtime_error);
}

TEST_CASE("getNumEdges counts undirected edges once") {
    Graph g(5);
    CHECK( g.getNumEdges() == 0 );
    g.addEdge(0, 1, 1);            
    g.addEdge(0, 2, 1);            
    g.addEdge(3, 4, 1);             
    CHECK( g.getNumEdges() == 3 );
    g.removeEdge(0, 2);             
    CHECK( g.getNumEdges() == 2 );
}

TEST_CASE("hasNegativeEdge returns true when any weight < 0") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    CHECK_FALSE( g.hasNegativeEdge() );
    g.addEdge(2, 3, -5);              
    CHECK( g.hasNegativeEdge() );
}

TEST_CASE("addEdge followed by removeEdge keeps graph consistent") {
    Graph g(3);
    g.addEdge(0, 1, 4);
    CHECK( g.isEdgeExist(0, 1) );
    g.removeEdge(0, 1);
    CHECK_FALSE( g.isEdgeExist(0, 1) );
    CHECK( g.getNumEdges() == 0 );
}

TEST_CASE("removeEdge on both directions actually deletes both lists") {
    Graph g(2);
    g.addEdge(0, 1, 9);
    g.removeEdge(0, 1);
    CHECK( g.getAdjSize(0) == 0 );
    CHECK( g.getAdjSize(1) == 0 );
}
