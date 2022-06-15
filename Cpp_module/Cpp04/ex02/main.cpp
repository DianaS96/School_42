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
    dynamic_cast<Cat *>(animals[3])->printIdea(2);
    dynamic_cast<Dog *>(animals[1])->printIdea(999);
    animals[0]->makeSound();
    animals[3]->makeSound();

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
    return 0;
}
