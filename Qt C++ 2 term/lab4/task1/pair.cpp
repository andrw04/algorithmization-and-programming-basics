#include "pair.h"

template<class T1, class T2>
Pair<T1, T2>::Pair(const T1 &x, const T2 &y)
{
    first = x;
    second = y;
}

template<class T1, class T2>
Pair<T1,T2> &Pair<T1, T2>::operator=(const Pair &other)
{
    first = other.first;
    second = other.second;
}

template<class T1, class T2>
void Pair<T1, T2>::swap(Pair &other) noexcept
{
    std::swap(first,other.first);
    std::swap(second,other.second);
}

template<class T1, class T2>
bool Pair<T1, T2>::operator==(const Pair<T1, T2> &rhs)
{
    return first == rhs.first && second == rhs.second;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator!=(const Pair<T1, T2> &rhs)
{
    return first != rhs.first && second != rhs.second;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &rhs)
{
    return first < rhs.first && second < rhs.second;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2> &rhs)
{
    return first > rhs.first && second > rhs.second;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator <=(const Pair<T1, T2> &rhs)
{
    return first <= rhs.first && second <= rhs.second;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator >=(const Pair<T1, T2> &rhs)
{
    return first >= rhs.first && second >= rhs.second;
}

template<class T1, class T2>
Pair<T1, T2> Pair<T1, T2>::make_pair(T1 t, T2 u)
{
    return Pair<T1,T2>(&t,&u);
}

template<class T1, class T2>
Pair<T1, T2>::Pair(const Pair<T1, T2> &p)
{
    first = p.first;
    second = p.second;
}



