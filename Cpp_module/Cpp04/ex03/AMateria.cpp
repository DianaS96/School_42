#include "AMateria.hpp"

AMateria::AMateria() : type("None") {
    return ;
}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(const AMateria &aMateria) {
    *this = aMateria;
}
AMateria& AMateria::operator=(const AMateria &aMateria) {
    if (this != &aMateria)
        this->type = aMateria.type;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria default destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "I do not know how to use " << target.getName() << std::endl;
}