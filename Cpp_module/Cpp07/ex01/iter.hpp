#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T1>
void iter(T1 *array, const int size, void (*func)(T1 &array))
{
    for (int i = 0; i < size; i++)
        (*func)(array[i]);
}

template <typename T>
void ft_increment(T &a) {
    a++;
}

#endif