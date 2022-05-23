#ifndef PAIR_H
#define PAIR_H
#include <iostream>

template<class T1, class T2>
struct Pair
{
public:
    // constructors
    Pair( const T1& x, const T2& y );

    Pair( const Pair<T1,T2>& p );

    // copy operator
    Pair& operator=( const Pair& other );

    void swap( Pair& other ) noexcept;

    // operators
    bool operator==(const Pair<T1,T2> &rhs);

    bool operator !=(const Pair<T1,T2> &rhs);

    bool operator< (const Pair<T1,T2> &rhs);

    bool operator> (const Pair<T1,T2> &rhs);

    bool operator <=(const Pair<T1,T2> &rhs);

    bool operator >=(const Pair<T1,T2> &rhs);

    Pair<T1,T2> make_pair( T1 t, T2 u );


    // data
    T1 first;
    T2 second;
};

#endif // PAIR_H
