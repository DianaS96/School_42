#include "Cat.hpp"
#include "Dog.hpp"

void    ft_create_animals()
{
    std::cout << FPURPLE << "------------------Constructors------------------" << NONE << std::endl;
    const int size = 2;
    Animal *animals[size * 2];
    
    for (int i = 0; i < size * 2; i++)
    {
        if (i < size)
        {
            animals[i] = new Dog();
            std::cout << std::endl;
        }
        else
        {
            animals[i] = new Cat();
            std::cout << std::endl;
        }
    }
    dynamic_cast<Dog *>(animals[0])->printIdea(1);
    dynamic_cast<Cat *>(animals[2])->printIdea(2);
    dynamic_cast<Dog *>(animals[1])->printIdea(999);

    std::cout << FPURPLE << "------------------Destructors------------------" << NONE << std::endl;
    for (int i = 0; i < size * 2; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
}

int main()
{
    ft_create_animals();

    std::cout << FPURPLE << "------------------Deep copy check------------------" << NONE << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "basic address: " << &basic << std::endl;
        std::cout << "tmp address: " << &tmp << std::endl;
    std::cout << FPURPLE << "------------------Destructors for tmp------------------" << NONE << std::endl;
    }
    std::cout << FPURPLE << "------------------Destructors for basic------------------" << NONE << std::endl;
    return 0;
}
