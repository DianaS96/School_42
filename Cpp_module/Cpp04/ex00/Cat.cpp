#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name) {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Default Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->getType() << " tells " << "meooooow" << std::endl;
}