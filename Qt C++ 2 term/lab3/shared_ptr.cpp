#include "shared_ptr.h"

template<class T>
SHARED_PTR<T>::SHARED_PTR(T *ptr)
{
    pointer = ptr;
    count = new int(1);
}

template<class T>
SHARED_PTR<T>::SHARED_PTR(SHARED_PTR<T> &ptr)
{
    pointer = ptr.pointer;
    count = ptr.count;
    ++(*count);
}

template<class T>
SHARED_PTR<T>::SHARED_PTR(SHARED_PTR<T> &&other) noexcept
{
    pointer = other.pointer;
    count = other.count;
    ++(*count);
}

template<class T>
T *SHARED_PTR<T>::get()
{
    return pointer;
}

template<class T>
int SHARED_PTR<T>::use_count()
{
    return *count;
}

template<class T>
bool SHARED_PTR<T>::unique()
{
    return *count == 1;
}

template<class T>
T &SHARED_PTR<T>::operator*()
{
    return *pointer;
}

template<class T>
T *SHARED_PTR<T>::operator->()
{
    return pointer;
}

template<class T>
SHARED_PTR<T>::operator bool() const
{
    return pointer != nullptr;
}

template<class T>
SHARED_PTR<T> &SHARED_PTR<T>::operator=(const SHARED_PTR<T> &other) noexcept
{
    ++(*other.count);
            --(*count);
            if (!(*count)) {
                delete pointer;
                delete count;
            }
            pointer = other.pointer;
            count = other.count;
            return *this;
}

template<class T>
SHARED_PTR<T>::~SHARED_PTR()
{
    --(*count);
    if (!*count)
    {
        delete count;
        delete pointer;
        pointer = nullptr;
    }
}
