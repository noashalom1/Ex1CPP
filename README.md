# Graph Algorithms Project

## ✨ Project Overview

This project implements an **undirected graph** using an **Adjacency List** data structure in C++, without using the STL (Standard Template Library). It also includes full implementations of classical graph algorithms, using custom-built data structures.

## 🧩 Project Structure

### Source Files

| File                        | Description |
|-----------------------------|-------------|
| `graph.hpp / graph.cpp`     | Core `Graph` class using adjacency lists |
| `algorithms.hpp / .cpp`     | Graph algorithms: BFS, DFS, Dijkstra, Prim, Kruskal |
| `queue.hpp / queue.cpp`     | Basic FIFO queue (used in BFS) |
| `min_heap.hpp / min_heap.cpp` | Min-Priority Queue for Dijkstra and Prim |
| `union_find.hpp / .cpp`     | Disjoint Set Union (Union-Find) for Kruskal |
| `main.cpp`                  | Demonstration of graph usage and algorithms |
| `Makefile`                  | Build and run the project using make commands |

---

## 🧪 How to Use

### 🔧 Build the Project:

```bash
make
