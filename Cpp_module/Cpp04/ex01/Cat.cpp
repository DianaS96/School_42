#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal("Cat"), brain(new Brain(*(other.brain))) {
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    brain = new Brain();
    *brain = *other.brain;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Default Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << this->getType() << " tells " << "meooooow" << std::endl;
}

void Cat::printIdea(unsigned int i)
{
    if (i >= 100)
    {
        std::cout << "I am cat. I have no idea with number " << i << std::endl;
        return ;
    }
    std::cout << FGREEN << "I am cat. I have ide #" << i << ": " << brain->getIdea(i) << NONE << std::endl;
}