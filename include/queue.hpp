// noapatito123@gmail.com

#ifndef SIMPLE_QUEUE_HPP
#define SIMPLE_QUEUE_HPP

namespace graph {

class Queue {
private:
    int* data;
    int capacity, size, front, rear;


public:
    Queue(int capacity);
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
};

} // namespace graph

#endif
