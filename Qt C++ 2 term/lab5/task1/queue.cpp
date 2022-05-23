#include <queue.h>

template<class T>
Queue<T>::Queue()
{

}

template<class T>
Queue<T>::Queue(T data)
{
    value = data;
}

template<class T>
T &Queue<T>::back()
{
    return last->value;
}

template<class T>
T &Queue<T>::front()
{
    return first->value;
}

template<class T>
void Queue<T>::push_back(T value)
{
    if(size == 0)
    {
        first = std::shared_ptr<Queue<T>>(new Queue<T>(value));
        last = first;
    }
    else
    {
        last->next = std::shared_ptr<Queue<T>>(new Queue<T>(value));
        std::shared_ptr<Queue<T>> tmp = last;
        last = last->next;
        last->prev = tmp;
    }
    size++;
}

template<class T>
void Queue<T>::pop_front()
{
    if(size == 0)
    {
        qDebug() << "Empty list!";
        return;
    }
    else if(size == 1)
    {
        first.reset();
    }
    else
    {
        std::shared_ptr<Queue<T>> tmp = first;
        first = first->next;
        tmp.reset();
    }
    size--;
}

template<class T>
int Queue<T>::getSize()
{
    return size;
}

template<class T>
bool Queue<T>::empty()
{
    return size == 0 ? true : false;
}

