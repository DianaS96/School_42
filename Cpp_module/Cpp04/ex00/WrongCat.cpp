#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) {
    std::cout << "Copy constructor called" << std::endl;
   *this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "Default WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << this->getType() << " tells " << "I ama a wrong cat" << std::endl;
}