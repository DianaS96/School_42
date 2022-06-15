#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : name ("WrongAnimal") {
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : name(name) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
    std::cout << "Copy constructor called" << std::endl;
   *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << this->getType() << " tells " << "I am a wrong animal" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (name);
}
