#ifndef SHARED_PTR_H
#define SHARED_PTR_H


template<class T>
class SHARED_PTR
{
public:
    template<class C> friend
    class WEAK_PTR;
    SHARED_PTR(T *ptr = nullptr);
    SHARED_PTR(SHARED_PTR<T> &ptr);
    SHARED_PTR(SHARED_PTR<T> &&other) noexcept;
    T *get();
    int use_count();
    bool unique();
    void reset();
    T &operator*();
    T *operator->();
    operator bool() const;
    SHARED_PTR &operator=(const SHARED_PTR<T> &other) noexcept;
    ~SHARED_PTR();
private:
    int *count;
    T *pointer;
};

#endif // SHARED_PTR_H
