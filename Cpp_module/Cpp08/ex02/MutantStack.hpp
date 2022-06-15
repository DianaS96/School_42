#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

// Stack's underlying container - deque 
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack const &other);
    ~MutantStack();

    MutantStack &operator=(MutantStack const &other);

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    iterator begin() {return std::stack<T>::c.begin();}
    iterator end() {return std::stack<T>::c.end();}
    reverse_iterator rbegin() {return std::stack<T>::c.rbegin();}
    reverse_iterator rend() {return std::stack<T>::c.rend();}

};

template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
    if (this != &other)
        std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {};

#endif