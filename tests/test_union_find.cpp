// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "union_find.hpp"

using namespace graph;

TEST_CASE("UnionFind initial state") {
    UnionFind uf(3);
    CHECK(uf.find(0) == 0);
    CHECK(uf.find(1) == 1);
    CHECK(uf.find(2) == 2);
}

TEST_CASE("UnionFind union operation") {
    UnionFind uf(4);
    uf.unite(0, 1);
    uf.unite(2, 3);
    CHECK(uf.find(0) == uf.find(1));
    CHECK(uf.find(2) == uf.find(3));
    CHECK(uf.find(0) != uf.find(2));

    uf.unite(1, 2);
    CHECK(uf.find(0) == uf.find(3));
}

TEST_CASE("UnionFind repeatedly uniting same set") {
    UnionFind uf(3);
    uf.unite(0, 1);
    int root = uf.find(1);
    uf.unite(0, 1); 
    CHECK(uf.find(1) == root);
}

TEST_CASE("UnionFind with chain merges") {
    UnionFind uf(4);
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(2, 3);
    CHECK(uf.find(0) == uf.find(3));
}

TEST_CASE("UnionFind self-union does nothing") {
    UnionFind uf(5);
    int root2 = uf.find(2);
    uf.unite(2, 2);                      
    CHECK( uf.find(2) == root2 );
    CHECK( uf.find(3) == 3 );             
}

TEST_CASE("UnionFind union-by-rank keeps root stable") {
    UnionFind uf(4);
    uf.unite(0, 1);                      
    int root01 = uf.find(0);
    uf.unite(2, 3);                       
    uf.unite(0, 2);                      

    CHECK( uf.find(0) == root01 );
    CHECK( uf.find(1) == root01 );
    CHECK( uf.find(2) == root01 );
    CHECK( uf.find(3) == root01 );
}

TEST_CASE("UnionFind large chain compresses correctly") {
    const int N = 10;
    UnionFind uf(N);
    for (int i = 1; i < N; ++i)
        uf.unite(i - 1, i);          

    int root = uf.find(0);
    bool allSame = true;
    for (int i = 1; i < N; ++i)
        allSame &= (uf.find(i) == root);

    CHECK(allSame);
}

TEST_CASE("UnionFind multiple interleaved unions") {
    UnionFind uf(6);
    uf.unite(0, 2);
    uf.unite(1, 3);
    uf.unite(4, 5);
    uf.unite(0, 1);
    uf.unite(2, 4);

    int root = uf.find(0);
    for (int i = 1; i < 6; ++i)
        CHECK( uf.find(i) == root );
}

