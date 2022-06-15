#include "easyfind.hpp"

int main(void) {
    /* initialize random seed: */
    srand (time(NULL));
    int to_found;
    std::cout << FPURPLE << "----------------TEST1(VECTOR)----------------" << NONE << std::endl;
    std::vector<int> vec;
    /* fill vec with random numbers between 1 and 3: */
    for (int i = 0; i < 10; i++)
        vec.push_back(rand() % 3 + 1);
    for (int i = 0; i < 10; i++)
    {
        std::cout << vec[i];
        if (i < 9)
            std::cout << " | ";
        else
            std::cout << std::endl;
    }
    try
    {
        to_found = 2;
        std::cout << "Element to found: " << to_found << std::endl;
        int a = ::easyfind(vec, to_found);
        std::cout << FGREEN << a << " was found" << NONE << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << FRED << e.what() << NONE << '\n';
    }
    
    std::cout << FPURPLE << "----------------TEST2(ARRAY)----------------" << NONE << std::endl;
    std::array<int, 10> arr;
    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 100 + 1;
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i];
        if (i < 9)
            std::cout << " | ";
        else
            std::cout << std::endl;
    }
    try
    {
        to_found = 20;
        std::cout << "Element to found: " << to_found << std::endl;
        int a = ::easyfind(arr, to_found);
        std::cout << FGREEN << a << " was found" << NONE << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << FRED << e.what() << NONE << '\n';
    } 

    std::cout << FPURPLE << "----------------TEST3(DEQUE)----------------" << NONE << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
        deq.push_back(rand() % 100 + 1);
    for (int i = 0; i < 10; i++)
    {
        std::cout << deq[i];
        if (i < 9)
            std::cout << " | ";
        else
            std::cout << std::endl;
    }
    try
    {
        to_found = 2;
        std::cout << "Element to found: " << to_found << std::endl;
        int a = ::easyfind(deq, to_found);
        std::cout << FGREEN << a << " was found" << NONE << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << FRED << e.what() << NONE << '\n';
    } 

    std::cout << FPURPLE << "----------------TEST4(LIST)----------------" << NONE << std::endl;
    std::list<int> mylist;
    for (int i = 0; i < 10; i++)
        mylist.push_back(rand() % 100 + 1);
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << *it << " | ";
    std::cout << std::endl;
    try
    {
        to_found = 6;
        std::cout << "Element to found: " << to_found << std::endl;
        int a = ::easyfind(mylist, to_found);
        std::cout << FGREEN << a << " was found" << NONE << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << FRED << e.what() << NONE << '\n';
    }
    return (0);
}