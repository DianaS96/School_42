#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
   return ;
}

Cure::Cure(const Cure &cure) : AMateria(cure) {
    *this = cure;
}
Cure& Cure::operator=(const Cure &cure) {
    if (this != &cure)
        this->type = cure.type;
    return (*this);
}

Cure::~Cure() {
    std::cout << "Cure default destructor called" << std::endl;
}


void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s  wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}