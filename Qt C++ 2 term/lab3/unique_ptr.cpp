#include "unique_ptr.h"

template<class T>
UNIQUE_PTR<T>::UNIQUE_PTR(T *ptr)
{
    pointer = ptr;
}

template<class T>
UNIQUE_PTR<T>::UNIQUE_PTR(UNIQUE_PTR<T> &ptr)
{
    pointer = ptr.pointer;
    delete ptr.pointer;
    ptr.pointer = nullptr;
}

template<class T>
UNIQUE_PTR<T>::~UNIQUE_PTR()
{
    if (pointer)
        delete pointer;
    pointer = nullptr;
}

template<class T>
UNIQUE_PTR<T>::UNIQUE_PTR(UNIQUE_PTR<T> &&other)
{
    pointer = std::move(other.pointer);
    other.pointer = nullptr;
}

template<class T>
void UNIQUE_PTR<T>::release()
{
    pointer = nullptr;
}

template<class T>
T *UNIQUE_PTR<T>::get()
{
    return pointer;
}

template<class T>
void UNIQUE_PTR<T>::reset(T *cur)
{
    T *old = this->pointer;
    this->pointer = cur;

    delete old;
}

template<class T>
UNIQUE_PTR<T> &UNIQUE_PTR<T>::operator=(UNIQUE_PTR &&rhs)
{
    delete pointer;
    pointer = std::move(rhs.pointer);
    rhs.pointer = nullptr;
    return *this;
}

template<class T>
T &UNIQUE_PTR<T>::operator*()
{
    return *pointer;
}

template<class T>
T *UNIQUE_PTR<T>::operator->()
{
    return pointer;
}

template<class T>
UNIQUE_PTR<T>::operator bool() const
{
    return pointer != nullptr;
}


