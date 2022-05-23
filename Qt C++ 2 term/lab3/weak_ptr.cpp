#include "weak_ptr.h"

template<class T>
WEAK_PTR<T>::WEAK_PTR()
{
    pointer = nullptr;
    count = nullptr;
}

template<class T>
WEAK_PTR<T>::WEAK_PTR(const WEAK_PTR &ptr)
{
    ptr = ptr.pointer;
    count = ptr.count;
}

template<class T>
WEAK_PTR<T>::WEAK_PTR(SHARED_PTR<T> &ptr)
{
    count = ptr.count;
    pointer = ptr.get();
}

template<class T>
WEAK_PTR<T>::~WEAK_PTR()
{

}

template<class T>
int WEAK_PTR<T>::use_count()
{
    return pointer != nullptr ? *count : 0;
}

template<class T>
WEAK_PTR<T> &WEAK_PTR<T>::operator=(WEAK_PTR<T> &rhs)
{
    this->count = rhs.count;
    T *temp = rhs.ptr;
    std::swap(this->ptr, temp);
    return *this;
}

template<class T>
WEAK_PTR<T> &WEAK_PTR<T>::operator=(SHARED_PTR<T> &rhs)
{
    this->count = rhs.count;
    this->pointer = rhs.pointer;
}

template<class T>
SHARED_PTR<T> WEAK_PTR<T>::lock()
{
    return (expired() ? SHARED_PTR<T>() : SHARED_PTR<T>(*this));
}

template<class T>
void WEAK_PTR<T>::reset()
{
    count = nullptr;
    pointer = nullptr;
}

template<class T>
bool WEAK_PTR<T>::expired()
{
    return use_count() == 0 || pointer == nullptr;
}
