#include "Fixed.hpp"

Fixed::Fixed() : integer(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int a) {
    std::cout << "Int constructor called" << std::endl;
    this->integer = a * 256;
}

Fixed::Fixed(const float a) {
    std::cout << "Float constructor called" << std::endl;
    this->integer = roundf(a * 256);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
    return ;
}

Fixed &Fixed::operator=(Fixed const &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->integer = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    return (this->integer);
}

void    Fixed::setRawBits(int const raw) {
    this->integer = raw;
}

int Fixed::toInt(void) const {
    int val = this->integer / 256;
    return (val);
}

float Fixed::toFloat(void) const {
    float val = (float)this->integer / 256;
    return (val);
}

std::ostream &operator<<(std::ostream &object, Fixed const &fixed) {
    object << fixed.toFloat();
    return (object);
}
