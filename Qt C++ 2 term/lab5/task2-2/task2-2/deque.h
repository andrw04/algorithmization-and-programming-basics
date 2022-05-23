#ifndef DEQUE_H
#define DEQUE_H


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
        bool operator==(T* right)
        {
            return current == right;
        }
        bool operator!=(Iterator right)
        {
            return current != right.current;
        }

    };

    T** ptr_array;
    int capacity = 2;
    int size = 0;
    int k = 2;
    Iterator begin;
    Iterator end;
    int begin_index = 0;
    int end_index = 0;
    T front_element;
    T end_element;
    void resize()
    {
        if (capacity == size)
        {
            capacity *= k;
            T** temp = new T * [capacity / k];
            int id = begin_index;
            for (int i = 0; i < size / k; i++)
            {
                temp[i] = ptr_array[id];
                if (id == size / k - 1)
                    id = 0;
                else
                    id++;
            }
            for (int i = size / k; i < capacity / k; i++)
            {
                temp[i] = new T[k];
            }
            end_index = size / k;
            begin_index = 0;
            delete ptr_array;
            ptr_array = temp;
            end = ptr_array[end_index];
            begin = ptr_array[begin_index];
        }
    }

public:
    Deque()
    {
        ptr_array = new T * [capacity / k];
        for (int i = 0; i < capacity / k; i++)
        {
            ptr_array[i] = new T[k];
        }
        begin = ptr_array[0];
        end = ptr_array[0];
        front_element = end_element = 0;
    }
    void push_back(T value)
    {
        resize();
        *end = value;
        if (end == ptr_array[end_index] + (k - 1))
        {
            if (end == ptr_array[capacity / k - 1] + (k - 1))
            {
                end_index = 0;
                end = ptr_array[end_index];
            }
            else
            {
                end_index++;
                end = ptr_array[end_index];
            }
        }
        else
        {
            end++;
        }
        size++;
        end_element = value;
    }
    void push_front(T value)
    {
        resize();
        if (begin == ptr_array[begin_index])
        {
            if (begin == ptr_array[0])
            {
                begin = ptr_array[capacity / k - 1] + (k - 1);
                begin_index = capacity / k - 1;
            }
            else
            {
                begin_index--;
                begin = ptr_array[begin_index] + (k - 1);
            }
        }
        else
        {
            begin--;
        }
        *begin = value;
        front_element = value;
        size++;

    }
    void pop_back()
    {
        if (end == ptr_array[end_index])
        {
            if (end == ptr_array[0])
            {
                end = ptr_array[capacity / k - 1] + (k - 1);
                end_index = capacity / k - 1;
            }
            else
            {
                end_index--;
                end = ptr_array[end_index] + (k - 1);
            }
        }
        else
        {
            end--;
        }
        *end = 0;
        Iterator it = end;
        int tmp = end_index;
        if (it == ptr_array[tmp])
        {
            if (it == ptr_array[0])
            {
                it = ptr_array[capacity / k - 1] + (k - 1);
                tmp = capacity / k - 1;
            }
            else
            {
                tmp--;
                it = ptr_array[tmp] + (k - 1);
            }
        }
        else
        {
            it--;
        }
        end_element = *it;
        size--;
    }
    void pop_front()
    {
        *begin = 0;
        if (begin == ptr_array[begin_index] + (k - 1))
        {
            if (begin == ptr_array[capacity / k - 1] + (k - 1))
            {
                begin_index = 0;
                begin = ptr_array[begin_index];
            }
            else
            {
                begin_index++;
                begin = ptr_array[begin_index];
            }
        }
        else
        {
            begin++;
        }
        size--;
        front_element = *begin;
    }
    T front()
    {
        return front_element;
    }
    T back()
    {
        return end_element;
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
        for (int i = 0; i < size / k; i++)
        {
            delete ptr_array[i];
        }
        delete ptr_array;
        size = 0;
    }
    T& random_access(int index)
    {
        return ptr_array[index / k][index % k];
    }
};

#endif // DEQUE_H
