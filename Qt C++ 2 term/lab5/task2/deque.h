#ifndef DEQUE_H
#define DEQUE_H
#include<QDebug>


template<class T>
class Deque
{
    class Iterator
    {
    public:
        T* current;
    public:
        Iterator()
        {
            current = nullptr;
        }
        Iterator(T* ptr)
        {
            current = ptr;
        }
        T& operator*()
        {
            return *current;
        }
        T& operator+(int n)
        {
            return *(current + n);
        }
        T& operator-(int n)
        {
            return *(current - n);
        }
        T& operator++(int)
        {
            return *current++;
        }
        T& operator--(int)
        {
            return *current--;
        }
        T& operator++()
        {
            return *++current;
        }
        T& operator--()
        {
            return *--current;
        }
        bool operator==(T *right)
        {
            return current == right;
        }
        bool operator!=(Iterator right)
        {
            return current != right.current;
        }

    };

    T* array;
    T** ptr_array;
    int capacity = 1;
    int size = 0;
    int k = 2;
    Iterator begin;
    Iterator end;
    void resize()
    {
        if (capacity == size)
        {
            capacity *= k;
            T* temp = new T[capacity * k];
            Iterator current = begin;
            for(int i = 0; i < size;i++)
            {
                temp[i] = *current;
                if (current == array + (capacity / k - 1))
                    current = array;
                else
                    current++;
            }
            delete array;
            array = temp;
            begin = array;
            end = array + (size);
        }
    }

public:
    Deque()
    {
        array = new T[capacity];
        begin = array;
        end = array;
    }
    void push_back(T value)
    {
        resize();
        *end = value;
        end++;
        size++;
    }
    void push_front(T value)
    {
        resize();
        if (begin == array)
            begin = array + (capacity - 1);
        else
            begin--;
        *begin = value;
        size++;
    }
    void pop_back()
    {
        *end = 0;
        if (end == array)
            end = array + (capacity - 1);
        else
            end--;
        size--;
    }
    void pop_front()
    {
        *begin = 0;
        if (begin == array + (capacity - 1))
            begin = array;
        else
            begin++;
        size--;
    }
    T& front()
    {
        return *begin;
    }
    T& back()
    {
        return end - 1;
    }
    int Size()
    {
        return size;
    }
    bool empty()
    {
        return size == 0 ? true : false;
    }
    void clear()
    {
        delete array;
        array = new T[capacity];
        begin = array;
        end = array;
    }
    T& randomAccess(int i)
    {
        Iterator tmp = begin;
        for (int j = 0; j < i; j++)
        {
            if (tmp == array + (capacity - 1))
                tmp = array;
            else
                tmp++;
        }
        return *tmp;
    }
};

#endif // DEQUE_H
