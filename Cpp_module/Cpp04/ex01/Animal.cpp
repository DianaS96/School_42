#include "Animal.hpp"

Animal::Animal() : type ("Animal") {
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &other) {
    std::cout << "Animal Copy constructor called" << std::endl;
    this->type = other.getType();
}

Animal &Animal::operator=(Animal const &other) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Default Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << this->getType() << " tells " << "nothing" << std::endl;
}

std::string Animal::getType() const {
    return (type);
}
