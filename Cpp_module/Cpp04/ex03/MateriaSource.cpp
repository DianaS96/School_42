#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & type) {
    *this = type;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &type) {
    if (this != &type)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (type.inventory[i])
                inventory[i] = type.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
std::cout << "MateriaSource default destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria*amateria) {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = amateria;
            return ;
        }
    }
    std::cout << "No space for new materia" << std::endl;
    delete amateria;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
            continue;
        if (inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    std::cout << "No materia with type " << type << std::endl;
    return (NULL);
}
