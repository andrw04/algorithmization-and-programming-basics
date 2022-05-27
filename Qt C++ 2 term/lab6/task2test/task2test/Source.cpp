#include <iostream>

template <class T>
class Stack
{
public:
    int capacity;
    int index;
    T* array;
    Stack(int capacity = 20) {
        this->capacity = capacity;
        this->index = 0;
        array = new T[capacity];
    }
    void push(T element)
    {
        array[index++] = element;
    }
    T pop()
    {
        return array[--index];
    }
    T& top()
    {
        return array[index - 1];
    }
    bool empty()
    {
        return index == 0;
    }
    int size()
    {
        return index;
    }

};


template<class T>
class HashTable
{
protected:
    Stack<T>** table;
    int size = 0;
    void resize()
    {
        capacity *= 2;
        Stack<T>** temp = new Stack<T>*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = nullptr;
        }
        for (int i = 0; i < capacity / 2; i++)
        {
            temp[i] = table[i];
        }
        delete table;
        table = temp;
    }

public:
    int capacity = 10;
    HashTable()
    {
        table = new Stack<T> *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
            delete table[i];
        delete table;
    }
    int GetHash(int key)
    {
        return key % 123;
    }
    void Add(int key, T value)
    {
        int index = GetHash(key);
        while (index > capacity - 1)
            resize();
        if (table[index] == nullptr)
        {
            Stack<T>* tmp = new Stack<T>();
            tmp->push(value);
            table[index] = tmp;
        }
        else
        {
            Stack<T>* tmp = table[index];
            tmp->push(value);
        }

    }
    void Remove(int id)
    {
        int index = GetHash(id);
        Stack<T>* tmp = table[index];
        if (!tmp->empty())
            tmp->pop();
    }
    Stack<T>* Find(int id)
    {
        int index = GetHash(id);
        Stack<T>* tmp = table[index];
        return tmp;
    }
};

int main()
{
    HashTable<int>* table = new HashTable<int>();
    for (int i = 0; i < 123;i++)
    {
        table->Add(i, 1);
    }
}