#include "iter.hpp"

int main(void) {
    const int size = 10;
    int arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = i;
    std::cout << "Array before iter: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        std::cout << " ";
    }
    iter(arr, size, ft_increment);
    std::cout << std::endl;
    std::cout << "Array after iter:  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}