#include "vector.h"

template<class T>
Vector<T>::Vector() : s1ze(0),  _capacity(1)
{
    _Vector = new T[_capacity];
}

template<class T>
Vector<T>::Vector(int Size, const T &defaultElement): s1ze(Size),  _capacity(Size + 1)
{
    _Vector = new T[_capacity];

    for(int i = 0 ; i< s1ze ; i++){
        _Vector[i] = defaultElement;
    }
}

 template<class T>
Vector<T>::Vector(int size): s1ze(size),  _capacity(size + 1)
{
    _Vector = new T[_capacity];

    for(int i = 0 ; i< s1ze ; i++){
        _Vector[i] = 0;
    }
}

template<class T>
Vector<T>::Vector(const Vector &copyVector) : s1ze(copyVector.size),_capacity(copyVector._capacity)
{
    _Vector = new T[_capacity];

    for(int i = 0; i < s1ze;i++){
        _Vector = copyVector._Vector[i];
    }
}

template<class T>
Vector<T>::Vector(Vector &&moveVector) : s1ze(moveVector.size),_capacity(moveVector._capacity)
{
    _Vector = new T[_capacity];

    for(int i = 0; i < s1ze; i++){
        _Vector = moveVector._Vector[i];
    }
}

template<class T>
Vector<T>::Vector(const std::initializer_list<T> &Iter): s1ze(Iter.size()),_capacity(s1ze + 1)
{
    _Vector = new T[_capacity];
    int index = 0;

    for(auto i = Iter.begin(); i < Iter.end();i++){
        _Vector[index++] = *i;
    }
}

template<class T>
Vector<T>::~Vector()
{
    delete _Vector;
}


template<class T>
void Vector<T>::assign(const int& newSize, const T& element)
{
    delete _Vector;

    s1ze = newSize;
    _capacity = s1ze + 1;
    _Vector = new T[_capacity];

    for(int i = 0 ; i < s1ze; i++){
        _Vector[i] = element;
    }
}

template<class T>
T &Vector<T>::at(int index)
{
    return _Vector[index];
}

template<class T>
T &Vector<T>::back()
{
    return _Vector[s1ze - 1];
}

template<class T>
class Vector<T>::Iter Vector<T>::begin()noexcept
{
    return &_Vector[0];
}

template<class T>
int Vector<T>::capacity() const noexcept
{
    return _capacity;
}


template<class T>
class Vector<T>::Iter const Vector<T>::cbegin() const noexcept
{
    if(s1ze == 0)
        return nullptr;
    return Iter(_Vector[0]);
}

template<class T>
class Vector<T>::Iter const Vector<T>::cend() noexcept
{
    if(s1ze == 0)
        return nullptr;
    return Iter(_Vector[s1ze]);
}

template<class T>
void Vector<T>::clear()
{
    s1ze = 0;
    _capacity = 1;

    delete _Vector;

    _Vector = new T[_capacity];
}

template<class T>
T* Vector<T>::data()
{
    if(s1ze == 0)
        return nullptr;
    return _Vector[0];
}

template<class T>
void Vector<T>::emplace(const int& insertPosition,T &&insertElement)
{
    if(insertPosition < s1ze - 1){
        if(s1ze >= _capacity - 1){
            _capacity *= 3.0/2;
        }

        T* tmp = _Vector;
        _Vector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < s1ze; i++){
            if(i == insertPosition){
                _Vector[currentIndex++] = std::move(insertElement);
            }
            _Vector[currentIndex++] = std::move(tmp[i]);
        }

        s1ze++;
        delete[] tmp;
    }
}

template<class T>
void Vector<T>::emplace_back(T &&insertElement)
{
    checkMemory();
    _Vector[s1ze++] = std::move(insertElement);
}

template<class T>
bool Vector<T>::empty()
{
    return !s1ze;
}

template<class T>
class Vector<T>::Iter Vector<T>::end()
{
    if(s1ze == 0)
        return nullptr;
    return &_Vector[s1ze];
}

