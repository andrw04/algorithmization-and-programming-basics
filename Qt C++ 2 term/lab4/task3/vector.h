#ifndef Vector_H
#define Vector_H

#include<iostream>
#include<QDebug>
template <class T>
class Vector
{
public:
    class Iter{
    public:
        Iter(T *ptr): ptr(ptr){};
        ~Iter(){};
        bool operator == (const Iter& rhs) const
        {
            return ptr == rhs.ptr;
        };

        bool operator != (const Iter& rhs) const
        {
            return !(*this == rhs);
        };

        Iter& operator = (const Iter &rhs)
        {
            ptr = rhs.ptr;
        };

        T& operator*() const
        {
            return *ptr;
        };

        T* operator->()
        {
            return ptr;
        };

        T* operator&()
        {
            return ptr;
        };

        Iter& operator++()
        {
            ptr++;
            return *this;
        }

        Iter& operator--()
        {
            ptr++;
            return *this;
        }

    private:
        T *ptr = nullptr;
    };


    explicit Vector();
    Vector(int size, const T &defaultElement);
    Vector(int size);
    Vector(const Vector &copyVector);
    Vector(Vector &&moveVector);
    Vector(const std::initializer_list<T> &Iter);
    ~Vector();

    void assign(const int& newSize, const T& element);
    T &at(int index);
    T &back();
    Iter begin() noexcept;
    int capacity() const noexcept;
    Iter const cbegin() const noexcept;
    Iter const cend() noexcept;
    Iter const crbegin() const noexcept;
    Iter const crend() const noexcept;
    void clear();
    T* data();
    void emplace(const int& insertPosition,T &&insertElement);
    void emplace_back(T &&element);
    bool empty();
    Iter end();
    void erase(const int& erasePosition);
    T& front();
    void insert(const int& insertPosition,const T& insertElement);
    long long maxsize();
    void pop_back();
    void print();
    void push_back(const T &addElement);
    Iter rbegin();
    Iter rend();
    void reserve(const int &capacity);
    void resize(const int& newSize);
    int size() const noexcept;
    void swap(Vector &rhs);
    void swap(Vector &&rhs);

    T& operator[](const int& index);
    T& operator[](const int& index)const;

private:
    void checkMemory();

    T *_Vector;
    int s1ze;
    int _capacity;
};

#endif // Vector_H
