# Ex1 CPP

## Author
Noa Patito 
Email: noapatito123@gmail.com

## Overview

This C++ project implements fundamental graph algorithms using object-oriented programming principles. The project includes classes for graph representation, graph traversal algorithms (BFS, DFS), shortest path (Dijkstra), and minimum spanning trees (Prim, Kruskal). The project avoids using the C++ Standard Template Library (STL) and manually manages memory, as required by assignment guidelines.

This project includes the following components:

 **graph** - Defines the `Graph` class using an adjacency list implemented with raw pointers.
* Manages adding/removing edges.
* Provides methods for checking negative edges, printing the graph, and retrieving vertex neighbors.
* Handles undirected graphs with validation and error throwing for invalid operations.

**algorithms** - Implements five core graph algorithms:
* `BFS` (Breadth-First Search) - starting from a specified node and returns a directed tree or forest   that outlines the BFS traversal path.

* `DFS` (Depth-First Search) - producing a directed tree or forest made up of only tree edges, reflecting the structure of the DFS exploration.

* `Dijkstra` (Shortest path, fails on negative edges) - Finds the shortest paths from a given starting vertex using Dijkstra’s algorithm. It returns a directed tree rooted at the source node that contains the lowest-cost paths to reachable vertices.

* `Prim` (MST) - Builds a Minimum Spanning Tree (MST) using Prim’s approach. The result is an undirected graph connecting all reachable nodes with minimal total edge weight.

* `Kruskal` (MST using Union-Find) - Constructs a Minimum Spanning Tree by applying Kruskal’s method. It also returns an undirected MST formed by choosing the lowest-weight edges that avoid cycles.

**min_heap** - Implements a custom `MinHeap` to support efficient minimum extraction and priority updates, used in Prim and Dijkstra.
Supports insert, extractMin, decreaseKey, contains, and getPriority.

**union_find** - Implements Union-Find (Disjoint Set Union - DSU) with path compression and union by rank.
Used by Kruskal's algorithm.

**queue** - Implements a basic circular queue used in BFS traversal.
Supports enqueue, dequeue, isEmpty.

**Tests** – Contains unit tests using [doctest](https://github.com/doctest/doctest) to validate each module:
* `test_graph.cpp`: Edge addition/removal, invalid vertices.
* `test_algorithms.cpp`: BFS, DFS, Dijkstra, Prim, Kruskal.
* `test_min_heap.cpp`: Heap operations and edge cases.
* `test_union_find.cpp`: Find, union operations.
* `test_queue.cpp`: Queue behavior, overflow/underflow.

**Demo (main)** – The main.cpp file contains example demonstrations that showcase the usage of the implemented algorithms. It includes:
* A connected graph without edge weights (default weights) to demonstrate traversal.
* A connected graph with weighted edges to show the effect on MST and shortest paths.
* A disconnected graph with weighted edges, highlighting how algorithms like Prim and Dijkstra behave in  partially connected components.

Each algorithm is executed on these examples, and the results are printed using the print_graph() method, helping visualize the output structure of each approach.


## Compilation and Running

* `make Main` – Compile all source files and run the main program.
* `make test` – Run all tests
* `make valgrind` – Run valgrind on main
* `make valgrind-test` – Run valgrind on tests
* `make clean` – Clean all build files

## Notes

* Manual memory management is used throughout.
* STL containers (e.g., `vector`, `map`) are not used.
* All errors (e.g., invalid edges, out-of-bounds access) throw exceptions.
