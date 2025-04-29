// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queue.hpp"

using namespace graph;

TEST_CASE("Queue basic operations") {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK(q.dequeue() == 1);
    CHECK(q.dequeue() == 2);
    CHECK(q.dequeue() == 3);
    CHECK(q.isEmpty());
}

TEST_CASE("Queue overflow throws") {
    Queue q(2);
    q.enqueue(1);
    q.enqueue(2);
    CHECK_THROWS_AS(q.enqueue(3), std::runtime_error);
}

TEST_CASE("Queue underflow throws") {
    Queue q(1);
    CHECK_THROWS_AS(q.dequeue(), std::runtime_error);
}

TEST_CASE("Queue enqueue and dequeue wrap-around behavior") {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    CHECK(q.dequeue() == 1);
    q.enqueue(3);
    CHECK(q.dequeue() == 2);
    CHECK(q.dequeue() == 3);
    CHECK(q.isEmpty());
}

TEST_CASE("isEmpty reflects state transitions") {
    Queue q(2);
    CHECK( q.isEmpty() );         

    q.enqueue(7);
    CHECK_FALSE( q.isEmpty() );  

    q.dequeue();
    CHECK( q.isEmpty() );         
}

TEST_CASE("Queue capacity 1 behaves correctly") {
    Queue q(1);
    q.enqueue(42);
    CHECK_THROWS_AS(q.enqueue(99), std::runtime_error);  // overflow

    CHECK(q.dequeue() == 42);
    CHECK_THROWS_AS(q.dequeue(), std::runtime_error);    // underflow
    CHECK( q.isEmpty() );
}

TEST_CASE("Multiple wrap-arounds maintain order") {
    Queue q(2);

    for (int i = 0; i < 5; ++i) { 
        q.enqueue(i);
        CHECK(q.dequeue() == i);
        CHECK( q.isEmpty() );
    }
}

TEST_CASE("Overflow after wrap-around throws") {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK_THROWS_AS(q.enqueue(4), std::runtime_error);   

    CHECK(q.dequeue() == 1);        
    q.enqueue(4);                   

    CHECK_THROWS_AS(q.enqueue(5), std::runtime_error);  
}

TEST_CASE("Underflow after partial operations throws") {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(11);
    CHECK(q.dequeue() == 10);
    CHECK(q.dequeue() == 11);
    CHECK_THROWS_AS(q.dequeue(), std::runtime_error);    
}

