// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "min_heap.hpp"

using namespace graph;

TEST_CASE("MinHeap basic insert and extract") {
    MinHeap heap(5);
    heap.insert(0, 10);
    heap.insert(1, 5);
    heap.insert(2, 8);

    CHECK(heap.extractMin() == 1);
    CHECK(heap.extractMin() == 2);
    CHECK(heap.extractMin() == 0);
    CHECK(heap.isEmpty());
}

TEST_CASE("MinHeap decreaseKey") {
    MinHeap heap(3);
    heap.insert(0, 10);
    heap.insert(1, 15);
    heap.insert(2, 20);
    heap.decreaseKey(2, 5);

    CHECK(heap.extractMin() == 2);
}

TEST_CASE("MinHeap contains and getPriority") {
    MinHeap heap(2);
    heap.insert(0, 4);
    heap.insert(1, 9);

    CHECK(heap.contains(0));
    CHECK(heap.contains(1));
    CHECK(heap.getPriority(0) == 4);
}

TEST_CASE("MinHeap extractMin on empty heap throws") {
    MinHeap heap(2);
    CHECK_THROWS_AS(heap.extractMin(), std::runtime_error);
}

TEST_CASE("MinHeap getPriority on non-existent vertex throws") {
    MinHeap heap(2);
    heap.insert(0, 5);
    CHECK_THROWS_AS(heap.getPriority(1), std::runtime_error);
}

TEST_CASE("MinHeap decreaseKey on non-existent vertex does nothing") {
    MinHeap heap(2);
    heap.insert(0, 5);
    CHECK_NOTHROW(heap.decreaseKey(1, 1)); // should silently do nothing
}

TEST_CASE("MinHeap overflow throws") {
    MinHeap heap(2);
    heap.insert(0, 1);
    heap.insert(1, 2);
    CHECK_THROWS_AS(heap.insert(2, 3), std::runtime_error);   // capacity reached
}

TEST_CASE("MinHeap contains returns false after extract") {
    MinHeap heap(3);
    heap.insert(0, 7);
    heap.insert(1, 4);
    CHECK(heap.contains(1));

    int v = heap.extractMin();        
    CHECK(v == 1);
    CHECK_FALSE(heap.contains(1));     // positions removed
}

TEST_CASE("getPriority throws after vertex removed") {
    MinHeap heap(2);
    heap.insert(0, 10);
    heap.extractMin();                 // removing 0
    CHECK_THROWS_AS(heap.getPriority(0), std::runtime_error);
}

TEST_CASE("decreaseKey ignores higher-or-equal priority") {
    MinHeap heap(2);
    heap.insert(0, 5);
    heap.decreaseKey(0, 7);            
    CHECK(heap.getPriority(0) == 5);

    heap.decreaseKey(0, 5);            
    CHECK(heap.getPriority(0) == 5);
}

TEST_CASE("isEmpty behaves correctly throughout operations") {
    MinHeap heap(3);
    CHECK(heap.isEmpty());

    heap.insert(0, 3);
    CHECK_FALSE(heap.isEmpty());

    heap.extractMin();
    CHECK(heap.isEmpty());
}

TEST_CASE("Extracting many items keeps correct order") {
    MinHeap heap(6);
    heap.insert(0, 60);
    heap.insert(1, 10);
    heap.insert(2, 30);
    heap.insert(3, 20);
    heap.insert(4, 40);
    heap.insert(5, 50);

    std::vector<int> order;
    while (!heap.isEmpty()) order.push_back(heap.extractMin());

    std::vector<int> expected = {1, 3, 2, 4, 5, 0};
    CHECK(order == expected);
}

