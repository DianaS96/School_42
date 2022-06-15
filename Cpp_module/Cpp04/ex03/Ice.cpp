#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
   return ;
}

Ice::Ice(const Ice &ice) : AMateria(ice) {
    *this = ice;
}
Ice& Ice::operator=(const Ice &ice) {
    if (this != &ice)
        this->type = ice.type;
	return (*this);
}

Ice::~Ice() {
    std::cout << "Ice default destructor called" << std::endl;
}


void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}