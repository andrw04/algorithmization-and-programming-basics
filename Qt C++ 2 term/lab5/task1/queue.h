#ifndef QUEUE_H
#define QUEUE_H
#include <memory>
#include <QDebug>

template<class T>
class Queue
{
public:
    Queue();

    Queue(T data);

    T& back();

    T& front();

    virtual void push_back(T value);

    void pop_front();

    int getSize();

    bool empty();
public:

    std::shared_ptr<Queue<T>> first;
    std::shared_ptr<Queue<T>> last;
    std::shared_ptr<Queue<T>> next;
    std::shared_ptr<Queue<T>> prev;

    int size = 0;
    T value;
};



#endif // QUEUE_H
