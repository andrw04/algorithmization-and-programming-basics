#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <QString>


template <class T>
class Stack
{
public:
    int capacity;
    int index;
    T* array;
    Stack(int capacity = 50) {
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
    Stack<std::pair<int,QString>>** table;
    int size = 0;
    void resize()
    {
        capacity *= 2;
        Stack<std::pair<int,QString>>** temp = new Stack<std::pair<int,QString>>*[capacity];
        for(int i = 0; i < capacity / 2;i++)
        {
            temp[i] = table[i];
        }
        for (int i = capacity / 2; i < capacity; i++)
        {
            temp[i] = nullptr;
        }
        delete table;
        table = temp;
    }

public:
    int capacity = 10;
    HashTable()
    {
        table = new Stack<std::pair<int,QString>> * [capacity];
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
        return key % 13;
    }
    void Add(int key, QString value)
    {
        int index = GetHash(key);
        while(index > capacity - 1)
            resize();
        if (table[index] == nullptr)
        {
            Stack<std::pair<int,QString>> *tmp = new Stack<std::pair<int,QString>>();
            tmp->push(std::make_pair(key,value));
            table[index] = tmp;
        }
        else
        {
            Stack<std::pair<int,QString>>* tmp = table[index];
            tmp->push(std::make_pair(key,value));
        }

    }
    void Remove(int id)
    {

        int index = GetHash(id);
        Stack<std::pair<int,QString>>* tmp = table[index];
        if(!tmp->empty())
            tmp->pop();
        else
        {
            delete tmp;
            table[index] = nullptr;
        }
    }
    Stack<std::pair<int,QString>>* Find(int id)
    {
        int index = GetHash(id);
        Stack<std::pair<int,QString>>* tmp = table[index];
        return tmp;
    }
};

#endif // HASHTABLE_H
