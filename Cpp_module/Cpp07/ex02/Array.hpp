#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <class T>
class Array
{
private:
    unsigned int _n;
    T *arr;
public:
    Array();
    Array(unsigned int n);
    Array(Array const &array);
	Array &operator=(Array const &array);
    unsigned int size() const;
    ~Array();
    class IndexOutOfRange : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return ("Index out of range!");
        }
    };

    T& operator[](int index);
    T& operator[](int index) const;
};

#endif

template <typename T>
Array<T>::Array() : _n(0), arr(nullptr) {
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n) {
    std::cout << "Array constructor called with " << n << " elements" << std::endl;
    arr = new T[_n];
}

template <typename T>
Array<T>::Array(Array const &array) {
    std::cout << "Array copy constructor called" << std::endl;
    *this = array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &array) {
    std::cout << "Array assignment operator called" << std::endl;
    if (this != &array)
    {
        _n = array._n;
        arr = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
            arr[i] = array.arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    delete [] arr;
}

template <typename T>
unsigned int Array<T>::size() const { 
    return (_n);
}

template <typename T>
T & Array<T> :: operator[](int i) {
    if (i == 0 && _n == 0)
        throw Array<T>::IndexOutOfRange();
	if (i < 0 || static_cast<unsigned int>(i) > _n - 1)
		throw Array<T>::IndexOutOfRange();
	else
		return arr[i];
}