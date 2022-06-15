#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << FGREEN << "------------------Constructors for Animal, Dog and Cat------------------" << NONE << std::endl;
    const Animal* meta = new Animal();
    std::cout <<std::endl;
    const Animal* j = new Dog();
    std::cout <<std::endl;
    const Animal* i = new Cat();
    std::cout <<std::endl;

    std::cout << FBLUE << "------------------Types (Dog and Cat)------------------" << NONE << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << FCYAN << "------------------Cat says smth------------------" << NONE << std::endl;
    i->makeSound(); //will output the cat sound!
    std::cout << FCYAN << "------------------Dog says smth------------------" << NONE << std::endl;
    j->makeSound();
    std::cout << FCYAN << "------------------Animal says smth------------------" << NONE << std::endl;
    meta->makeSound();

    std::cout << FGREEN << "------------------Constructors for WrongAnimal and WrongCat------------------" << NONE << std::endl;
    const WrongAnimal* meta1 = new WrongAnimal();
    std::cout <<std::endl;
    const WrongAnimal* cat1 = new WrongCat();
    std::cout << FPURPLE << "------------------Wrong cat says smth------------------" << NONE << std::endl;
    cat1->makeSound();
    std::cout << FPURPLE << "------------------Wrong animal says smth------------------" << NONE << std::endl;
    meta1->makeSound();

    std::cout << FGREEN << "------------------Destructors------------------" << NONE << std::endl;
    delete meta;
    std::cout <<std::endl;
    delete j;
    std::cout <<std::endl;
    delete i;
    std::cout <<std::endl;
    delete meta1;
    std::cout <<std::endl;
    delete cat1;
    
    return 0;
}
