#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <iostream>

template<class T>
class UNIQUE_PTR
{
public:
    UNIQUE_PTR(T *ptr = nullptr);
    UNIQUE_PTR(UNIQUE_PTR<T> &pointer);
    ~UNIQUE_PTR();
    UNIQUE_PTR(UNIQUE_PTR<T> &&other);
    void release();
    T *get();
    void reset(T *cur);
    UNIQUE_PTR &operator=(UNIQUE_PTR &&rhs);
    T &operator*();
    T *operator->();
    operator bool() const;
private:
    T * pointer;

};


#endif // UNIQUE_PTR_H
