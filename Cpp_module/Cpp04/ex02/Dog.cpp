#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    brain = new Brain();
    *brain = *other.brain;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    {
        this->type = other.type;
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Default Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << this->getType() << " tells " << "wof-wof" << std::endl;
}

void Dog::printIdea(unsigned int i)
{
    if (i >= 100)
    {
        std::cout << FYELLOW << "I am dog. I have no idea with number " << i << NONE << std::endl;
        return ;
    }
    std::cout << FGREEN << "I am dog. I have ide #" << i << ": " << brain->getIdea(i) << NONE << std::endl;
}