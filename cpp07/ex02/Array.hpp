#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <iomanip>


template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array(){
            _array = NULL;
            _size = 0;
        }
        Array(unsigned int n){
            _array = new T[n];
            _size = n;
        }
        Array(Array const &other)
        {
            _array = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        Array &operator=(Array const &other)
        {
            if (this != &other)
            {
                delete [] _array;
                _array = new T[other._size];
                _size = other._size;
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return (*this);
        }
        T &operator[](unsigned int n)
        {
            if (n >= _size)
                throw std::exception();
            return (_array[n]);
        }
        ~Array(){
            delete [] _array;
        }
        unsigned int size() const{
            return (_size);
        }
};


#endif
