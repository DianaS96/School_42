#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name) {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Default Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->getType() << " tells " << "wof-wof" << std::endl;
}