template<class T>
void Vector<T>::erase(const int& erasePosition)
{
    if(erasePosition <= s1ze - 1){
        T* tmp = _Vector;

        _Vector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < s1ze; i++){
            if(i == erasePosition)
                continue;
            _Vector[currentIndex++] = tmp[i];
        }

        s1ze--;
        delete[] tmp;
    }
}

template<class T>
T &Vector<T>::front()
{
    if(s1ze == 0)
        return nullptr;
    return _Vector[s1ze - 1];
}

template<class T>
long long Vector<T>::maxsize(){
    long long S = pow(2,64)/8;
    return S - 1;
}

template<class T>
void Vector<T>::insert(const int& insertPosition,const T& insertElement)
{
    if(insertPosition < s1ze - 1){
        if(s1ze >= _capacity - 1){
            _capacity *= 3.0/2;
        }

        T* tmp = _Vector;
        _Vector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < s1ze; i++){
            if(i == insertPosition){
                _Vector[currentIndex++] = insertElement;
            }
            _Vector[currentIndex++] = tmp[i];
        }

        s1ze++;
        delete[] tmp;
    }

}

template<class T>
void Vector<T>::pop_back()
{
    if(s1ze == 0 )
        return;
    --s1ze;
}

template<class T>
void Vector<T>::print()
{
    for(int i = 0; i < s1ze; i++){
        qDebug()<< _Vector[i] << ' ';
    }

    qDebug() << "||";

    for(int i = s1ze; i < _capacity; i++){
        qDebug() << "none" << ' ';
    }
    qDebug() << "";
}

template<class T>
void Vector<T>::push_back(const T &addElement)
{
    checkMemory();
    _Vector[s1ze++] = addElement;
}

template<class T>
class Vector<T>::Iter Vector<T>::rbegin()
{
    if(s1ze == 0)
        return nullptr;
    return _Vector[s1ze];
}

template<class T>
class Vector<T>::Iter Vector<T>::rend()
{
    if(s1ze == 0)
        return nullptr;
    return _Vector[0];
}

template<class T>
void Vector<T>::reserve(const int &capacity)
{
    T* tmp = _Vector;

    _capacity = capacity;
    s1ze = _capacity - 1;
    _Vector = new T[_capacity];

    for(int i = 0; i < s1ze; i++){
        _Vector[i] = tmp[i];
    }

    delete[] tmp;

}

template<class T>
void Vector<T>::resize(const int &newSize)
{
    if(newSize == s1ze){
        return;
    }
    else if(newSize < s1ze){
        for(int i = s1ze - 1;i > newSize - 1; i--){
            _Vector[i] = 0;
        }
    }
    else{
        T* tmp = _Vector;

        _capacity = newSize;
        _Vector = new T[_capacity];

        for(int i = 0; i < s1ze; i++){
            _Vector[i] = tmp[i];
        }

        delete[] tmp;
        for(int i = newSize - 1;i > s1ze; i--){
            _Vector[i] = 0;
        }
    }
    s1ze = newSize;
}

template<class T>
int Vector<T>::size() const noexcept
{
    return size;
}

template<class T>
void Vector<T>::swap(Vector &rhs)
{
    qSwap(_Vector,rhs._Vector);
    qSwap(s1ze,rhs.size);
    qSwap(_capacity,rhs._capacity);
}

template<class T>
void Vector<T>::swap(Vector &&rhs)
{
    qSwap(_Vector,rhs._Vector);
    qSwap(s1ze,rhs.size);
    qSwap(_capacity,rhs._capacity);
}

template<class T>
T &Vector<T>::operator[](const int &index)
{
    return _Vector[index];
}
template<class T>
T &Vector<T>::operator[](const int &index) const
{
    return _Vector[index];
}


template<class T>
void Vector<T>::checkMemory()
{
    if(s1ze >= _capacity - 1){
        T* tmp = _Vector;

        _capacity *= 2;
        _Vector = new T[_capacity];
        for(int i = 0; i < s1ze; i++){
            _Vector[i] = tmp[i];
        }

        delete[] tmp;
    }
}
