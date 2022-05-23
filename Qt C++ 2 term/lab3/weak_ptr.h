#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include <shared_ptr.h>
//#include <shared_ptr.cpp>
#include <iostream>

template<class T>
class WEAK_PTR
{
public:
    WEAK_PTR();
    WEAK_PTR(const WEAK_PTR &ptr);
    WEAK_PTR(SHARED_PTR<T> &ptr);
    ~WEAK_PTR();
    int use_count();
    WEAK_PTR &operator=(WEAK_PTR<T> &rhs);
    WEAK_PTR &operator=(SHARED_PTR<T> &rhs);
    SHARED_PTR<T> lock();
    void reset();
    bool expired();

private:
    T *pointer;
    int *count;
};

#endif // WEAK_PTR_H
